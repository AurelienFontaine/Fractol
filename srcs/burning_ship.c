/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:38:38 by afontain          #+#    #+#             */
/*   Updated: 2023/04/23 18:34:56 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(t_data *data)
{
	double	tmp;
	int		n;
	double	x;
	double	y;
	
	y = 0;
	while(y < WINDOW_HEIGHT)
	{	
		y++;
		x = 0;
		while(x < WINDOW_WIDTH)
		{
			data->cmplx.ca = (x / (WINDOW_WIDTH / (data->xmax - data->xmin))) + data->xmin;
     		data->cmplx.cb = (y / (WINDOW_HEIGHT / (data->ymax - data->ymin))) + data->ymin;
			data->za = 0;
			data->zb = 0;
			n = 0;
			while (data->za*data->za + data->zb*data->zb < 4 && n < MAX_ITER)
			{
				data->zb = fabs(data->zb);
				tmp = fabs(data->za);
				data->za = data->za*data->za - data->zb*data->zb + data->cmplx.ca;
				data->zb = 2*tmp*data->zb + data->cmplx.cb;
				n++;
			}
			if (n == MAX_ITER)
				img_pxl_put(&data->img, x, y, create_color(0, 0, 0));
			else
				choose_colors1(data, x, y, n);
			x++;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:16:23 by afontain          #+#    #+#             */
/*   Updated: 2023/04/23 18:37:47 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_data *data)
{
	double	tmp;
	int		n;

	data->y = 0;
	while(data->y < WINDOW_HEIGHT)
	{	
		data->y++;
		data->x = 0;
		while(data->x < WINDOW_WIDTH)
		{
			data->ca = (data->x / (WINDOW_WIDTH / (data->xmax - data->xmin))) + data->xmin;
     		data->cb = (data->y / (WINDOW_HEIGHT / (data->ymax - data->ymin))) + data->ymin;
			data->za = 0;
			data->zb = 0;
			n = 0;
			while (data->za*data->za + data->zb*data->zb < 4 && n < MAX_ITER)
			{
				tmp = data->za;
				data->za = data->za*data->za - data->zb*data->zb + data->ca;
				data->zb = 2*tmp*data->zb + data->cb;
				n++;
			}
			if (n == MAX_ITER)
				img_pxl_put(&data->img, data->x, data->y, create_color(0, 0, 0));
			else
				choose_colors2(data, data->x, data->y, n);
			data->x++;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

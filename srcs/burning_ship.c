/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:38:38 by afontain          #+#    #+#             */
/*   Updated: 2023/04/28 13:39:06 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	algo_b(t_data *data, int x, int y)
{
	double	x2;
	double	y2;
	int		n;

	data->ca = (x * ((data->xmax - data->xmin) / WINDOW_WIDTH)) + data->xmin;
	data->cb = (y * ((data->ymax - data->ymin) / WINDOW_HEIGHT)) + data->ymin;
	data->za = 0;
	data->zb = 0;
	x2 = 0;
	y2 = 0;
	n = 0;
	while (x2 + y2 < 4 && n < MAX_ITER)
	{
		x2 = data->za * data->za;
		y2 = data->zb * data->zb;
		data->zb = fabs(data->za * data->zb + data->za * data->zb + data->cb);
		data->za = fabs(x2 - y2 + data->ca);
		n++;
	}
	return (n);
}

int	burning_ship(t_data *data)
{
	int		n;
	double	x;
	double	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		y++;
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			n = algo_b(data, x, y);
			if (n == MAX_ITER)
				img_pxl_put(&data->img, x, y, create_color(0, 0, 0));
			else
				choose_colors1(data, x, y, n);
			x++;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	return (0);
}

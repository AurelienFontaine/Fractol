/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:16:23 by afontain          #+#    #+#             */
/*   Updated: 2023/04/25 14:29:20 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	algo_m(t_data *data, int x, int y)
{
	double	x2;
	double	y2;
	int		n;

	data->ca = (x / (WINDOW_WIDTH / (data->xmax - data->xmin))) + data->xmin;
	data->cb = (y / (WINDOW_HEIGHT / (data->ymax - data->ymin))) + data->ymin;
	data->za = 0;
	data->zb = 0;
	x2 = 0;
	y2 = 0;
	n = 0;
	while (x2 + y2 < 4 && n < MAX_ITER)
	{
		x2 = data->za * data->za;
		y2 = data->zb * data->zb;
		data->zb = 2 * data->za * data->zb + data->cb;
		data->za = x2 - y2 + data->ca;
		n++;
	}
	return (n);
}

int	mandelbrot(t_data *data)
{
	int	x;
	int	y;
	int	n;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{	
		y++;
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			n = algo_m(data, x, y);
			if (n == MAX_ITER)
				img_pxl_put(&data->img, x, y, create_color(0, 0, 0));
			else
				choose_colors2(data, x, y, n);
			x++;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

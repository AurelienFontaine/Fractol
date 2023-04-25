/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:31:23 by afontain          #+#    #+#             */
/*   Updated: 2023/04/25 15:19:35 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	algo_j(t_data *data, int x, int y)
{
	double	y2;
	double	x2;
	int		n;

	data->ca = (x / (WINDOW_WIDTH / (data->xmax - data->xmin))) + data->xmin;
	data->cb = (y / (WINDOW_HEIGHT / (data->ymax - data->ymin))) + data->ymin;
	n = 0;
	y2 = 0;
	x2 = 0;
	while (y2 + x2 <= 4 && n < MAX_ITER)
	{
		x2 = data->ca * data->ca;
		y2 = data->cb * data->cb;
		data->cb = 2 * data->ca * data->cb + 0.1889;
		data->ca = x2 - y2 - 0.7269;
		n++;
	}
	return (n);
}
//+ vr;
//+ vc;

int	julia(t_data *data)
{
	int	n;
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		y++;
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			n = algo_j(data, x, y);
			if (n == MAX_ITER)
				img_pxl_put(&data->img, x, y, create_color(0, 0, 0));
			else
				choose_colors(data, x, y, n);
			x++;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

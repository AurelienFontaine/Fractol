/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:38:38 by afontain          #+#    #+#             */
/*   Updated: 2023/04/21 11:40:40 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(t_data *data)
{
	double	tmp;
	// double	za;
	// double	zb;
	int		n;
	// double	ca;
	// double 	cb;
	double x;
	double y;
	// double z;
	
	y = 0;
	while(y < WINDOW_HEIGHT)
	{	
		y++;
		x = 0;
		while(x < WINDOW_WIDTH)
		{
			data->cmplx.ca = (x / (WINDOW_WIDTH / (data->xmax - data->xmin))) + data->xmin;
     		data->cmplx.cb = (y / (WINDOW_HEIGHT / (data->ymax - data->ymin))) + data->ymin;
			data->complex.za = 0;
			data->complex.zb = 0;
			n = 0;
			while (data->complex.za*data->complex.za + data->complex.zb*data->complex.zb < 4 && n < MAX_ITER)
			{
				data->complex.zb = fabs(data->complex.zb);
				tmp = fabs(data->complex.za);
				data->complex.za = data->complex.za*data->complex.za - data->complex.zb*data->complex.zb + data->cmplx.ca;
				data->complex.zb = 2*tmp*data->complex.zb + data->cmplx.cb;
				n++;
			}
			// z = n + 1 - log(log2(sqrt(za*za + zb*zb))) / log(2);
			if (n == MAX_ITER)
				img_pxl_put(&data->img, x, y, create_color(0, 0, 0));
			else	
				// img_pxl_put(&data->img, x, y, create_color(z, z, z));
				choose_colors1(data, data->complex.za, data->complex.zb, x, y, n);
			x++;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 14:38:38 by afontain          #+#    #+#             */
/*   Updated: 2023/04/10 18:41:07 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burning_ship(t_data *data)
{
	double	tmp;
	double	za;
	double	zb;
	int		n;
	double	ca;
	double 	cb;
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
			ca = (x / (WINDOW_WIDTH / (xb2 - xb1))) + xb1;
     		cb = (y / (WINDOW_HEIGHT / (yb2 - yb1))) + yb1;
			za = 0;
			zb = 0;
			n = 0;
			while (za*za + zb*zb < 4 && n < MAX_ITER)
			{
				zb = fabs(zb);
				tmp = fabs(za);
				za = za*za - zb*zb + ca;
				zb = 2*tmp*zb + cb;
				n++;
			}
			// z = n + 1 - log(log2(sqrt(za*za + zb*zb))) / log(2);
			if (n == MAX_ITER)
				img_pxl_put(&data->img, x, y, create_color(0, 0, 0));
			else	
				// img_pxl_put(&data->img, x, y, create_color(z, z, z));
				choose_colors1(data, za, zb, x, y, n);
			x++;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

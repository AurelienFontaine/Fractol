/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:16:23 by afontain          #+#    #+#             */
/*   Updated: 2023/04/10 18:09:08 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_data *data)
{
	double	tmp;
	double	za;
	double	zb;
	int		n;
	double	ca;
	double 	cb;
	double x;
	double y;

	y = 0;
	while(y < WINDOW_HEIGHT)
	{	
		y++;
		x = 0;
		while(x < WINDOW_WIDTH)
		{
			ca = (x / (WINDOW_WIDTH / (xm2 - xm1))) + xm1;
     		cb = (y / (WINDOW_HEIGHT / (ym2 - ym1))) + ym1;
			za = 0;
			zb = 0;
			n = 0;
			while (za*za + zb*zb < 4 && n < MAX_ITER)
			{
				tmp = za;
				za = za*za - zb*zb + ca;
				zb = 2*tmp*zb + cb;
				n++;
			}
			if (n == MAX_ITER)
				img_pxl_put(&data->img, x, y, create_color(0, 0, 0));
			else	
				// img_pxl_put(&data->img, x, y, create_color((255*n)/ MAX_ITER, 0, 0));
				choose_colors1(data, za, zb, x, y, n);
			x++;
		}
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

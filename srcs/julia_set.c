/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:16:23 by afontain          #+#    #+#             */
/*   Updated: 2023/03/28 17:42:17 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(int x, int y, t_data	*data, t_img *img)
{
	double		tmp;
	double		za;
	double		zb;
	int			n;

	n = 0;
	while(x < WINDOW_WIDTH)
	{
		x++;
		while(y < WINDOW_HEIGHT)
		{
			za = x / (WINDOW_WIDTH / (x2 - x1)) + x1;
     		zb = y / (WINDOW_HEIGHT / (y2 - y1)) + y1;
			y++;
		}
	}
	while (za * za + zb * zb < 4 && n < MAX_ITER)
	{
		tmp = za;
		za = za * za - zb *zb + data->ca;
 		zb = 2 * tmp *zb + data->cb;
		n++;
	}
	if (n == MAX_ITER)
		img_pix_put(img, x, y, create_color(0, 0, 0));
	else	
		img_pix_put(img, x, y, create_color(0, 0, (n * 255) / 50));
}

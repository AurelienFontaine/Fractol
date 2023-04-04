/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:20:50 by afontain          #+#    #+#             */
/*   Updated: 2023/03/28 17:37:52 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img,j++, i, rect.color);
		++i;
	}
	return (0);
}

int	render(t_data *data)
{
	int	x;
	int	y;
	int i;

	y = 0;
	if(!data->win_ptr)
		return (1);
	// render_background(&data->img, WHITE_PIXEL);
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		i = 0;
		while (x < WINDOW_WIDTH)
		{
			// if (x % 2 == 0) 
			render_rect(&data->img, (t_rect){x, y, 1, 1, i});
			i += 13980;
				// render_rect(&data->img, (t_rect){ x, y, 1, 1, 200});
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

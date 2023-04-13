/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:29:27 by afontain          #+#    #+#             */
/*   Updated: 2023/04/13 17:37:05 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_mouse(t_data *data, int x, int y)
{
	int mouse_x;
	int mouse_y;
	int tmp_y;

	mouse_x = x + 10;
	mouse_y = y + 3;
	tmp_y = y;
	while (x < mouse_x)
	{
		y = tmp_y;
		while (y < mouse_y)
		{
			img_pxl_put(&data->img, x, y, create_color(220, 220, 220));
			y++;
		}
		x++;
	}
}



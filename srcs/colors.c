/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:40:07 by afontain          #+#    #+#             */
/*   Updated: 2023/03/28 16:44:13 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_color(int R, int G, int B)
{
	return(256*256*R + 256*G + B);
}

int	choose_color(int x, int y, t_data *data, int n)
{
	if (data->color == 0)
		return (img_m(x, y, data, create_color(255, 255, 255)));
	else if (data->color == 1)
		return (img_m(x, y, data, create_color(0, 0, 0)));
	// else if (data->color == 2)
	// 	return (img_m(x, y, data, create_color(0, 0, 0)));
	// else if (data->color == 3)
	// 	return (img_m(x, y, data, create_color(0, 0, 0)));
	// else if (data->color == 4)
	// 	return (img_m(x, y, data, create_color(0, 0, 0)));
	// else if (data->color == 5)
	// 	return (img_m(x, y, data, create_color(0, 0, 0)));
	// else if (data->color == 6)
	// 	return (img_m(x, y, data, create_color(0, 0, 0)));
	// else if (data->color == 7)
	// 	return (img_m(x, y, data, create_color(0, 0, 0)));
	// else if (data->color == 8)
	// 	return (img_m(x, y, data, create_color(0, 0, 0)));
	// else if (data->color == 9)
	// 	return (img_m(x, y, data, create_color(0, 0, 0)));
}

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
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, ft_rgb(220, 220, 220));
			y++;
		}
		x++;
	}
}

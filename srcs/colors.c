/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:40:07 by afontain          #+#    #+#             */
/*   Updated: 2023/04/04 18:50:01 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_color(int R, int G, int B)
{
	return(256*256*R + 256*G + B);
}

void	choose_color(int x, int y, t_data *data, int n)
{
	if (((n % 10) % 10) == 0)
		return (img_pxl_put(&data->img, x, y, create_color(255, 255, 255)));
	else if ((n % 10) == 1)
		return (img_pxl_put(&data->img, x, y, create_color(225, 225, 225)));
	else if ((n % 10) == 2)
		return (img_pxl_put(&data->img, x, y, create_color(200, 200, 200)));
	else if ((n % 10) == 3)
		return (img_pxl_put(&data->img, x, y, create_color(175, 175, 175)));
	else if ((n % 10) == 4)
		return (img_pxl_put(&data->img, x, y, create_color(150, 150, 150)));
	else if ((n % 10) == 5)
		return (img_pxl_put(&data->img, x, y, create_color(120, 120, 120)));
	else if ((n % 10) == 6)
		return (img_pxl_put(&data->img, x, y, create_color(100, 100, 100)));
	else if ((n % 10) == 7)
		return (img_pxl_put(&data->img, x, y, create_color(75, 75, 75)));
	else if ((n % 10) == 8)
		return (img_pxl_put(&data->img, x, y, create_color(50, 50, 50)));
	else if ((n % 10) == 9)
		return (img_pxl_put(&data->img, x, y, create_color(0, 0, 0)));
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
			img_pxl_put(&data->img, x, y, create_color(220, 220, 220));
			y++;
		}
		x++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:59:10 by afontain          #+#    #+#             */
/*   Updated: 2023/04/10 18:12:19 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
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

void	choose_function()
{
	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:59:38 by afontain          #+#    #+#             */
/*   Updated: 2023/04/29 17:46:17 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_coord(t_data *data, double len_x, double len_y, double zoom)
{
	data->xmax = data->tmp_x + (len_x) * zoom;
	data->ymax = data->tmp_y + (len_y) * zoom;
	data->xmin = data->tmp_x - (len_x) * zoom;
	data->ymin = data->tmp_y - (len_y) * zoom;
}

void	zoom(t_data *data, double zoom)
{
	double	len_x;
	double	len_y;

	data->tmp_x = (data->mouse_x
			/ (WINDOW_WIDTH / (data->xmax - data->xmin))) + data->xmin;
	data->tmp_y = (data->mouse_y
			/ (WINDOW_HEIGHT / (data->ymax - data->ymin))) + data->ymin;
	len_x = (data->xmax - data->xmin) * zoom;
	len_y = (data->ymax - data->ymin) * zoom;
	check_coord(data, len_x, len_y, zoom);
	data->count_zoom++;
}

int	key_event(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		close_it(data);
		return (0);
	}
	else if (keysym == XK_Left)
		move(data, 0.2, 'L');
	else if (keysym == XK_Up)
		move(data, 0.2, 'U');
	else if (keysym == XK_Right)
		move(data, 0.2, 'R');
	else if (keysym == XK_Down)
		move(data, 0.2, 'D');
	choose_fractal(data);
	return (0);
}

int	mouse_event(int keysym, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keysym == MOUSE_BTN_4)
		zoom(data, 0.5);
	else if (keysym == MOUSE_BTN_5)
	{
		zoom(data, 1.1);
		if (data->count_zoom == 1)
			data->count_zoom -= 1;
		else if (data->count_zoom > 1)
			data->count_zoom -= 2;
	}
	else
		return (0);
	choose_fractal(data);
	return (0);
}

int	mouse_pos(int x, int y, t_data *data)
{
	data->mouse_x = x;
	data->mouse_y = y;
	return (0);
}

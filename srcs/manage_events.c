/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:59:38 by afontain          #+#    #+#             */
/*   Updated: 2023/04/23 17:38:37 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_data *data, double move, char direction)
{
		// double	mil_r;
		// double	mil_c;
		// mil_r = data->xmax - data->xmin;
		// mil_c = data->ymax - data->ymin;
		if (direction == 'U')
		{
			data->ymax += data->ymax * move;
			data->ymin += data->ymin * move;
		}
		else if (direction == 'D')
		{
			data->ymax -= data->ymax * move;
			data->ymin -= data->ymin * move;
		}
		else if (direction == 'L')
		{
			data->xmax -= data->xmax * move;
			data->xmin -= data->xmin * move;
		}
		else if (direction == 'R')
		{
			data->xmax += data->xmax * move;
			data->xmin += data->xmin * move;
		}
}

void	zoom(t_data *data, double zoom)
{
	double len_x;
	double len_y;
	
	data->tmp_x = (data->mouse_x / (WINDOW_WIDTH / (data->xmax - data->xmin))) + data->xmin;
    data->tmp_y = (data->mouse_y / (WINDOW_HEIGHT / (data->ymax - data->ymin))) + data->ymin;
	// printf("NEW Mouse X %f\n", data->tmp_x);
	// printf("NEW Mouse Y %f\n\n", data->tmp_y);
	len_x = (data->xmax - data->xmin)*zoom;
	len_y = (data->ymax - data->ymin)*zoom;
	// printf("len X %f\n", len_x);
	// printf("len  Y %f\n\n", len_y);
		if (data->xmax > 1.5)
			data->xmax = 1.5;
		else
			data->xmax = data->tmp_x + (len_x)*zoom;
		if (data->ymax > 1.5)
			data->ymax = 1.5;
		else
			data->ymax = data->tmp_y + (len_y)*zoom;
		if (data->xmin < -1.5)
			data->xmin = -1.5;
		else
			data->xmin = data->tmp_x -(len_x)*zoom;
		if (data->ymin < -1.5)
			data->ymin = -1.5;
		else
			data->ymin = data->tmp_y - (len_y)*zoom;
		data->count_zoom++;
	// printf("ZOOM COMPTEUR%f\n\n", data->count_zoom);
	// printf("XMAX %f\n", data->xmax);
	// printf("XMIN %f\n", data->xmin);
	// printf("YMAX %f\n", data->ymax);
	// printf("YMIN %f\n\n", data->ymin);
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
	return(0);
}

int mouse_event(int keysym, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (keysym == MOUSE_BTN_4)
		zoom(data, 0.5);
	else if (keysym == MOUSE_BTN_5)
		zoom(data, 1.1);
	else
		return (0);
	choose_fractal(data);
	return (0);
}

int	mouse_pos(int x, int y, t_data *data)
{
	data->mouse_x = x;
	data->mouse_y = y;
	// printf("MOUSE X %f\n", data->mouse_x);
	// printf("MOUSE Y %f\n\n", data->mouse_y);
	return (0);
}

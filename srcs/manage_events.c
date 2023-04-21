/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:59:38 by afontain          #+#    #+#             */
/*   Updated: 2023/04/18 13:45:54 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_data *data, double move, char direction)
{
		double	mil_r;
		double	mil_c;

		mil_r = data->xmax - data->xmin;
		mil_c = data->ymax - data->ymin;
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
	double	mil_r;
	double	mil_c;
	
	mil_r = data->xmin - data->xmax;
	mil_c = data->ymax - data->ymin;
	data->xmax = data->xmax + (mil_r - zoom * mil_r) / 2;
	data->xmin = data->xmax + zoom * mil_r;
	data->ymin = data->ymin + (mil_c - zoom * mil_c) / 2;
	data->ymax = data->ymin + zoom * mil_c;
	data->count_zoom++;
	printf("%f\n", data->count_zoom);
	printf("%f\n", data->xmax);
	printf("%f\n", data->xmin);
	printf("%f\n", data->ymax);
	printf("%f\n", data->xmin);
}

int	key_event(int keysym, t_data *data)
{
	// printf("data %p\n", data);
	if (keysym == XK_Escape)
	{
		close_it(data);	
		return (0);
	}
	// if (keysym == XK_Pointer_Button4)
	// 	zoom(data, 0.5);
	// else if (keysym == XK_Pointer_Button5)
	// 	zoom(data, 0.5);
	else if (keysym == XK_Left)
		move(data, 0.2, 'L');
	else if (keysym == XK_Up)
		move(data, 0.2, 'U');                        
	else if (keysym == XK_Right)
		move(data, 0.2, 'R');
	else if (keysym == XK_Down)
		move(data, 0.2, 'D');
	choose_fractal(data);
	// printf("data %p\n", data);
	return(0);
}

// int x, int y

int mouse_event(int keysym, int x, int y, t_data *data)
{
	if (keysym == MOUSE_BTN_4)
	{
		zoom(data, 0.5);
		x -= WINDOW_WIDTH / 2;
		y -= WINDOW_HEIGHT / 2;
		if (x < 0)
			move(data, (double)x * -1 / WINDOW_WIDTH, 'L');
		else if (x > 0)
			move(data, (double)x / WINDOW_WIDTH, 'R');
		if (y < 0)
			move(data, (double)y * -1 / WINDOW_HEIGHT, 'U');
		else if (y > 0)
			move(data, (double)y / WINDOW_HEIGHT, 'D');
	}
	else if (keysym == MOUSE_BTN_5)
		zoom(data, 2);
	else
		return (0);
	choose_fractal(data);
	return (0);
}

// int	mouse_move(t_data *data, int keysym)
// {
	
// }

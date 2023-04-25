/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:29:27 by afontain          #+#    #+#             */
/*   Updated: 2023/04/25 15:26:52 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_data *data, double move, char direction)
{
	if (direction == 'U')
	{
		data->ymax = data->ymax - (move / (data->count_zoom + 1));
		data->ymin = data->ymin - (move / (data->count_zoom + 1));
	}
	else if (direction == 'D')
	{
		data->ymax = data->ymax + (move / (data->count_zoom + 1));
		data->ymin = data->ymin + (move / (data->count_zoom + 1));
	}
	else if (direction == 'L')
	{
		data->xmax = data->xmax - (move / (data->count_zoom + 1));
		data->xmin = data->xmin - (move / (data->count_zoom + 1));
	}
	else if (direction == 'R')
	{
		data->xmax = data->xmax + (move / (data->count_zoom + 1));
		data->xmin = data->xmin + (move / (data->count_zoom + 1));
	}
}

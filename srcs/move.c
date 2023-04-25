/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:29:27 by afontain          #+#    #+#             */
/*   Updated: 2023/04/25 17:56:46 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move(t_data *data, double move, char direction)
{
	if (direction == 'U')
	{
		data->ymax = data->ymax - (move / (pow(2.0, (double)data->count_zoom)));
		data->ymin = data->ymin - (move / (pow(2.0, (double)data->count_zoom)));
	}
	else if (direction == 'D')
	{
		data->ymax = data->ymax + (move / (pow(2.0, (double)data->count_zoom)));
		data->ymin = data->ymin + (move / (pow(2.0, (double)data->count_zoom)));
	}
	else if (direction == 'L')
	{
		data->xmax = data->xmax - (move / (pow(2.0, (double)data->count_zoom)));
		data->xmin = data->xmin - (move / (pow(2.0, (double)data->count_zoom)));
	}
	else if (direction == 'R')
	{
		data->xmax = data->xmax + (move / (pow(2.0, (double)data->count_zoom)));
		data->xmin = data->xmin + (move / (pow(2.0, (double)data->count_zoom)));
	}
}
//  c_z = 0 d = 3 m = 0.2
//  c_z = 1 d = 1.5  m = 0.1
//  c_z = 2 d = 0.75 m = 0.05
//  c_z = 3 d = 0.375 m = 0.025
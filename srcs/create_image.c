/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:15:47 by afontain          #+#    #+#             */
/*   Updated: 2023/04/25 14:16:49 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->set = -1;
	data->ca = 0;
	data->cb = 0;
	data->cs = 0;
	data->za = 0;
	data->zb = 0;
	data->vr = 0;
	data->vc = 0;
	data->count_zoom = 0;
	data->tmp_x = 0;
	data->tmp_y = 0;
	data->xmax = 0;
	data->xmin = 0;
	data->ymax = 0;
	data->ymin = 0;
	data->mouse_x = 0;
	data->mouse_y = 0;
}

int	init_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (MLX_ERROR);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Fractol");
	if (!data->win_ptr)
	{
		free(data->win_ptr);
		return (MLX_ERROR);
	}
	data->img.mlx_img
		= mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	return (0);
}

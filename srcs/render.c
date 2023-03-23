/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:20:50 by afontain          #+#    #+#             */
/*   Updated: 2023/03/23 15:20:16 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render_background(t_img *img, int color)
{
	// Met le fond de la fenetre d'une couleur
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img,j++, i, rect.color);
		++i;
	}
	return (0);
}

int	render(t_data *data)
{
	/* if window has been destroyed, we don't want to put the pixel ! */
	if(data->win_ptr == NULL)
		return (1);
	render_background(&data->img, WHITE_PIXEL);
	
	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});

	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
			100, 100, GREEN_PIXEL});
			
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

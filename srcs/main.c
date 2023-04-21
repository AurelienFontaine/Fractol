/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:08:56 by afontain          #+#    #+#             */
/*   Updated: 2023/04/21 14:30:51 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pxl_put(t_img *img, int x, int y, int color)
{
	char    *pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	// printf("data %p\n", data);

	if (ac < 2)
		return (write(1, "Choisir: Mandelbrot, Julia ou Burning_ship\n", 45), 1);
	init_data(&data);
	if (check_args(&data, ac, av) == 0)
	{
		init_window(&data);

	// printf("data %p\n", data);
	
	// /* Setup hooks */ 
	// check_args(data, ac, av);
	// choose_fractal(data, ac, av)
	// mlx_loop_hook(data.mlx_ptr, &choose_fractal, data);
		choose_fractal(&data);
	// Suppr la fenetre avec ESC et le X de la fenetre
	// mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	
	 	mlx_hook(data.win_ptr, MotionNotify, PointerMotionMask, &mouse_pos, &data);
		mlx_hook(data.win_ptr, EVENT_CLOSE_BTN, 0, close_it, &data);
		mlx_key_hook(data.win_ptr, key_event, &data);
		mlx_mouse_hook(data.win_ptr, mouse_event, &data);
	
	// mlx_hook(data->win_ptr, ClientMessage, KeyPressMask, &key_event, &data);
	// mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask, &mouse_event, &data);
		mlx_loop(data.mlx_ptr);
	}
	/*Execute qd il y'a plus de fenetres */
	// mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	// mlx_destroy_display(data->mlx_ptr);
	// free(data->mlx_ptr);
	// }
}

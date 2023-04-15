/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:08:56 by afontain          #+#    #+#             */
/*   Updated: 2023/04/13 18:23:22 by afontain         ###   ########.fr       */
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

int	main(void)
{
	t_data	data;

	// if (ac < 2)
		// write(1, "Pas de Fractales choisies\n", 26);
	// init_window(&data);
	// init(data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
								"Fractol");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	
	// /* Setup hooks */ 
	// check_args(&data, ac, av);
	// choose_fract(&data, ac, av);
	// mlx_loop_hook(data.mlx_ptr, &julia, &data);
	// choose_fractal(ac, av, &data);
	
	// Suppr la fenetre avec ESC et le X de la fenetre
	// mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, EVENT_CLOSE_BTN, 0, close_it, &data);
	mlx_key_hook(data.win_ptr, key_event, &data);
	mlx_mouse_hook(data.win_ptr, mouse_event, &data);
	
	mlx_hook(data.win_ptr, ClientMessage, KeyPressMask, &key_event, &data);
	// mlx_hook(data.win_ptr, MotionNotify, PointerMotionMask, &mouse_event, &data);

	mlx_loop(data.mlx_ptr);

	/*Execute qd il y'a plus de fenetres */
	// mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	// mlx_destroy_display(data.mlx_ptr);
	// free(data.mlx_ptr);
	// }
}

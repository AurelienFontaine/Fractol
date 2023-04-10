/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:03:08 by afontain          #+#    #+#             */
/*   Updated: 2023/04/10 18:28:37 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	choose_fractal(int ac, char **av, t_data *data)
// {
// 	if (ac == 1)
// 		return (write(1, "Pas de Fractales choisies\n", 26), 0);
// 	else if (ac == 3)
// 		return (write(1, "Mauvais choix de caracteres\n", 28), 0);
// 	else if (ac > 4)
// 		return (write(1, "Trop de parametres saisis\n", 26), 0);
// 	if (ac == 2)
// 	{
// 		if (ft_strcmp(av[1], "Mandelbrot") || ft_strcmp(av[1], "mandelbrot"))
// 			return (mlx_loop_hook(data->mlx_ptr, &mandelbrot, &data), 1);
// 		else if (ft_strcmp(av[1], "Burning_ship") || ft_strcmp(av[1], "burning_ship"))
// 			return (mlx_loop_hook(data->mlx_ptr, &burning_ship, &data), 1);
// 	}
// 	else if (ac == 4 && (ft_strcmp(av[1],"Julia") || ft_strcmp(av[1], "julia")))
// 		return (mlx_loop_hook(data->mlx_ptr, &julia, &data), 1);
// }

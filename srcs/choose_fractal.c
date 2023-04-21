/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:03:08 by afontain          #+#    #+#             */
/*   Updated: 2023/04/21 11:51:54 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int choose_fractal(t_data *data)
{
	// mlx_clear_window(data->mlx_ptr, data->win_ptr);
	printf("CECI EST UN TEST\n");
	printf("%p\n", data);
	if (data->set == MANDELBROT)
		return (mandelbrot(data));
	else if (data->set == JULIA)
		return (julia(data));
	else if (data->set == BURNING_SHIP)
		return (burning_ship(data));
	return (0);
}

void set_coord(t_data *data)
{
	if (data->set == MANDELBROT)
	{
		data->xmax = 0.6;
		data->xmin = -2;
		data->ymax = 1.2;
		data->ymin = -1.2;
	}
	else if (data->set == JULIA)
	{
		data->xmax = 1.5;
		data->xmin = -1.5;
		data->ymax = 1.5;
		data->ymin = -1.5;
	}
	else if (data->set == BURNING_SHIP)
	{
		data->xmax = 0.6;
		data->xmin = -2;
		data->ymax = 1.2;
		data->ymin = -1.2;
	}
}

void get_fractal(t_data *data, char **av)
{
	if (ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], "julia") == 0)
			data->set = JULIA;
	else if (ft_strcmp(av[1], "Mandelbrot") == 0
		|| ft_strcmp(av[1], "mandelbrot") == 0)
			data->set = MANDELBROT;
	else if (ft_strcmp(av[1], "Burning_ship") == 0
		|| ft_strcmp(av[1], "burning_ship") == 0)
			data->set = BURNING_SHIP;
	else 
		write(1, "Erreur, choisir entre : Julia, Mandelbrot, Burning_ship\n", 56);
}

void	check_args(t_data *data, int ac, char **av)
{
	get_fractal(data, av);
	set_coord(data);
	if ((data->set != JULIA && ac > 3) || (data->set == JULIA && ac > 5))
			write(1, "Trop de parametres saisis\n", 26);
	if (data->set != JULIA)
	{
		if (ft_atof(av[2]) <= 1 && ft_atof(av[2]) >= 0)
			data->cs = ft_atof(av[2]);
		else 
			write(1, "Invalide CS choisir entre 0 et 1\n", 33);
	}
	if (data->set == JULIA)
	{
		if (ft_atof(av[2]) <= 1 && ft_atof(av[2]) >= 0)
			data->cs = ft_atof(av[2]);
		else 
			write(1, "Invalide CS choisir entre 0 et 1\n", 33);
		data->vr = ft_atof(av[2]);
		data->vc = ft_atof(av[3]);
		if(data->vr > 2.0 || data->vr < -2.0)
			write(1, "Valeur reelle trop grande\n", 26);
		if(data->vc > 2.0 || data->vc < -2.0)
			write(1, "Valeur complexe trop grande\n", 28);
	}
}

// int	choose_fractal(int ac, char **av, t_data *data)
// {
// 	if (ac == 1)
// 	{
// 		write(1, "Pas de Fractales choisies\n", 26);
// 		return (1);
// 	}
// 	else if (ac == 3)
// 	{
// 		write(1, "Mauvais choix de caracteres\n", 28);
// 		return (1);
// 	}
// 	else if (ac > 4)
// 	{
// 		write(1, "Trop de parametres saisis\n", 26);
// 		return (1);
// 	}
// 	if (ac == 2)
// 	{
// 		if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "mandelbrot") == 0)
// 		{
// 			printf("%i\n", ft_strcmp(av[1], "Mandelbrot"));
// 			return (&mandelbrot);
// 		}
// 		else if (ft_strcmp(av[1], "Burning_ship") == 0 || ft_strcmp(av[1], "burning_ship") == 0)
// 			return (burning_ship(data));
// 		else 
// 			write(1, "Mauvais choix de Fractale\n", 28);
// 	}
// 	else if (ac == 4 && (ft_strcmp(av[1],"Julia") == 0 || ft_strcmp(av[1], "julia") == 0))
// 	{
// 		printf("yo");
// 		return (julia(data));
// 	}
// 	return (0);
// }

// int	*choose_fractal(int ac, char **av, t_data *data)
// {
// 	if (ac == 1)
// 	{
// 		write(1, "Pas de Fractales choisies\n", 26);
// 		return (1);
// 	}
// 	else if (ac == 3)
// 	{
// 		write(1, "Mauvais choix de caracteres\n", 28);
// 		return (1);
// 	}
// 	else if (ac > 4)
// 	{
// 		write(1, "Trop de parametres saisis\n", 26);
// 		return (1);
// 	}
// 	if (ac == 2)
// 	{
// 		if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "mandelbrot") == 0)
// 		{
// 			printf("%i\n", ft_strcmp(av[1], "Mandelbrot"));
// 			return (mandelbrot(data));
// 		}
// 		else if (ft_strcmp(av[1], "Burning_ship") == 0 || ft_strcmp(av[1], "burning_ship") == 0)
// 			return (burning_ship(data));
// 		else 
// 			write(1, "Mauvais choix de Fractale\n", 28);
// 	}
// 	else if (ac == 4 && (ft_strcmp(av[1],"Julia") == 0 || ft_strcmp(av[1], "julia") == 0))
// 	{
// 		printf("yo");
// 		return (julia(data));
// 	}
// 	return (0);
// }

// int	choose_fractal(int ac, char **av, t_data *data)
// {
// 	if (ac == 1)
// 	{
// 		write(1, "Pas de Fractales choisies\n", 26);
// 		return (1);
// 	}
// 	else if (ac == 3)
// 	{
// 		write(1, "Mauvais choix de caracteres\n", 28);
// 		return (1);
// 	}
// 	else if (ac > 4)
// 	{
// 		write(1, "Trop de parametres saisis\n", 26);
// 		return (1);
// 	}
// 	if (ac == 2)
// 	{
// 		if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "mandelbrot") == 0)
// 		{
// 			printf("%i\n", ft_strcmp(av[1], "Mandelbrot"));
// 			return (mlx_loop_hook(data->mlx_ptr, &mandelbrot, &data), 0);
// 		}
// 		else if (ft_strcmp(av[1], "Burning_ship") == 0 || ft_strcmp(av[1], "burning_ship") == 0)
// 			return (mlx_loop_hook(data->mlx_ptr, &burning_ship, &data), 0);
// 	}
// 	else if (ac == 2 && (ft_strcmp(av[1],"Julia") == 0 || ft_strcmp(av[1], "julia") == 0))
// 	{
// 		printf("yo");
// 		return (mlx_loop_hook(data->mlx_ptr, &julia, &data), 0);
// 	}
// 	return (0);
// }
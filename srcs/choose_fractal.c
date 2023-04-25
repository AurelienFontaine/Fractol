/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:03:08 by afontain          #+#    #+#             */
/*   Updated: 2023/04/25 17:31:26 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_julia(t_data *data, int ac, char **av)
{
	if (data->set == JULIA && (ac != 5))
		return (write(STDERR_FILENO, "Il faut 3 parametres pour Julia\n", 32), 1);
	if (data->set == JULIA && ac == 5)
	{
		data->vr = ft_atof(av[2]);
		data->vc = ft_atof(av[3]);
		if ((data->vr > 2.0 || data->vr < -2.0)
			&& (data->vc > 2.0 || data->vc < -2.0))
			return (write(STDERR_FILENO, "Erreur, Choisir VR et VC entre -2 et 2\n", 38), 1);
		if (data->vr > 2.0 || data->vr < -2.0)
			return (write(STDERR_FILENO, "VR trop grande\nChoisir entre -2 et 2\n", 37), 1);
		if (data->vc > 2.0 || data->vc < -2.0)
			return (write(STDERR_FILENO, "VC trop grande\nChoisir entre -2 et 2\n", 37), 1);
		if (ft_atof(av[4]) <= 1 && ft_atof(av[4]) >= 0)
			data->cs = ft_atof(av[4]);
		else
			return (write(STDERR_FILENO, "Invalide CS choisir entre 0 et 1\n", 33), 1);
	}
	return (0);
}

int	choose_fractal(t_data *data)
{
	if (data->set == MANDELBROT)
		return (mandelbrot(data));
	else if (data->set == JULIA)
		return (julia(data));
	else if (data->set == BURNING_SHIP)
		return (burning_ship(data));
	return (0);
}

void	set_coord(t_data *data)
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

void	get_fractal(t_data *data, int ac, char **av)
{
	if (ac > 1)
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
			write(STDERR_FILENO, "Erreur, choisir: Julia, Mandelbrot ou Burning_ship\n", 51);
	}
}

int	check_args(t_data *data, int ac, char **av)
{
	get_fractal(data, ac, av);
	if (data->set != 1 && data->set != 2 && data->set != 3)
		return (1);
	set_coord(data);
	if (data->set != JULIA && (ac > 3))
		return (write(STDERR_FILENO, "Trop de parametres saisis\n", 26), 1);
	else if (data->set != JULIA && (ac < 3))
		return (write(STDERR_FILENO, "Pas assez de parametres saisis\n", 31), 1);
	if (data->set != JULIA)
	{
		if (ft_atof(av[2]) <= 1 && ft_atof(av[2]) >= 0)
			data->cs = ft_atof(av[2]);
		else
			return (write(STDERR_FILENO, "Invalide CS choisir entre 0 et 1\n", 33), 1);
	}
	return (check_julia(data, ac, av));
}

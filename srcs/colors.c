/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:40:07 by afontain          #+#    #+#             */
/*   Updated: 2023/04/25 17:18:19 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_it(t_data *data, int x, int y, int n)
{
	if (n == MAX_ITER)
		img_pxl_put(&data->img, x, y, create_color(0, 0, 0));
	else
		choose_colors(data, x, y, n);
}

int	create_color(int R, int G, int B)
{
	return (256 * 256 * R + 256 * G + B);
}

void	choose_colors(t_data *data, int x, int y, int n)
{
	int		r;
	int		g;
	int		b;
	double	shift;

	shift = data->cs * fabs((100 - 10 * (double)data->count_zoom) / 100);
	r = (255.0 * (1.0 - cos(n / 256.0 * 2.0 * M_PI)) / 2.0);
	g = (255.0 * (1.0 - cos(n / 256.0
					* shift * 2.0 * M_PI + 2.0 * M_PI / 3.0)) / 2.0);
	b = (255.0 * (1.0 - cos(n / 256.0 * 2.0 * M_PI + 4.0 * M_PI / 3.0)) / 2.0);
	img_pxl_put(&data->img, x, y, create_color(r, g, b));
}

void	choose_colors1(t_data *data, int x, int y, int n)
{
	int		r;
	int		g;
	int		b;
	double	shift;

	shift = data->cs * fabs((100 - 10 * (double)data->count_zoom) / 100);
	r = (255.0 * (1.0 - cos(n / 256.0
					* shift * 2.0 * M_PI + 4.0 * M_PI / 3.0)) / 2.0);
	g = (255.0 * (1.0 - cos(n / 256.0 * 2.0 * M_PI + 1.0 * M_PI / 3.0)) / 2.0);
	b = (255.0 * (1.0 - cos(n / 256.0 * 2.0 * M_PI)) / 2.0);
	img_pxl_put(&data->img, x, y, create_color(r, g, b));
}

void	choose_colors2(t_data *data, int x, int y, int n)
{
	int		r;
	int		g;
	int		b;
	double	shift;

	shift = data->cs * fabs((100 - 10 * (double)data->count_zoom) / 100);
	r = (255.0 * (1.0
				- cos(n / 256.0 * 2.0 * M_PI + 4.0 * M_PI / 3.0)) / 2.0);
	g = (255.0 * (1.0 - cos(n / 256.0 * 2.0 * M_PI + 1.0 * M_PI / 3.0)) / 2.0);
	b = (255.0 * shift);
	img_pxl_put(&data->img, x, y, create_color(r, g, b));
}

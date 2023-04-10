/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:40:07 by afontain          #+#    #+#             */
/*   Updated: 2023/04/10 18:58:04 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_color(int R, int G, int B)
{
	return(256*256*R + 256*G + B);
}

void choose_colors(t_data *data, int x, int y, int n)
{
	int r;
	int g;
	int b;
	int z;
	
	z = n + 1 - log(log2(sqrt(data->ca*data->ca + data->cb*data->cb))) / log(2);
	r = (255.0 * (1.0 - cos(z / 256.0 * 2.0 * M_PI)) / 2.0);
	g = (255.0 * (1.0 - cos(z / 256.0 * 2.0 * M_PI + 2.0 * M_PI / 3.0)) / 2.0);
    b = (255.0 * (1.0 - cos(z / 256.0 * 2.0 * M_PI + 4.0 * M_PI / 3.0)) / 2.0);
	img_pxl_put(&data->img, x, y, create_color(r, g, b));
}

void choose_colors1(t_data *data, double za, double zb, int x, int y, int n)
{
	int r;
	int g;
	int b;
	int z;
	
	z = n + 1 - log(log2(sqrt(za*za + zb*zb))) / log(2);
	r = (255.0 * (1.0 - cos(z / 256.0 * 2.0 * M_PI + 4.0 * M_PI / 3.)) / 2.0);
	g = (255.0 * (1.0 - cos(z / 256.0 * 2.0 * M_PI + 1.0* M_PI / 3.0)) / 2.0);
    b = (255.0 * (1.0 - cos(z / 256.0 * 2.0 * M_PI)) / 2.0);
	img_pxl_put(&data->img, x, y, create_color(r, g, b));
}

// void	choose_color(int x, int y, t_data *data, int z)
// {
// 	if ((n >= 0 && n <= 0.1))
// 		return (img_pxl_put(&data->img, x, y, create_color(()));
// 	else if (n > 0.1 && n <= 0.2) 
// 		return (img_pxl_put(&data->img, x, y, create_color(());
// 	else if (n > 0.2 && n <= 0.3) 
// 		return (img_pxl_put(&data->img, x, y, create_color());
// 	else if (n > 0.3 && n <=  0.4)
// 		return (img_pxl_put(&data->img, x, y, create_color());
// 	else if (n >0.4 && n <= 0.5) 
// 		return (img_pxl_put(&data->img, x, y, create_color();
// 	else if ( n > 0.5 && n <= 0.6)
// 		return (img_pxl_put(&data->img, x, y, create_color(());
// 	else if ( n > 0.6 && n <= 0.7)
// 		return (img_pxl_put(&data->img, x, y, create_color());
// 	else if ( n > 0.7 && n <= 0.8) 
// 		return (img_pxl_put(&data->img, x, y, create_color(());
// 	else if ( n > 0.8 && n <= 0.9) 
// 		return (img_pxl_put(&data->img, x, y, create_color(()));
// 	else if (n > 0.9 && n <= 1)
// 		return (img_pxl_put(&data->img, x, y, create_color()));
// }

void	normed_choose_color(int x, int y, t_data *data, int n)
{
	if ((n >= 0 && n <= MAX_ITER / 10))
		return (img_pxl_put(&data->img, x, y, create_color(255, 255, 255)));
	else if (n > MAX_ITER / 10 && n <= 2 * MAX_ITER / 10) 
		return (img_pxl_put(&data->img, x, y, create_color(225, 125, 70)));
	else if (n > 2 * MAX_ITER / 10 && n <= 3 * MAX_ITER / 10) 
		return (img_pxl_put(&data->img, x, y, create_color(200, 70, 0)));
	else if (n > 3 * MAX_ITER / 10 && n <= 4 * MAX_ITER / 10)
		return (img_pxl_put(&data->img, x, y, create_color(175, 70, 0)));
	else if (n > 4 * MAX_ITER / 10 && n <= 5 * MAX_ITER / 10) 
		return (img_pxl_put(&data->img, x, y, create_color(150, 70, 0)));
	else if ( n > 5 * MAX_ITER / 10 && n <= 6 * MAX_ITER / 10)
		return (img_pxl_put(&data->img, x, y, create_color(125, 70, 0)));
	else if ( n > 6 * MAX_ITER / 10 && n <= 7 * MAX_ITER / 10)
		return (img_pxl_put(&data->img, x, y, create_color(100, 70, 0)));
	else if ( n > 7 * MAX_ITER / 10 && n <= 8 * MAX_ITER / 10) 
		return (img_pxl_put(&data->img, x, y, create_color(75, 70, 0)));
	else if ( n > 8 * MAX_ITER / 10 && n <= 9 * MAX_ITER / 10) 
		return (img_pxl_put(&data->img, x, y, create_color(50, 70, 0)));
	else if (n > 9 * MAX_ITER / 10 && n <= MAX_ITER)
		return (img_pxl_put(&data->img, x, y, create_color(20, 70, 0)));
}

// void	choose_color(int x, int y, t_data *data, int n)
// {
// 	if (((n % 10)) == 0)
// 		return (img_pxl_put(&data->img, x, y, create_color(255, 255, 255)));
// 	else if ((n % 10) == 1)
// 		return (img_pxl_put(&data->img, x, y, create_color(225, 125, 70)));
// 	else if ((n % 10) == 2)
// 		return (img_pxl_put(&data->img, x, y, create_color(200, 70, 0)));
// 	else if ((n % 10) == 3)
// 		return (img_pxl_put(&data->img, x, y, create_color(175, 70, 0)));
// 	else if ((n % 10) == 4)
// 		return (img_pxl_put(&data->img, x, y, create_color(150, 70, 0)));
// 	else if ((n % 10) == 5)
// 		return (img_pxl_put(&data->img, x, y, create_color(125, 70, 0)));
// 	else if ((n % 10) == 6)
// 		return (img_pxl_put(&data->img, x, y, create_color(100, 70, 0)));
// 	else if ((n % 10) == 7)
// 		return (img_pxl_put(&data->img, x, y, create_color(75, 70, 0)));
// 	else if ((n % 10) == 8)
// 		return (img_pxl_put(&data->img, x, y, create_color(50, 70, 0)));
// 	else if ((n % 10) == 9)
// 		return (img_pxl_put(&data->img, x, y, create_color(20, 70, 0)));
// }

// int create_pallette(t_data *data, int n)
// {
// 	int	i;
// 	int	*tab[MAX_ITER];
// 	int	**array;
// 	int	total;
// 	int x;
// 	int y;
// 	int j;
	
// 	j = 0;
// 	total = 0;
// 	x = 0;
// 	i = 0;
// 	while (x < WINDOW_WIDTH)
// 	{
// 		y = 0;
// 		while(y < WINDOW_HEIGHT)
// 		{
// 			// j = array[x][y];
// 			tab[j] = tab[j] + 1;
// 			y++;
// 			while (i < MAX_ITER)
// 			{
// 				total += *tab[j];
// 				i++;
// 			}
// 		}
// 		x++;
// 	}
// }

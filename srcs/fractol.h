/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:10:38 by afontain          #+#    #+#             */
/*   Updated: 2023/04/04 18:51:39 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#	define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stdio.h>
# include <math.h>

#include "../mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define MLX_ERROR 1

#define MAX_ITER 250

#define x1 -2.1
#define x2 0.6
#define y1 -1.2
#define y2 1.2

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 900

// typedef struct s_complex
// {
// 	double	a;
// 	double	b;
// }t_complex;

typedef struct s_img
{
	int		bpp;
	int		line_len;
	int		endian;
	char	*addr;
	void	*mlx_img;
}t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	double	ca;
	double	cb;
	double	xup;
	double	xdown;
	double	yup;
	double	ydown;
	double	movex;
	double	movey;
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
	t_img	img;
	// t_complex julia;
}t_data;	

//Main
void	img_pxl_put(t_img *img, int x, int y, int color);

// Close Window
int		handle_keypress(int keysym, t_data *data);
int		handle_mousepress(t_data *data);

// Render
// int		render(t_data *data);

//Utils

//Julia_set
int	julia(t_data *data);

//Colors
void	choose_color(int x, int y, t_data *data, int n);
int	create_color(int R, int G, int B);

#endif
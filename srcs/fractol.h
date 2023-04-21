/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:10:38 by afontain          #+#    #+#             */
/*   Updated: 2023/04/21 14:37:15 by afontain         ###   ########.fr       */
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

#define MAX_ITER 1000

#define MANDELBROT 1
#define JULIA 2
#define BURNING_SHIP 3

#define MOUSE_BTN_4 4
#define MOUSE_BTN_5 5
#define EVENT_CLOSE_BTN 17

// //Mandelbrot scope
// #define xm1 -2
// #define xm2 0.6
// #define ym1 -1.2
// #define ym2 1.2

// //Julia scope
// #define xj1 -1.5
// #define xj2 1.5
// #define yj1 -1.5
// #define yj2 1.5

// //Burning_ship scope
// #define xb1 -2.1
// #define xb2 0.6
// #define yb1 -1.2
// #define yb2 1.2

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 900

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_complex
{
	double	za;
	double	zb;
	double	tmp;
}t_complex;

typedef struct s_cmplx
{
	double	ca;
	double	cb;
}t_cmplx;

typedef struct s_img
{
	int		bpp;
	int		line_len;
	int		endian;
	char	*addr;
	void	*mlx_img;
}t_img;

// typedef struct s_fract
// {
// 	int	*julia;
// 	int *mandelbrot;
// 	int *burning_ship;
// }t_fract;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		set;
	double	ca;
	double	cb;
	double 	vr;
	double 	vc;
	double 	cs;
	double	count_zoom;
	double	xmax;
	double	xmin;
	double	ymax;
	double	ymin;
	int		mouse_x;
	int		mouse_y;
	int		x;
	int		y;
	// int		width;
	// int		height;
	// int		color;
	t_img	img;
	t_complex complex;
	t_cmplx	cmplx;
}t_data;	

//Main
void	img_pxl_put(t_img *img, int x, int y, int color);

// Close Window
int		handle_keypress(int keysym, t_data *data);
int		handle_mousepress(t_data *data);
int 	close_it(t_data *data);
void	clean_exit(int exit_code, t_data *data);

// Render
// int		render(t_data *data);

//Utils
int		ft_strcmp(char *s1, char *s2);
double	ft_atof(char *str);

//Mandelbrot
int		mandelbrot(t_data *data);

//Julia
int		julia(t_data *data);

//Burning_ship
int 	burning_ship(t_data *data);

//Colors
// void	basic_choose_color(int x, int y, t_data *data, int n);
void	choose_colors(t_data *data, int x, int y, int n);
void	choose_colors1(t_data *data, double za, double zb, int x, int y, int n);
void	choose_colors2(t_data *data, double za, double zb, int x, int y, int n);
int		create_color(int R, int G, int B);

//Choose Fractals
int		check_args(t_data *data, int ac, char **av);
void	get_fractal(t_data *data,int ac, char **av);
int 	choose_fractal(t_data *data);

//Manage_events
void	zoom(t_data *data, double zoom);
void 	move(t_data *data, double move, char direction);
int		key_event(int keysym, t_data *data);
int 	mouse_event(int keysym, int x, int y, t_data *data);
int		mouse_pos(int x, int y, t_data *data);

//Create image
int	 	init_window(t_data *data);
void	init_data(t_data *data);

#endif
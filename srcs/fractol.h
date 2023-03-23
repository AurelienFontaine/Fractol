/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:10:38 by afontain          #+#    #+#             */
/*   Updated: 2023/03/23 15:20:12 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#	define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stdio.h>

#include "../mlx/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0x00FF00
#define BLUE_PIXEL 0x0000FF

#define WHITE_PIXEL 0xFFFFFF
#define BLACK_PIXEL 0x000000

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}t_img;	

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}t_data;

typedef struct t_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}t_rect;	

// typedef struct s_list
// {
// 	int				content;
// 	int				index;
// 	struct s_list	*next;
// }t_list;

//Main


// Close Window
int		handle_keypress(int keysym, t_data *data);
int		handle_mousepress(t_data *data);

// Render
int		render(t_data *data);


#endif
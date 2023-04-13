# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afontain <afontain@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 13:09:26 by afontain          #+#    #+#              #
#    Updated: 2023/04/13 17:48:56 by afontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		fractol

SRCS_DIR = srcs/

GNL_DIR = GNL/

SRCS =		${GNL_DIR}get_next_line_utils.c \
 			${GNL_DIR}get_next_line.c \
		 	${SRCS_DIR}main.c \
			${SRCS_DIR}mandelbrot.c \
			${SRCS_DIR}julia.c \
			${SRCS_DIR}burning_ship.c \
			${SRCS_DIR}close_window.c \
			${SRCS_DIR}colors.c \
			${SRCS_DIR}choose_fractal.c \
			${SRCS_DIR}utils.c \
			${SRCS_DIR}manage_events.c \
			${SRCS_DIR}create_image.c \
			${SRCS_DIR}draw_mouse.c
			
_DEPS =		fractol.h

INCL =		./includes/

DEPS =		$(patsubst %,$(INCL)/%,$(_DEPS))

OBJS =		${SRCS:.c=.o}

CC =		clang

RM =		rm -f

CFLAGS =	-Wall -Werror -Wextra -g

MLX =		./mlx

MLX_LIB = 	./mlx/libmlx_Linux.a

.c.o:		${DEPS} 
		${CC} ${CFLAGS} -I${INCL} -I${MLX} -g3 -c $< -o ${<:.c=.o}

		

$(NAME):	${OBJS} $(MLX_LIB)
		${CC} ${CFLAGS}  ${OBJS} -o ${NAME} ${MLX_LIB}\
		-L -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

$(MLX_LIB):
		make -C ${MLX} -j


all:		${NAME}

malloc_test: $(OBJS) $(MLX_LIB)
	$(CC) ${OBJS} $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${MLX_LIB} -L. -lmallocator

clean:		
		${RM} ${OBJS}
		make clean -C ${MLX}

fclean:		clean
		${RM} ${NAME}
		${RM} ${NAME} ${MLX_LIB}

re:		fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re
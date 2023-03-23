/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:08:17 by afontain          #+#    #+#             */
/*   Updated: 2023/03/21 16:01:16 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdint.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
void	read_next_line(char *line, char *buffer);
char	*line_to_buffer(char *str);
char	*read_line(int fd, char *str);
char	*ft_strchr(const char *str, int c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
void	*ft_memset(void *str, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:18:58 by makurek           #+#    #+#             */
/*   Updated: 2024/12/05 16:05:09 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif
# define MAX_FD OPEN_MAX

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

# if BUFFER_SIZE < 1
#  define BUFFER_ZERO 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 1
# else
#  define BUFFER_ZERO 0
# endif

typedef struct s_struct
{
	char	buffer[BUFFER_SIZE];
	char	*current;
	int		bytes_read;
}	t_buffer;

char	*get_next_line(int fd);

#endif

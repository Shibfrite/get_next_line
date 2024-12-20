/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:18:58 by makurek           #+#    #+#             */
/*   Updated: 2024/12/20 16:54:39 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
//# include <stdio.h>
//# include <fcntl.h>

# ifndef MAX_FD
#  define MAX_FD 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

typedef struct s_struct
{
	char	buffer[BUFFER_SIZE + 1];
	char	*current;
	int		bytes_read;
}	t_buffer;

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2, size_t len2);
char	*get_next_line(int fd);

#endif

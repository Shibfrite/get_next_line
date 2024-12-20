/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/31 18:18:54 by makurek		   #+#	#+#			 */
/*   Updated: 2024/12/20 16:54:06 by makurek          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_buffer(t_buffer *buf, int fd, char **line)
{
	int	read_result;

	if (!buf->current || buf->current >= buf->buffer + buf->bytes_read)
	{
		buf->bytes_read = read(fd, buf->buffer, BUFFER_SIZE);
		buf->buffer[buf->bytes_read] = '\0';
		if (buf->bytes_read <= 0)
		{
			read_result = buf->bytes_read;
			if (read_result < 0)
			{
				free(*line);
				buf->buffer[0] = '\0';
				buf->current = NULL;
				buf->bytes_read = 0;
			}
			return (read_result);
		}
		buf->current = buf->buffer;
	}
	return (1);
}

static char	*process_buffer(t_buffer *buf, char *old_line)
{
	char	*nl_char;
	char	*new_line;
	size_t	chunk_len;

	nl_char = ft_strchr(buf->current, '\n');
	if (nl_char)
		chunk_len = (size_t)(nl_char - buf->current + 1);
	else
		chunk_len = (size_t)(buf->buffer + buf->bytes_read - buf->current);
	new_line = ft_strjoin(old_line, buf->current, chunk_len);
	free(old_line);
	if (!new_line)
		return (0);
	buf->current += chunk_len;
	return (new_line);
}

char	*get_next_line(int fd)
{
	static t_buffer	buffers[MAX_FD];
	t_buffer		*buf;
	char			*line;
	int				read_result;

	if (fd < 0 || fd >= MAX_FD)
		return (0);
	buf = &buffers[fd];
	line = 0;
	while (1)
	{
		read_result = read_buffer(buf, fd, &line);
		if (read_result < 0)
			return (NULL);
		else if (!read_result)
			return (line);
		line = process_buffer(buf, line);
		if (!line)
			return (0);
		if (ft_strchr(line, '\n'))
			return (line);
	}
}

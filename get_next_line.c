/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: makurek <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/31 18:18:54 by makurek		   #+#	#+#			 */
/*   Updated: 2024/12/16 15:08:26 by makurek          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!c)
		return ((char *)s);
	return (NULL);
}

static char	*ft_strjoin(char *s1, char *s2, size_t len2)
{
	size_t	len1;
	char	*result;
	char	*ptr;

	len1 = 0;
	while (s1 && s1[len1])
		len1++;
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (0);
	ptr = result;
	while (s1 && *s1)
		*ptr++ = *s1++;
	while (len2--)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (result);
}

static int	read_buffer(int fd, t_buffer *buffers)
{
	t_buffer	*buf;

	buf = &buffers[fd];
	buf->bytes_read = read(fd, buf->buffer, BUFFER_SIZE);
	if (buf->bytes_read <= 0)
	{
		buffers[fd] = (t_buffer){0};
		return (buf->bytes_read);
	}
	buf->buffer[buf->bytes_read] = '\0';
	buf->current = buf->buffer;
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
	char			*line;

	if (fd < 0 || fd >= MAX_FD)
		return (0);
	line = 0;
	while (1)
	{
		if (buffers[fd].current == 0
			|| buffers[fd].current >= buffers[fd].buffer
			+ buffers[fd].bytes_read)
			if (read_buffer(fd, buffers) <= 0)
				return (NULL);
		line = process_buffer(&buffers[fd], line);
		if (!line)
			return (0);
		if (ft_strchr(line, '\n'))
			return (line);
	}
}

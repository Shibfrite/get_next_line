/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makurek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:31:55 by makurek           #+#    #+#             */
/*   Updated: 2024/12/11 12:32:20 by makurek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
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

char	*ft_strjoin(char *s1, char *s2, size_t len2)
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

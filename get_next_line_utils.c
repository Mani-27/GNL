/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:32:08 by sayari            #+#    #+#             */
/*   Updated: 2021/02/23 14:49:29 by sayari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p_dest;

	i = 0;
	p_dest = (unsigned char *)dst;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		p_dest[i] = *(unsigned char *)src;
		src++;
		i++;
	}
	return (dst);
}
char		*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;
	
	len = ft_strlen(s1);
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1, len);
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

int	ft_save_or_not(char *s1, int index)
{
	int len_s1;

	len_s1 = ft_strlen(s1);
	if (len_s1 == 1)
		return (0);
	else if(index < len_s1)
		return (1);
	return (0);
}

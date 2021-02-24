/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tphilipp <tphilipp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 16:48:49 by sayari            #+#    #+#             */
/*   Updated: 2021/02/24 15:00:06 by tphilipp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_find_newline(char *s, char c)
{
		int i;

		i = 0;
		if (s[i])
		{
				while (s[i] && (s[i] != c))
						i++;
				if (s[i] == c)
						return (i);
		}
		return (-1);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!(ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	return (ptr);
}
char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr_s;
	size_t			i;

	i = 0;
	if (!s || len <= 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
	ptr_s = (char *)malloc(sizeof(char) * len + 1);
	if (ptr_s == NULL)
		return (NULL);
	while (i < len)
	{
		ptr_s[i] = s[start];
		i++;
		start++;
	}
	ptr_s[i] = '\0';
	return (ptr_s);
}
int	get_next_line(int fd, char **line)
{
	char bf[BUFFER_SIZE + 1];
	ssize_t ret;
	static char *save = NULL;
	int index;
	char *temp = NULL;

	index = -1;
	ret = 1;
	if (fd < 0 || fd > 255 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	//*line = malloc(sizeof(char) * BUFFER_SIZE);
	*line = NULL;
	//if (*line == NULL)
	//	return(-1);
	//if ((*line = malloc(sizeof(char) * BUFFER_SIZE)) == NULL)
	//	return (-1);
	while (ret > 0)
	{
		if (save == NULL)
		{
			ret = read(fd, bf, BUFFER_SIZE);
			if (ret == 0)
				return (0);
			bf[ret] = '\0';
		}
		else
		{	
			printf("b \n");
			ft_strcpy(bf, save);
			save = NULL;
			index = ft_find_newline(bf, '\n');
			if (index != -1)
			{
				bf[index] = '\0';
				temp = *line;
				free(*line);
				*line = NULL;
				*line = ft_strjoin(temp, bf);
				if (!((bf + index + 1) == NULL))
					save = ft_strdup(bf + index + 1);
				return (1);
			}
		}
/***********************************************************************/
		index = ft_find_newline(bf, '\n');
		if (index != -1)
		{
			printf("b \n");
			temp = *line;
			*line = ft_strjoin(temp, ft_substr(bf, 0, index));
			free(temp);
			temp = NULL;
			if (!((bf + index + 1) == NULL))
			{
				save = ft_strdup(bf + index + 1);
			}
			return(1);
		}
		else
		{
			//temp = *line;
			if (!*line)
				*line = malloc(sizeof(char) * BUFFER_SIZE);
			temp = *line;
			*line = ft_strjoin(temp, bf);
			free(temp);
			temp = NULL;
			printf("p \n");
		}
	}
	return (0);
}

int main(void)
{
	ssize_t r;
	char bf[BUFFER_SIZE + 1];
	char *line = NULL;
	int fd;
	fd = open("test.txt", O_RDONLY);
	printf(" %d  %s \n", get_next_line(fd, &line), line);
	line = NULL;
	printf("%d  %s \n", get_next_line(fd, &line), line);
	//line = NULL;
	//printf("%d  %s \n", get_next_line(fd, &line), line);
	//line = NULL;
	//printf("%d  %s \n", get_next_line(fd, &line), line);
	close(fd);
}

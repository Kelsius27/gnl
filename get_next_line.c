/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:57:34 by kmarques          #+#    #+#             */
/*   Updated: 2021/08/23 18:04:42 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
		if (s[l] == '\n')
			return (l + 1);
	return (l);
}

int	ft_findnl(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

char	*ft_writeline(char *line, char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*tmp;

	i = 0;
	j = 0;
	size = ft_strlen(line) + ft_strlen(buffer);
	tmp = ft_strdup(line);
	free(line);
	line = malloc((size + 1) * sizeof(char));
	while (*(tmp + j))
	{
		*(line + j) = *(tmp + j);
		j++;
	}
	while (j < size)
	{
		*(line + j) = *(buffer + i);
		i++;
		j++;
	}
	*(line + j) = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	//static char	*save;
	int			nl;

	nl =  0;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buffer[BUFFER_SIZE] = '\0';
	line = malloc(1 * sizeof(char));
	*line = '\0';
	while (!nl)
	{
		read(fd, buffer, BUFFER_SIZE);
		nl = ft_findnl(buffer);
		line = ft_writeline(line, buffer);
	}
	free(buffer);
	return (line);
}

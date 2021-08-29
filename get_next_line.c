/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:57:34 by kmarques          #+#    #+#             */
/*   Updated: 2021/08/28 00:31:49 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Find a `\n` on the string
 *
 * @param buffer String to search
 * @return int Return 1 if find or 0 if not
 */
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

/**
 * @brief Get the next line of file
 *
 * @param fd File descriptor
 * @return char* Return line
 */
char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	static char	*save;
	ssize_t		bytesread;

	if (!save)
		save = ft_strdup("\0");
	while (!ft_findnl(save))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (((*save == '\0') && (bytesread == 0)) || (bytesread == -1))
		{
			free (save);
			save = NULL;
			return (NULL);
		}
		if (bytesread == 0)
			break ;
		buffer[bytesread] = '\0';
		save = ft_joinbuffer(save, buffer);
	}
	line = ft_getnline(save);
	save = ft_trimsave(save);
	return (line);
}

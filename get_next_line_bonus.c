/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 16:57:34 by kmarques          #+#    #+#             */
/*   Updated: 2021/08/28 21:38:53 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list	*ft_findaddlst(t_list *elem, int fd)
{
	t_list	*newelem;

	if (elem)
	{
		while (elem->next != NULL)
		{
			if (elem->fd == fd)
				return (elem);
			elem = elem->next;
		}
		if (elem->fd == fd)
			return (elem);
	}
	newelem = (t_list *)malloc(1 * sizeof(t_list));
	if (newelem == NULL)
		return (NULL);
	if (elem)
		elem->next = newelem;
	newelem->fd = fd;
	newelem->content = ft_strdup("\0");
	newelem->previous = elem;
	newelem->next = NULL;
	return (newelem);
}

t_list	*ft_firstlst(t_list *elem)
{
	if (!elem)
		return (NULL);
	while (elem->previous != NULL)
		elem = elem->previous;
	return (elem);
}

t_list	*ft_delelem(t_list *elem)
{
	free (elem->content);
	if (!elem->next && !elem->previous)
	{
		free (elem);
		return (NULL);
	}
	else if (!elem->previous)
	{
		elem->next->previous = NULL;
		free (elem);
		return (elem->next);
	}
	else if (!elem->next)
		elem->previous->next = NULL;
	else
	{
		elem->previous->next = elem->next;
		elem->next->previous = elem->previous;
	}
	free (elem);
	return (ft_firstlst(elem->previous));
}

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
	char			buffer[BUFFER_SIZE + 1];
	char			*line;
	static t_list	*elem;
	ssize_t			bytesread;

	elem = ft_findaddlst(elem, fd);
	while (!ft_findnl(elem->content))
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (((*elem->content == '\0') && (bytesread == 0)) || (bytesread == -1))
		{
			elem = ft_delelem(elem);
			return (NULL);
		}
		if (bytesread == 0)
			break ;
		buffer[bytesread] = '\0';
		elem->content = ft_joinbuffer(elem->content, buffer);
	}
	line = ft_getnline(elem->content);
	elem->content = ft_trimsave(elem->content);
	if ((*elem->content == '\0') && (bytesread == 0))
		elem = ft_delelem(elem);
	elem = ft_firstlst(elem);
	return (line);
}

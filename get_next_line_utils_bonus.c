/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:03:58 by kmarques          #+#    #+#             */
/*   Updated: 2021/08/28 00:42:32 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief Length of the string
 *
 * @param s String
 * @return size_t Length of string
 */
size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}

/**
 * @brief Initialize string with s
 *
 * @param s String to be copied
 * @return char* New string with malloc
 */
char	*ft_strdup(const char *s)
{
	char	*dst;
	int		i;

	i = 0;
	while (*(s + i))
		i++;
	dst = malloc(i + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(dst + i) = *(s + i);
		i++;
	}
	*(dst + i) = '\0';
	return (dst);
}

/**
 * @brief Join previous save with new buffer
 *
 * @param save Previous save
 * @param buffer New read
 * @return char* String after join
 */
char	*ft_joinbuffer(char *save, char *buffer)
{
	size_t	count;
	char	*tmp;
	int		i;

	count = ft_strlen(save) + ft_strlen(buffer);
	tmp = malloc((count + 1) * sizeof(char));
	i = 0;
	while (*(save + i) != '\0')
	{
		*tmp = *(save + i);
		i++;
		tmp++;
	}
	while (*buffer != '\0')
	{
		*tmp = *buffer;
		buffer++;
		tmp++;
	}
	*tmp = '\0';
	free (save);
	return (tmp - count);
}

/**
 * @brief Copy new line form save
 *
 * @param save Saved string
 * @return char* New line from file
 */
char	*ft_getnline(char *save)
{
	int		count;
	char	*line;
	int		i;

	count = 0;
	while ((save[count] != '\n') && (save[count] != '\0'))
		count++;
	if (save[count] == '\n')
		count++;
	line = malloc((count + 1) * sizeof(char));
	i = 0;
	while (count > i)
	{
		*(line + i) = *(save + i);
		i++;
	}
	*(line + i) = '\0';
	return (line);
}

/**
 * @brief Trim saved string of line returned
 *
 * @param save Saved string
 * @return char* final save after removing line returned
 */
char	*ft_trimsave(char *save)
{
	char	*newsave;
	int		i;
	int		j;

	i = 0;
	while ((*(save + i) != '\n') && (*(save + i) != '\0'))
		i++;
	if (*(save + i) == '\n')
		i++;
	newsave = malloc((ft_strlen(save + i) + 1) * sizeof(char));
	j = 0;
	while (*(save + i) != '\0')
	{
		*(newsave + j) = *(save + i);
		j++;
		i++;
	}
	*(newsave + j) = '\0';
	free (save);
	return (newsave);
}

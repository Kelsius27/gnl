/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:03:58 by kmarques          #+#    #+#             */
/*   Updated: 2021/08/23 18:04:52 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 00:27:46 by kmarques          #+#    #+#             */
/*   Updated: 2021/08/28 00:31:40 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
int		ft_findnl(char *buffer);
char	*ft_strdup(const char *s);
char	*ft_joinbuffer(char *save, char *buffer);
size_t	ft_strlen(const char *s);
char	*ft_getnline(char *save);
char	*ft_trimsave(char *save);

#endif

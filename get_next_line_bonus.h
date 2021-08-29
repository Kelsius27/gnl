/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarques <kmarques@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 00:27:46 by kmarques          #+#    #+#             */
/*   Updated: 2021/08/28 16:33:46 by kmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_list
{
	struct s_list	*previous;
	int				fd;
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		ft_findnl(char *buffer);
char	*ft_strdup(const char *s);
char	*ft_joinbuffer(char *save, char *buffer);
size_t	ft_strlen(const char *s);
char	*ft_getnline(char *save);
char	*ft_trimsave(char *save);
t_list	*ft_findaddlst(t_list *elem, int fd);
t_list	*ft_firstlst(t_list *elem);
t_list	*ft_delelem(t_list *elem);

#endif

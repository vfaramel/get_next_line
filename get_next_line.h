/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 03:14:03 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/07 01:05:55 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	makelist(t_list *start, int fd);
void	ft_lstadd_back(t_list *lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_strchr(char *s);
t_list	*ft_lstnew(char *content);
char	*finalstringlen(t_list *start);
char	*finalstring(t_list *start);
t_list	*newstart(t_list *start);

#endif

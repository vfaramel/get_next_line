/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 01:35:46 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/07 03:05:48 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list *lst, t_list *new)
{
	t_list	*last;

	if (lst)
	{
		last = ft_lstlast(lst);
		last->next = new;
	}
	else
		lst = new;
}

t_list	*ft_lstnew(char *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}

t_list	*newstart(t_list *start)
{
	int		i;
	int		n;
	char	*arr;
	char	c;

	i = 0;
	n = 0;
	c = '\0';
	arr = &c;
	while (start->content[i])
	{
		if (start->content[i++] == '\n')
		{
			while (start->content[i + n])
				n++;
			arr = (char *)malloc((n + 1) * sizeof(char));
			n = 0;
			while (start->content[i])
				arr[n++] = start->content[i++];
			arr[n] = '\0';
		}
	}
	start = ft_lstnew(arr);
	return (start);
}

char	*get_next_line(int fd)
{
	static t_list	*start;
	char			*final;
	char			c;

	if (!start)
	{
		c = '\0';
		start = ft_lstnew(&c);
	}
	makelist(start, fd);
	final = finalstring(start);
	if (!*final)
		return (0);
	start = ft_lstlast(start);
	start = newstart(start);
	return (final);
}

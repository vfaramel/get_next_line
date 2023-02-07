/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 04:12:08 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/07 04:01:42 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*finalstringlen(t_list *start)
{
	t_list	*node;
	int		i;
	int		tot;
	char	*final;

	node = start;
	tot = 0;
	while (node)
	{
		i = 0;
		while (node->content[i])
		{
			tot++;
			if (node->content[i++] == '\n')
				break ;
		}
		node = node->next;
	}
	final = (char *)malloc((tot + 1) * sizeof(char));
	return (final);
}

char	*finalstring(t_list *start)
{
	char	*final;
	t_list	*node;
	int		x;
	int		i;

	final = finalstringlen(start);
	node = start;
	x = 0;
	while (node)
	{
		i = 0;
		while (node->content[i])
		{
			//write(1, node->content + i,1);
			final[x] = node->content[i];
			//printf("%c %d\n", final[x], x);
			x++;
			if (node->content[i++] == '\n')
				break ;
		}
		node = node->next;
	}
	final[x] = '\0';
	i = 0;
	while (*(final + i))
	{
		i++;
	}
	return (final);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_strchr(char *s)
{
	while (*(s) && s)
	{
		if ('\n' == *(s++))
			return (1);
	}
	return (0);
}

void	makelist(t_list *start, int fd)
{
	ssize_t	i;
	ssize_t	x;
	char	*pbuf;
	t_list	*node;
	char	*arr;

	node = start;
	pbuf = malloc(BUFFER_SIZE + 1);
	while (!ft_strchr(node->content))
	{
		i = -1;
		x = read(fd, pbuf, BUFFER_SIZE);
		if (!x)
			return ;
		arr = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		node = ft_lstnew((void *)arr);
		ft_lstadd_back(start, node);
		while (++i < x)
			node->content[i] = pbuf[i];
		node->content[i] = '\0';
		i = 0;
	}
}

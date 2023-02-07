/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfaramel <vfaramel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:36:40 by vfaramel          #+#    #+#             */
/*   Updated: 2023/02/07 04:03:54 by vfaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*arr;
	int		i;
	int		fd1;
	char	*brr;

	i = 0;
	fd = open("hello", O_RDONLY);
	fd1 = open("text2", O_RDONLY);
	arr = get_next_line(fd);
//	brr = get_next_line(fd1);
	while(arr)
	{
		printf("%s\n", arr);
		arr = get_next_line(fd);
//		printf("%s\n", brr);
//		brr = get_next_line(fd1);
	}
	close(fd);
	close(fd1);
	return (0);
}

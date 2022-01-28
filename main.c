/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebloodbe <ebloodbe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:46:16 by ebloodbe          #+#    #+#             */
/*   Updated: 2021/12/09 12:59:54 by ebloodbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> // printf
#include <fcntl.h> // open

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	i = 16;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	while (i--)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	close (fd);
	return (0);
}

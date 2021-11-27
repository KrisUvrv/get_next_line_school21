/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebloodbe <ebloodbe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:29:49 by ebloodbe          #+#    #+#             */
/*   Updated: 2021/11/27 14:37:03 by ebloodbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *line;
	static char	*buffer;
	
	
	//static char	buffer[BUFFER_SIZE + 1];
	static int i;
	int j;
	static int count_lines;
	
	char *rest;
	char *result;
	long count;
	
	if (read(fd, buffer, 0) != 0 || BUFFER_SIZE <= 0)
		return NULL;
	line = (char *)malloc(sizeof(char));
	line[0] = '\0';
	if (buffer[i] == '\n')
	{
		i++;
	}
	j = 0;
	while (count_lines == 0 || buffer[i] != '\n')
	{
		if (buffer[i] == '\0')
		{
			count = read(fd, buffer, BUFFER_SIZE);
			if (count <= 0)
				return (ft_return_line(line));
			buffer[count] = '\0';
			i = 0;
		}
		j = 0;
		while (buffer[i + j] && buffer[i + j] != '\n')
		{
			j++;
		}
		rest = (char *)malloc(sizeof(char) * j + 1 + (buffer[i] == '\n'));
		if (!rest)
			return (ft_return_line(line));
		
		ft_strlcpy(rest, buffer + i, j);
		i = i + j;
		if (buffer[i] == '\n')
		{
			count_lines++;
			rest[j++] = '\n';
		}
		rest[j] = '\0';
		result = ft_strjoin(line, rest);
		free(line);
		free(rest);
		line = result;
	}
	if (j == 0 && buffer[i] == '\n')
	{
		free(line);
		line = (char *)malloc(sizeof(char) * 2);
		line[0] = '\n';
		line[1] = '\0';
	}
	return (ft_return_line(line));
}

int main(int argc, char **argv)
{
	int	fd;
	int i;
	char *line; 

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
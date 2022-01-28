/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebloodbe <ebloodbe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:29:49 by ebloodbe          #+#    #+#             */
/*   Updated: 2021/12/09 10:25:22 by ebloodbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*ft_read_line(int fd, char *str, long count)
{
	char	*buff;

	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (!ft_strchr(str, '\n') && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[count] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1 + (str[i] == '\n'));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_trimstr(char *str)
{
	int		i;
	int		j;
	char	*trimstr;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	trimstr = (char *)malloc(sizeof(char) * ft_strlen(str) - i + 1);
	if (!trimstr)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		trimstr[j++] = str[i++];
	trimstr[j] = '\0';
	free(str);
	return (trimstr);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;
	long		count;

	count = 1;
	if (read(fd, str, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_line(fd, str, count);
	if (!str)
		return (NULL);
	line = ft_line(str);
	str = ft_trimstr(str);
	return (line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebloodbe <ebloodbe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:57:42 by ebloodbe          #+#    #+#             */
/*   Updated: 2021/11/29 22:04:20 by ebloodbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str, char *buff)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!str && !buff)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(str) + (ft_strlen(buff) + 1)));
	i = 0;
	j = 0;
	if (str)
	{
		while (str[i])
		{
			result[i] = str[i];
			i++;
		}
	}
	while (buff[j])
		result[i++] = buff[j++];
	result[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (result);
}

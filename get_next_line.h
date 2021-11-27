/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebloodbe <ebloodbe@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:57:53 by ebloodbe          #+#    #+#             */
/*   Updated: 2021/11/24 15:41:03 by ebloodbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1024

# include <stdio.h> // printf
# include <fcntl.h> // open
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int num;
	char *line;
	struct s_list	*next;
}	t_list;

char *get_next_line(int fd);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strcpy(char *dst, const char *src);
void	ft_strclr(char *s);
char	*ft_strnew(size_t size);
char *ft_return_line(char *line);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);

#endif
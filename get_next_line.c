/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:23:29 by hfanzaou          #+#    #+#             */
/*   Updated: 2021/11/28 22:00:29 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char *c = "";
	char *l;
	char *t;
	int i;
	int j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	t = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!t)
		return (0);
	while (ft_cmp(c, '\n') && i != 0)
	{
		i = read(fd, t, BUFFER_SIZE);
		if (i == -1)
		{
			return NULL; 
		}
		t[i] = '\0';
		c = ft_strjoin(c, t);
		
	}
	free(t);
	j = 0;
	while (c[j] && c[j] != '\n')
		j++;
	l = malloc(sizeof(char) * (j + 1));
	if(!l)
		return 0;
	j = 0;
	while (*c && *c != '\n')			
	{
		l[j] = *c++;
		j++;
	}
	c++;
	l[j] = '\0';
	return l;	
}

int main()
{
	int fd = open("text.txt", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}

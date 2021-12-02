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

char 	*get_alloc(int i)
{
	char *c;

	c = malloc(sizeof(char) * (i + 1));
	if (!c)
		return (NULL);
	return (c);	
}

char	*get_read(char *c, int fd)
{
	int i;
	char *t;

	if (!c)
	{
		c = get_alloc(1);
		*c = '\0';
	}
	t = get_alloc(BUFFER_SIZE);
	i = 1;
	while (ft_cmp(c, '\n') && i > 0)
	{
		i = read(fd, t, BUFFER_SIZE);
		if (i < 0 || (!i && !*t))
		{
			free(t);
			free(c);
			return (NULL);
		}
		t[i] = '\0';
		c = ft_strjoin(c, t);
	}
	free(t);
	return (c);
}
char	*get_line(char *c)
{
	int i;
	char *l;

	i = 0;
	if (!*c)
	{
		free(c);
		return (ft_strdup("\0"));
	}
	else if (*c == '\n')
	{
		return (ft_strdup("\n"));
	}
	while (c[i] && c[i] != '\n')
		i++;	
	l = get_alloc(i);
	i = 0;
	while (c[i])
	{
		l[i] = c[i];
		i++;
		if (c[i - 1] == '\n')
			break;
	}
	l[i] = '\0';
	return (l);
}

char	*get_save(char *c)
{
	int i;
	char *s;

	i = 0;
	if (!*c)
	{
		free(c);
		return (NULL);
	}
	while (c[i] && c[i] != '\n')
		i++;	
	s = ft_substr(c, i + 1, ft_strlen(c));
	return (s);
}

char 	*get_next_line(int fd)
{
	static char *c;
	char *l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	c = get_read(c, fd);
	if(!c)
		return (NULL);
	l = get_line(c);
	if (!*l)
	{
		free(l);
		return (NULL);
	}
	c = get_save(c);
	return (l);

}

int main()
{
	int fd = open("text.txt", O_RDWR);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//get_next_line(fd);
}
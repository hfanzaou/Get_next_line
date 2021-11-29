/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 22:15:34 by hfanzaou          #+#    #+#             */
/*   Updated: 2021/11/28 22:15:36 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*c;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	c = malloc(sizeof(char) * i + 1);
	if (c == NULL)
		return (0);
	j = 0;
	while (*s1)
	{
		c[j] = *s1++;
		j++;
	}
	while (*s2)
	{
		c[j] = *s2++;
		j++;
	}
	c[j] = '\0';
	return (c);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_cmp(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return 0;
		s++;
	}
	return 1;
}


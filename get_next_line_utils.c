/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:48:55 by sleleu            #+#    #+#             */
/*   Updated: 2022/05/24 19:11:44 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		size;
	int		i;
	char	*tab;

	i = 0;
	//if (ft_strlen(s2) && ft_strlen(s2) < BUFFER_SIZE) 
	size = (ft_strlen(s1) + ft_strlen(s2));
	//else
	//	size = ft_strlen(s1) + BUFFER_SIZE;
	tab = malloc(sizeof(char) * size + 1);
	tab[size] = '\0';
	if (tab == NULL)
		return (NULL);
	while (*s1)
	{
		tab[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)// && i < size)
	{
		tab[i] = *s2;
		i++;
		s2++;
	}
	return (tab);
}

char	*ft_strdup(char *s1)
{
	char	*tab;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s1[size])
		size++;
	tab = malloc(sizeof(char) * size + 1);
	if (tab == NULL)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*tab;
	int	i;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start + len > ft_strlen(s))
		len = len - start;
	if (start > ft_strlen(s))
		len = 0;
	tab = malloc(sizeof(char) * len + 1);
	if (tab == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		tab[i] = s[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strchr(char *s, int c)
{
	int				i;
	unsigned char	search;

	search = (unsigned char)c;
	i = 0;
	while (s[i] && s[i] != search)
		i++;
	if (s[i] == search)
		return ((char *)s + i);
	else
		return (NULL);
}

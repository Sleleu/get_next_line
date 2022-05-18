/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 12:46:24 by sleleu            #+#    #+#             */
/*   Updated: 2022/05/18 15:48:26 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define	BUFFER_SIZE 1

#include <stdio.h>

void	ft_read_line(char *buff, char *statiks)
{
	int	i;

	i = 0;
	while (*statiks != '\n' || *statiks != EOF)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			ft_free(statiks);
			return ;
		}
		ft_strjoin(buff, statiks);
	}
}

char	*ft_line_to_return(char *str)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	while (*str != '\n' || *str != EOF)
		i++;
	line = malloc(sizeof(char) * i + 1);
		if (!line)
			return (NULL);
	while (line[j])
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_save_char(char *buff)
{
	int	len;
	int	i;
	char	*tab;

	while (buff[i] != '\n')
		i++;
	len = ft_strlen(buff) - i;
	tab = malloc(sizeof(char) * len + 1);
		if (tab == NULL)
			return (NULL);
	ft_strcpy(tab, buff[i]);
	return (tab);
}

char	*get_next_line(int fd)
{
	/*
	static char	*statiks;
	int		len;

	if (fd == -1 || !BUFFER_SIZE)
		return (NULL);
	while (statiks != NULL || statiks != '\0')
	{
		len = ft_read_line(argv[1], statiks);
		statiks = ft_save_char()
	}*/
	static char	*statiks;
	char	*line;
	char	buff[]
	int	res;

	while (res != NULL)
	{
		 res = read(fd, buff, BUFFER_SIZE);
		 	if (res == -1)
				return (NULL);
		if (statiks == NULL)
			statiks = buff;
		else
			ft_strjoin(statiks, buff);
	}
	line = ft_ft_to_return(line);
		if (!line)
			ft_free(line);
	return (line);
}

int	main(int *argc, char **argv)
{
	int	fd;
	char	*line;

	(void)argc;

	fd = open(argv[1], O_RDONLY);

	line = "";

	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);

	return (0);
}

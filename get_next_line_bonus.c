/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:15:13 by sleleu            #+#    #+#             */
/*   Updated: 2022/05/25 23:02:55 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	i++;
	line[i] = '\0';
	return (line);
}

char	*ft_get_endline(char *line, char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		i++;
		while (line[i])
		{
			buff[j] = line[i];
			i++;
			j++;
		}
	}
	buff[j] = '\0';
	return (buff);
}

char	*ft_read_line(int fd, char *line, char *buff)
{
	int	return_value;

	return_value = 1;
	line = ft_strjoin(line, buff);
	while (return_value != 0)
	{
		return_value = read(fd, buff, BUFFER_SIZE);
		buff[return_value] = '\0';
		line = ft_strjoin(line, buff);
		if (ft_strchr(line, '\n'))
		{
			buff = ft_get_endline(line, buff);
			line = ft_get_line(line);
			break ;
		}
	}
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[1024][BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0 || read(fd, buff, 0) == -1)
		return (NULL);
	line = ft_read_line(fd, line, buff[fd]);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

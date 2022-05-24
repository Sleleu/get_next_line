/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleleu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:13:58 by sleleu            #+#    #+#             */
/*   Updated: 2022/05/24 19:23:27 by sleleu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int	ft_error(int fd)
{
	if (fd < 0 || BUFFER_SIZE <= 0/* || read(fd, &line, 0) < 0*/)
		return (1);
	return (0);
}

char	*ft_save(char *stash)
{
	int	len;
	int	i;
	char	*end_line;

	len = 0;
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	len = ft_strlen(stash) - i;
	end_line = malloc(sizeof(char) * len + 1);
		if (!end_line)
			return (NULL);
	end_line = ft_substr(end_line, i + 1, len - 1);
	end_line[len - 1] = '\0';
	return (end_line);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int	len;

	len = 0;
	while (stash[len] && stash[len] != '\n') 
		len++;
	line = malloc(sizeof(char) * (len + 2));
		if (!line)
			return (NULL);
	line = ft_substr(stash, 0, len + 1);
	line[len + 1] = '\0';
	return (line);
}

void	*ft_read(int fd, char *stash)
{
	char	buff[BUFFER_SIZE + 1];
	int	val;
	char	*line;

	val = 1;
	while (val != 0)
	{
		val = read(fd, buff, BUFFER_SIZE);
		// if (val == -1)
		// free(buff)
		// break;
		stash = ft_strjoin(stash, buff);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	if (ft_strchr(stash, '\n'))
	{
		line = ft_get_line(stash);
		printf("\n===\n stash= %s \n=======\n", stash);
		printf("\n===\n line= %s \n=======\n", line);
		if (stash[ft_strlen(stash)] != '\0')
			stash = ft_save(stash);
		printf("stash[] == 0 ? %d ------", (stash[ft_strlen(stash)] == 0)); 
                printf("\n===\n stas DEUXh= %s \n=======\n", stash);                                                                             
                printf("\n===\n line DEUX= %s \n=======\n", line);
	}
	if (ft_strchr(stash, '\0') == stash)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	stash[1024];
//	char		*line;

       // if (ft_error(fd, stash))
         //     return (NULL);
	//stash = malloc(sizeof(char) * BUFFER_SIZE + 1);
	//	if (!stash)
	//		return (NULL);
//	if (!fd || !BUFFER_SIZE)
//		return (NULL);
	return (ft_read(fd, stash));
	//if (!ft_read)
	//stash = ft_save(stash);
//	return (line);
}

int	main(void)
{
	int	fd;
	char *line;
	fd = open("test", O_RDONLY);
	if (fd == -1)
			return (1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);	
}
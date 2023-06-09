/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 01:14:00 by emoreau           #+#    #+#             */
/*   Updated: 2023/03/14 19:54:04 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	line = nextline(fd);
	return (line);
}

char	*nextline(int fd)
{
	static char	*stash[1024];
	char		*buf;
	char		*line;
	ssize_t		readed;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readed = 1;
	*buf = 0;
	while (readed > 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed == -1)
			return (free(buf), NULL);
		buf[readed] = '\0';
		stash[fd] = ft_strjoin_gnl(stash[fd], buf);
		if (backslash(buf) == 1)
			break ;
	}
	if (readed <= 0 && stash[fd][0] == 0)
		return (free(buf), free(stash[fd]), stash[fd] = NULL, NULL);
	line = inistash(stash[fd]);
	stash[fd] = freestash(stash[fd]);
	return (free(buf), line);
}

char	*freestash(char *stash)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	str = malloc(sizeof(char) * (ft_strlen_gnl(stash) - i + 1));
	if (!str)
		return (NULL);
	while (stash[i])
	{
		str[j] = stash[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(stash);
	return (str);
}

char	*inistash(char *stash)
{
	int		i;
	char	*line;

	if (!stash)
		return (NULL);
	line = malloc(sizeof(char) * (sizeline(stash) + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

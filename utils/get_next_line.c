/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaeed <bsaeed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:32:41 by bsaeed            #+#    #+#             */
/*   Updated: 2022/08/26 18:26:27 by bsaeed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	nl_checker(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

char	*gnl_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	line = NULL;
	if (!str[0])
		return (NULL);
	i = nl_checker(str);
	line = mallocer(line, i + 2);
	j = 0;
	i = 0;
	while (str[i] != '\n' && str[i])
		line[j++] = str[i++];
	if (str[i] == '\n')
		line[j++] = str[i++];
	line[j] = '\0';
	return (line);
}

char	*gnl_remains(char *str)
{
	char	*remain;
	int		i;

	i = nl_checker(str);
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	remain = ft_strdup(str + i + 1);
	free (str);
	return (remain);
}

char	*readfile(int fd, char *str)
{
	char	*buff;
	int		readret;

	buff = NULL;
	readret = 1;
	while (!ft_strchr(str, '\n') && readret != 0)
	{
		buff = mallocer(buff, BUFFER_SIZE + 1);
		readret = read(fd, buff, BUFFER_SIZE);
		if (readret == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[readret] = '\0';
		str = ft_strjoin(str, buff);
		free (buff);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 1024)
		return (NULL);
	str = readfile(fd, str);
	if (!str)
		return (NULL);
	line = gnl_line(str);
	str = gnl_remains(str);
	return (line);
}

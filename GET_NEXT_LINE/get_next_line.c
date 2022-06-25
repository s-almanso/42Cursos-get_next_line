/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:19:48 by salmanso          #+#    #+#             */
/*   Updated: 2022/06/25 22:01:39 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> //printf library

#include "get_next_line.h"

// Intial Code

char *ft_read_save(int fd, char *str)
{
	char	*tmp;
	int		count;

	tmp = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	count = 1;
	while(count && !ft_strchr(str, '\n'))
	{
		count = read(fd, tmp, BUFFER_SIZE);
		if (count == -1)
		{
			free(tmp);
			return(NULL);
		}
		tmp[count] = '\0';
		str = ft_strjoin(str, tmp);
	}
	free (tmp);
	return(str);
}

char *ft_save_line(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	if (!str[i])
		return(NULL);
	i = ft_strlen(str);
	j = 0;
	tmp = malloc (sizeof(char) * i + 1);
	if (!tmp)
		return (NULL);
	while(str[j] != '\n' && str[j] != '\0')
	{
		tmp[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[j] = '\0';
	return(tmp);
}

char *ft_save_remaining(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while(str[i] != '\n' && str[i] != '\0')
		i++;
	tmp = malloc (sizeof(char) * (ft_strlen(str) - i) + 1);
	if (!tmp)
	{
		free(tmp);
		return(NULL);
	}
	if (str[i] == '\n')
		i++;
	while(str[i] != '\0')
	{
		tmp[j] = str[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	free(str);
	return(tmp);
}

char *get_next_line(int fd)
{
	static char *buff;
	char *str;

	if (fd < 0 || fd > 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = ft_read_save(fd, buff);
	if (!buff || buff[0] == '\0')
	{
		if (buff)
			free(buff);
		buff = NULL;
		return(NULL);
	}
	str = ft_save_line(buff);
	buff = ft_save_remaining(buff);
	if(!buff)
	{
		free(buff);
		buff = NULL;
	}
	return (str);
}

int main ()
{
	int fd = open("file.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}

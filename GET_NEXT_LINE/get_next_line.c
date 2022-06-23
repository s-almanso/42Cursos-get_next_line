/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:19:48 by salmanso          #+#    #+#             */
/*   Updated: 2022/06/22 20:48:32 by salmanso         ###   ########.fr       */
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
	char *tmp;
	int count;

	count = 1;
	// Allocate memory for the string to save what we'll read
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);

	// Now we need to loop through the line till we can find a '\0'
	while(count && !ft_strchr(str, '\n'))
	{
		count = read(fd, tmp, BUFFER_SIZE);
		if (count == -1)
		{
			free(tmp);
			return(NULL);
		}
		tmp[count] = '\0';
		tmp = ft_strjoin(str, tmp);
	}
	free(tmp);
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
	// measure number of charachters inside the static var
	i = ft_strlen(str);
	j = 0;
	// allocate memory for it + '\0' + '\n'
	tmp = malloc (sizeof(char) * i + 1);
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	while(tmp[j] != '\n' && str[j] != '\0')
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

	while(str[i] != '\n' && str[i] != '\0')
		i++;
	j = 0;
	tmp = malloc (sizeof(char) * (ft_strlen(str) - i) + 2);
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
	// declare the static variable
	static char *static_str;
	char *str;

	// check if fd & Buffer are invalid
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	// call the function that will read and save from fd
	static_str = ft_read_save(fd, static_str);
	if(!static_str || static_str[0] == '\0')
	{
		if (str)
			free(static_str);
		static_str = NULL;
		return(NULL);
	}

	// call the function that will save the line into str from static_str
	str = ft_save_line(static_str);

	// call the function that will save after '\n', after the new line is read
	static_str = ft_save_remaining(static_str);
	if(!static_str)
	{
		free(static_str);
		static_str = NULL;
	}
	return (str);
}

int main ()
{
	int fd = open("file.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	free(line);
	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);
}

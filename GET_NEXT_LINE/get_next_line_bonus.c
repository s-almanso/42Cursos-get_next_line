/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:53:22 by salmanso          #+#    #+#             */
/*   Updated: 2022/06/26 20:39:22 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char *buff[OPEN_MAX];
	char *str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = ft_read_save(fd, buff[fd]);
	if (!buff[fd])
	{
		if (buff[fd])
			free(buff[fd]);
		buff[fd] = NULL;
		return(NULL);
	}
	str = ft_save_line(buff[fd]);
	buff[fd] = ft_save_remaining(buff[fd]);
	if(!buff[fd])
	{
		free(buff[fd]);
		buff[fd] = NULL;
	}
	return (str);
}

// #include <stdio.h> //printf library

// int main ()
// {
// 	int fd = open("file.txt", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	free(line);
// }

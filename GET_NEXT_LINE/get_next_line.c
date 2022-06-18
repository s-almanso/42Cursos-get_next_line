/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 20:19:48 by salmanso          #+#    #+#             */
/*   Updated: 2022/06/18 21:06:38 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> //printf library

char *get_next_line(int fd)
{
	// declare the static variable
	char	x;

	// check if fd & Buffer are invalid
	if ((fd = open("file_name", O_RDONLY)) == -1 || BUFFER == '\0')
		return (NULL);

	// call the function that will read fd


	return (x);
}
void ft_read_fd();
void ft_save_extra_read();

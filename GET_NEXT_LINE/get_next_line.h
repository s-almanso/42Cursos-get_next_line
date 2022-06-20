/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salmanso <salmanso@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:35:24 by salmanso          #+#    #+#             */
/*   Updated: 2022/06/20 21:47:30 by salmanso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 5

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char *get_next_line(int fd);
char *ft_read_save(int fd, char *str);
char *ft_save_line(char *str);
char *ft_save_remaining(char *str);


char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int	ft_strlen(const char *s);
int	ft_strlen_till_var(const char *s, int c);

#endif

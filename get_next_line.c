/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:40:14 by nparker           #+#    #+#             */
/*   Updated: 2018/12/20 15:30:32 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_error(int fd, char **line, char *str)
{
	if (fd < 0 || line == Null)
		return (-1);
	if (!(str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	return (0);
}

char	*read_line(int fd, char *str)
{
	int buff;
	int	read_fd;

	buff = [BUFF_SIZE + 1];
	while (read_fd = read(fd, buff, BUFF_SIZE) > 0)
	{
		buff[read_fd] = '\0'
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	char *str[64000];

}
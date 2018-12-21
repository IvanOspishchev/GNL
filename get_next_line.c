/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:40:14 by nparker           #+#    #+#             */
/*   Updated: 2018/12/21 16:41:52 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

int				check_error(int fd, char *line, char *str)
{
	if (fd < 0 || line == NULL)
		return (-1);
	if (!(str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	return (0);
}

char			*read_line(int fd, char *str)
{
	char		buff[BUFF_SIZE + 1];
	int			read_fd;

	while ((read_fd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_fd] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static char *str[65536];
	int			i;

	i = 0;
	if (check_error(fd, *line, *str) == -1)
		return (-1);
	if (!*str)
		*str = ft_strjoin(*line, *str);
	*str = read_line(fd, *str);
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (i == 0)
			*line = ft_strdup(" ");
		else
		{
			*line = ft_strsub(*str, 0, i);
			*str = str[i++];
		}
		return (1);
	}
	*line = ft_strdup(" ");
	return (0);
}

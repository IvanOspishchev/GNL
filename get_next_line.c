/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:40:14 by nparker           #+#    #+#             */
/*   Updated: 2018/12/24 13:43:02 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int				create_line(char **str, char **line, int fd, int read_fd)
{
	char		*tmp;
	int			len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (read_fd == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				read_line(const int fd, char **str, char *buff, int read_fd)
{
	char		*temp;

	while ((read_fd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_fd] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		temp = ft_strjoin(str[fd], buff);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (read_fd);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str[64536];
	char		buff[BUFF_SIZE + 1];
	int			read_fd;

	read_fd = 0;
	if (fd == -1 || line == NULL)
		return (-1);
	if (read_line(fd, str, buff, read_fd) < 0)
		return (-1);
	if (read_fd < 0)
		return (-1);
	else if (read_fd == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (create_line(str, line, fd, read_fd));
}

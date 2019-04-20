/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:59:04 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/03/04 22:28:56 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	getchrine(int fd, char *t[256], char **line)
{
	int i;

	i = 0;
	while (t[fd][i] != '\n' && t[fd][i] != '\0')
		i++;
	if (ft_strlen(t[fd]))
	{
		if (t[fd][i] == '\0')
		{
			*line = ft_strdup(t[fd]);
			t[fd] = t[fd] + i;
			return (1);
		}
		t[fd][i++] = '\0';
		*line = ft_strdup(t[fd]);
		t[fd] = t[fd] + i;
		return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*t[256];

	if (fd < 0 || !line || BUFF_SIZE < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (t[fd] == NULL)
		t[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		t[fd] = ft_strjoin(t[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (getchrine(fd, t, line));
}

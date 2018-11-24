/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 21:04:41 by viwade            #+#    #+#             */
/*   Updated: 2018/11/23 19:07:46 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int
	modify(char *b)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = BUFF_SIZE;
	while (n--)
		if ((b[i] *= !(b[i] == '\n')))
			break ;
		else
			++i;
	return (i);
}

int
	get_next_line(const int fd, char **line)
{
	int			i;
	static int	bytes;
	static int	pfd;
	char		*buf;
	char		*tmp;

	bytes *= fd == pfd;
	pfd = fd;
	i = 0;
	buf = (char *)ft_memalloc(BUFF_SIZE);
	while (0 < (bytes = (int)read(fd, (void *)buf, (size_t)BUFF_SIZE)))
	{
		++i;
		tmp = ft_strnew(BUFF_SIZE * i + 1);
		if (i > 1)
			tmp = ft_strcat(tmp, line[0]);
		free (line[0]);
		ft_strncat(tmp, buf, modify(buf));
		line[0] = ft_strdup(tmp);
		free(tmp);
	}
	free(buf);
	if (bytes == -1)
		return (-1);
	return (1);
}

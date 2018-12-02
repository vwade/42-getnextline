/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 21:04:41 by viwade            #+#    #+#             */
/*   Updated: 2018/12/01 18:28:13 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int
	readline(t_file *file, int fd, char **line)
{
	long int	nb;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;

	file->str = (file->str) ? file->str : ft_strnew(0);
	while ((nb = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nb] = 0;
		tmp = file->str;
		file->str = ft_strjoin(tmp, buf);
		free(tmp);
	}
	if ((tmp = ft_strchr(&file->str[file->ndx], '\n')))
		file->len = (size_t)(tmp - &file->str[file->ndx]);
	else
		file->len = ft_strlen(&file->str[file->ndx]);
	line[0] = ft_strsub(file->str, (unsigned int)file->ndx, file->len);
	file->ndx += (tmp) ? file->len + 1 : file->len;
	return (!!tmp);
}

/*
**	COMMENTS MAY GO HERE
*/

int
	get_next_line(const int fd, char **line)
{
	static t_file	file[FD_LIMIT];
	
	if (fd < 0 || fd > FD_LIMIT - 1 || !line || read(fd, 0, 0) == -1)
		return (-1);
	return (readline(&file[fd], fd, line));
}

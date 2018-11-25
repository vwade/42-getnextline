/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 21:04:41 by viwade            #+#    #+#             */
/*   Updated: 2018/11/25 10:49:18 by viwade           ###   ########.fr       */
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

static int
	readline(t_file *file, int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	if ((file->offset = read(fd, buf, 0)) == -1)
		return (-1);
	while ((file->offset = read(fd, buf, BUFF_SIZE)) > )
	{
		tmp = file->str;
		file->str = ft_strjoin(tmp, buf);
		file->len = ft_strlen(file->str);
		free(tmp);
		if ((tmp = ft_strchr(file->str, '\n')))
			if ((file->offset++))
				break ;
	}
	free(buf);
	line[0] = ft_strsub(file->str, tmp - file->str, file->len);
	line[0][file->len] = 0;
	if (file->offset)
		return (1);
	return (0);
}

/*
**	COMMENTS MAY GO HERE
*/

int
	get_next_line(const int fd, char **line)
{
	static t_file	*file[FD_LIMIT];
	int				ret;

	if (fd < 0 || fd > FD_LIMIT - 1 || !line)
		return (-1);
	ret = readline(file[fd], fd, line);
	return (ret);
}
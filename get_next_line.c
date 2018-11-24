/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 21:04:41 by viwade            #+#    #+#             */
/*   Updated: 2018/11/24 07:46:07 by viwade           ###   ########.fr       */
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
	readline(t_file **file, char **line, int fd)
{
	;
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
	
}
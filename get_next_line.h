/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 21:04:41 by viwade            #+#    #+#             */
/*   Updated: 2018/11/26 17:57:54 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define FD_LIMIT 8192
# define BUFF_SIZE 42

# include "libft/libft.h"
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_file
{
	int		ndx;
	char	*str;
	int		len;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif

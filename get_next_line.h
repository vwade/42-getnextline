/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viwade <viwade@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 21:04:41 by viwade            #+#    #+#             */
/*   Updated: 2018/11/24 06:58:25 by viwade           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42
# define FD_LIMIT 4864

# include "libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>

typedef struct	s_file
{
	int		offset;
	char	*str;
	int		len;
}				t_file;

int				get_next_line(const int fd, char **line);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 12:25:54 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/06/24 21:27:38 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static t_gnl	gnl;
	ssize_t			num_bytes;
	char			*buff;

	if (!gnl.endln && (gnl.tmp = gnl.str))
		gnl.endln = gnl.str;
	CHECK_ERROR(fd);
	CHECK((buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))));
	while ((num_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		ft_memcpy(gnl.endln, buff, num_bytes);
		gnl.endln += num_bytes;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	CHECK_ERROR(num_bytes);
	CHECK((*line = ft_strchrdup(gnl.tmp, '\n')));
	if (num_bytes < BUFFER_SIZE && !ft_charlen(gnl.tmp, '\0'))
		return (0);
	return (move_tmp_point(&gnl));
}

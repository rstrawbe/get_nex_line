/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 12:25:00 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/06/24 21:43:29 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# ifndef MEM_SIZE
#  define MEM_SIZE 100000000
# endif

typedef struct	s_gnl
{
	char		str[MEM_SIZE];
	char		*endln;
	char		*tmp;
}				t_gnl;

int				get_next_line(int fd, char **line);
int				move_tmp_point(t_gnl *gnl);
char			*ft_strchrdup(const char *s1, char c);
char			*ft_strchr(const char *s, int c);
size_t			ft_charlen(char const *s, char c);
void			*ft_memcpy(void *dest, const void *src, size_t n);

# define CHECK(x) if (!x) return (-1)
# define CHECK_ERROR(x) if (x < 0) return (-1)
#endif

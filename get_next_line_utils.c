/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstrawbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 12:26:42 by rstrawbe          #+#    #+#             */
/*   Updated: 2020/06/28 19:30:55 by rstrawbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		move_tmp_point(t_gnl *gnl)
{
	char			*tmp;

	if ((tmp = ft_strchr(gnl->tmp, '\n')) != NULL)
	{
		gnl->tmp = tmp + 1;
		return (1);
	}
	else
	{
		gnl->tmp = ft_strchr(gnl->tmp, '\0');
		return (0);
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d_tmp;
	unsigned char	*s_tmp;

	d_tmp = (unsigned char *)dest;
	s_tmp = (unsigned char *)src;
	while (n--)
		*d_tmp++ = *s_tmp++;
	return (dest);
}

size_t	ft_charlen(char const *s, char c)
{
	size_t		i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0' && s[i] != c)
			i++;
		return (i);
	}
	return (0);
}

char	*ft_strchrdup(const char *s1, char c)
{
	char		*dst;
	size_t		len;

	len = ft_charlen(s1, c);
	if (!(dst = (char *)malloc(sizeof(*s1) * (len + 1))))
		return (NULL);
	ft_memcpy(dst, s1, len);
	dst[len] = '\0';
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	char	*pt;

	pt = (char *)s;
	while (*pt)
	{
		if (*pt == (char)c)
			return (pt);
		pt++;
	}
	if (c == 0)
		return (pt);
	return (NULL);
}

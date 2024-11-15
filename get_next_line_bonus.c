/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbarret <tbarret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:29:43 by tbarret           #+#    #+#             */
/*   Updated: 2024/03/09 12:52:52 by tbarret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gen_buffer(char *s, int fd)
{
	char	*b;
	int		r;

	r = 1;
	b = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!b)
		return (0);
	while (r != 0 && !ft_strchr(s, '\n'))
	{
		r = read(fd, b, BUFFER_SIZE);
		if (r == -1)
		{
			free(b);
			return (0);
		}
		b[r] = 0;
		s = ft_strjoin(s, b);
	}
	free(b);
	return (s);
}

char	*gen_line(char *s)
{
	int		i;
	char	*r;

	if (!s[0])
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	r = (char *)malloc(sizeof(char) * (i + 2));
	if (!r)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		r[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		r[i] = s[i];
		i++;
	}
	r[i] = 0;
	return (r);
}

char	*next_buffer(char *s)
{
	int			i;
	int			j;
	char		*r;

	i = 0;
	while (s[i] && s[i] != '\n')
			i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	r = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!r)
		return (0);
	i++;
	j = 0;
	while (s[i])
	r[j++] = s[i++];
	r[j] = '\0';
	free(s);
	return (r);
}

char	*get_next_line(int fd)
{
	static char		*s[99999];
	char			*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	s[fd] = gen_buffer(s[fd], fd);
	if (!s[fd])
		return (0);
	l = gen_line(s[fd]);
	s[fd] = next_buffer(s[fd]);
	return (l);
}

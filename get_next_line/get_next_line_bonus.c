/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 11:02:35 by eablak            #+#    #+#             */
/*   Updated: 2022/10/27 16:53:34 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(int fd, char *all_line)
{
	char	*buf;
	int		return_read;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	return_read = 1;
	while ((!ft_strchr(all_line, '\n')) && return_read != 0)
	{
		return_read = read(fd, buf, BUFFER_SIZE);
		if (return_read == -1)
		{
			free (buf);
			return (0);
		}
		buf[return_read] = '\0';
		all_line = ft_strjoin(all_line, buf);
	}
	free(buf);
	return (all_line);
}

char	*get_next_line(int fd)
{
	static char	*all_line[4096];
	char		*wanted;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	all_line[fd] = ft_get_line(fd, all_line[fd]);
	if (!all_line[fd])
		return (NULL);
	wanted = ft_bring(all_line[fd]);
	all_line[fd] = ft_take_rest(all_line[fd]);
	return (wanted);
}

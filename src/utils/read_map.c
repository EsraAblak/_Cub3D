/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:17:40 by eablak            #+#    #+#             */
/*   Updated: 2023/06/05 16:17:43 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_map_started(char *all_line, int start, int end)
{
	int	keep_start;
	int	flag;

	keep_start = start;
	while (start < end)
	{
		if (!(all_line[start] == '1' || all_line[start] == ' '
				|| all_line[start] == '\n'))
			return (0);
		start++;
	}
	start = keep_start;
	flag = 0;
	while (start < end)
	{
		if (all_line[start] == '1')
			flag = 1;
		start++;
	}
	if (flag)
		return (1);
	return (0);
}

void	find_map(char *all_line, int start, t_map *map)
{
	int	len;
	int	i;

	len = ft_strlen(all_line);
	map->c_map = malloc(sizeof(char) * (len - start + 1));
	i = 0;
	while (all_line[start])
	{
		map->c_map[i] = all_line[start];
		start++;
		i++;
	}
	map->c_map[i] = '\0';
}

char	*read_file(int fd)
{
	char	*line;
	char	*all_line;

	all_line = NULL;
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		all_line = ft_g_strjoin(all_line, line);
		if (line != NULL)
			free(line);
	}
	return (all_line);
}

char	**read_map(char *map, t_map *_map)
{
	char	*all_line;
	int		fd;
	char	**all_map;

	all_line = NULL;
	fd = open(map, O_RDWR);
	if (fd < 0)
	{
		printf("Error\n");
		return (NULL);
	}
	all_line = read_file(fd);
	if (all_line == NULL)
		return (NULL);
	close(fd);
	map_start_index(all_line, _map);
	all_map = ft_split(all_line, '\n');
	free(all_line);
	return (all_map);
}

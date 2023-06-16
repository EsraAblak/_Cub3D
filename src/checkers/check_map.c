/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:16:09 by eablak            #+#    #+#             */
/*   Updated: 2023/06/05 16:22:52 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_wall(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == '0')
				if (!check_location(map->map, i, j))
					safe_exit(map);
			j++;
		}
		i++;
	}
}

void	empty_line(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map->c_map[i])
	{
		if (map->c_map[i] == '\n' && map->c_map[i + 1] == '\n')
		{
			if (i + 1 == (int)ft_strlen(map->c_map) - 1)
				return ;
			j = i + 1;
			while (map->c_map[j] == '\n')
				j++;
			if (map->c_map[j] == '\0')
				return ;
			else
				safe_exit(map);
		}
		i++;
	}
}

void	map_pos(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (map->mmap[++i])
	{
		j = -1;
		while (map->mmap[i][++j])
		{
			if (map->mmap[i][j] == 'N' ||
				map->mmap[i][j] == 'E' ||
				map->mmap[i][j] == 'W' || map->mmap[i][j] == 'S')
			{
				map->map_x = j;
				map->map_y = i;
				return ;
			}
		}
	}
}

void	invalid_map(t_map *map, int y, int x)
{
	if (x < 0 || y < 0)
		return ;
	else if (y > double_ptr_len(map->mmap) - 1
		|| x > (int)ft_strlen(map->mmap[y]) - 1)
		return ;
	else if (map->mmap[y][x] == 'k')
		return ;
	else if (map->mmap[y][x] == ' ')
		return ;
	map->mmap[y][x] = 'k';
	invalid_map(map, y, x + 1);
	invalid_map(map, y, x - 1);
	invalid_map(map, y + 1, x);
	invalid_map(map, y - 1, x);
}

void	check_map(t_map *map)
{
	check_wall(map);
	check_player(map);
	empty_line(map);
	map->mmap = ft_split(map->c_map, '\n');
	map_pos(map);
	invalid_map(map, map->map_y, map->map_x);
	check_invalid_map(map);
}

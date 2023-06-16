/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:20:19 by mmesum            #+#    #+#             */
/*   Updated: 2023/06/04 16:52:30 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_location(char **map, int i, int j)
{
	if (i - 1 < 0 || i + 1 > double_ptr_len(map) || j - 1 < 0 || j
		+ 1 > (int)ft_strlen(map[i]) - 1)
		return (0);
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || map[i][j - 1] == ' '
		|| map[i][j + 1] == ' ')
		return (0);
	return (1);
}

void	check_invalid_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->mmap[i])
	{
		j = 0;
		while (map->mmap[i][j])
		{
			if (map->mmap[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if (map->mmap[i][j] != 'k')
				safe_exit(map);
			j++;
		}
		i++;
	}
}

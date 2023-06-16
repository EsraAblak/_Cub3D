/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:16:21 by eablak            #+#    #+#             */
/*   Updated: 2023/06/05 16:16:25 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_invalid_char(t_map *map, int i, int j)
{
	if (map->map[i][j] != '1' && map->map[i][j] != '0' && map->map[i][j] != 'D'
		&& map->map[i][j] != 'N' && map->map[i][j] != 'S'
		&& map->map[i][j] != 'W' && map->map[i][j] != 'E'
		&& map->map[i][j] != ' ')
		safe_exit(map);
}

void	check_player(t_map *map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'W')
				count++;
			check_invalid_char(map, i, j);
			j++;
		}
		i++;
	}
	if (count != 1)
		safe_exit(map);
}

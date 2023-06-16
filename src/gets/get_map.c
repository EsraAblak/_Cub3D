/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:36:48 by mmesum            #+#    #+#             */
/*   Updated: 2023/06/05 15:33:50 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	find_i(char **all_map)
{
	int	i;

	i = 0;
	while (all_map[i])
	{
		if (get_type(all_map[i]) != UNKNOWN)
			i++;
		else if (is_color(all_map[i]) == 1)
			i++;
		else if (check_str(all_map[i]) == 0)
			i++;
		else
			break ;
	}
	return (i);
}

void	check_empty_line(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		if (is_empty(map->map[i]) == 1)
			safe_exit(map);
		i++;
	}
}

void	get_map(char **all_map, int i, t_map *map)
{
	int	len;
	int	j;

	len = 0;
	j = 0;
	i = find_i(all_map);
	map->map = &all_map[i];
	while (all_map[i])
	{
		len++;
		i++;
	}
	map->map = malloc(sizeof(char *) * (len + 1));
	i = i - len;
	while (all_map[i])
		map->map[j++] = ft_strdup(all_map[i++]);
	map->map[j] = NULL;
}

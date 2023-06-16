/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_index_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:17:25 by eablak            #+#    #+#             */
/*   Updated: 2023/06/05 16:17:27 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_values(int *i, int *start, int *end, int *count)
{
	*i = 0;
	*start = 0;
	*end = 0;
	*count = 0;
}

int	keep_start_end(char *all_line, int start, int end, t_map *map)
{
	map->c_map = NULL;
	if (start < end)
	{
		if (is_map_started(all_line, start, end) == 1)
		{
			map->start_index = start;
			find_map(all_line, start, map);
			return (1);
		}
	}
	return (0);
}

void	map_start_index(char *all_line, t_map *map)
{
	int	i;
	int	start;
	int	end;
	int	count;

	if (all_line == NULL)
		return ;
	init_values(&i, &start, &end, &count);
	while (all_line[i])
	{
		if (i == 0 && count == 0)
			start = i;
		if (all_line[i] == '\n')
		{
			count++;
			end = i;
		}
		if (keep_start_end(all_line, start, end, map))
			break ;
		if (all_line[i] == '\n' && count != 0)
			start = i + 1;
		i++;
	}
}

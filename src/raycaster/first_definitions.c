/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_definitions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:17:04 by eablak            #+#    #+#             */
/*   Updated: 2023/06/05 16:20:28 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	find_pos(t_all *all)
{
	int	i;
	int	j;

	i = -1;
	while (all->map->map[++i])
	{
		j = -1;
		while (all->map->map[i][++j])
		{
			if (all->map->map[i][j] == 'N' ||
				all->map->map[i][j] == 'E' ||
				all->map->map[i][j] == 'W' || all->map->map[i][j] == 'S')
			{
				all->rc->pos_x = j;
				all->rc->pos_y = i;
				return ;
			}
		}
	}
}

void	find_dir(t_all *all)
{
	int	x;
	int	y;

	x = all->rc->pos_x;
	y = all->rc->pos_y;
	if (all->map->map[y][x] == 'N')
	{
		all->rc->dir_x = -1;
		all->rc->dir_y = 0;
	}
	else if (all->map->map[y][x] == 'S')
	{
		all->rc->dir_x = 1;
		all->rc->dir_y = 0;
	}
	else if (all->map->map[y][x] == 'W')
	{
		all->rc->dir_x = 0;
		all->rc->dir_y = 1;
	}
	else if (all->map->map[y][x] == 'E')
	{
		all->rc->dir_x = 0;
		all->rc->dir_y = -1;
	}
}

void	find_plane(t_all *all)
{
	if (all->rc->dir_x == 0 && all->rc->dir_y == 1)
	{
		all->rc->plane_x = 0.66;
		all->rc->plane_y = 0;
	}
	else if (all->rc->dir_x == 0 && all->rc->dir_y == -1)
	{
		all->rc->plane_x = -0.66;
		all->rc->plane_y = 0;
	}
	else if (all->rc->dir_x == 1 && all->rc->dir_y == 0)
	{
		all->rc->plane_x = 0;
		all->rc->plane_y = 0.66;
	}
	else if (all->rc->dir_x == -1 && all->rc->dir_y == 0)
	{
		all->rc->plane_x = 0;
		all->rc->plane_y = -0.66;
	}
}

t_all	*first_definitions(t_map *map)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	all->rc = malloc(sizeof(t_rc));
	all->mlx = malloc(sizeof(t_mlx));
	all->map = map;
	all->rc->window_height = 1080;
	all->rc->window_width = 1920;
	find_pos(all);
	find_dir(all);
	find_plane(all);
	return (all);
}

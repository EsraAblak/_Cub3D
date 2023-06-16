/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:36:29 by mmesum            #+#    #+#             */
/*   Updated: 2023/06/05 15:40:30 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	intial_value(t_help *help)
{
	help->i = 0;
	help->no = 0;
	help->so = 0;
	help->we = 0;
	help->ea = 0;
	help->d = 0;
}

void	images_utils(t_map *map, t_help *help)
{
	if (map->image[help->i].type == NO)
		help->no++;
	if (map->image[help->i].type == SO)
		help->so++;
	if (map->image[help->i].type == WE)
		help->we++;
	if (map->image[help->i].type == EA)
		help->ea++;
}

void	check_images(t_map *map)
{
	t_help	*help;

	help = malloc(sizeof(t_help));
	intial_value(help);
	while (help->i < 4)
	{
		help->fd = open(map->image[help->i].path, O_RDONLY);
		if (map->image[help->i].type == UNKNOWN || help->fd <= 0
			|| map->image[help->i].path == NULL)
		{
			if (help->fd > 0)
				close(help->fd);
			free(help);
			safe_exit(map);
		}
		images_utils(map, help);
		help->i++;
	}
	close(help->fd);
	if (help->no != 1 || help->so != 1 || help->we != 1 || help->ea != 1)
	{
		free(help);
		safe_exit(map);
	}
	free(help);
}

void	check_colors(t_map *map)
{
	if (map->ceiling_color == -1 || map->floor_color == -1)
		safe_exit(map);
}

void	checkers(t_map *map)
{
	check_images(map);
	check_colors(map);
	check_map(map);
}

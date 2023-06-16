/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_directions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:16:47 by eablak            #+#    #+#             */
/*   Updated: 2023/06/05 16:16:50 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_direction	get_type(char *str)
{
	while (*str == ' ' && *str)
		str++;
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		return (NO);
	if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		return (SO);
	if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		return (WE);
	if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		return (EA);
	return (UNKNOWN);
}

char	*get_path(char *str)
{
	char	**ret;
	char	*val;

	ret = ft_split(str, ' ');
	if (ret[2] != NULL)
	{
		free_double_pointer(ret);
		return (NULL);
	}
	if (ret[1] != NULL)
	{
		val = ft_strdup(ret[1]);
		free_double_pointer(ret);
		return (val);
	}
	free_double_pointer(ret);
	return (NULL);
}

void	get_images(char **all_map, t_map *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	map->image = malloc(sizeof(t_image) * 4);
	while (all_map[i] != NULL && count < 4)
	{
		if (check_str(all_map[i]) == 1)
		{
			map->image[count].type = get_type(all_map[i]);
			if (map->image[count].type != UNKNOWN)
			{
				map->image[count].path = get_path(all_map[i]);
				count++;
			}
		}
		i++;
	}
	get_colors(all_map, i, map);
}

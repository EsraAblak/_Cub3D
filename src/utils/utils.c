/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:47:20 by mmesum            #+#    #+#             */
/*   Updated: 2023/06/05 15:36:15 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	free_double_pointer(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_cub(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (arg[len - 1] == 'b' && arg[len - 2] == 'u' && arg[len - 3] == 'c'
		&& arg[len - 4] == '.')
		return (1);
	return (0);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->image != NULL)
	{
		while (i < 4)
		{
			if (map->image[i].type != UNKNOWN)
				free(map->image[i].path);
			i++;
		}
		free(map->image);
	}
	if (map->map != NULL)
		free_double_pointer(map->map);
	if (map->c_map != NULL)
		free(map->c_map);
	if (map->mmap != NULL)
		free_double_pointer(map->mmap);
	free(map);
}

int	double_ptr_len(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

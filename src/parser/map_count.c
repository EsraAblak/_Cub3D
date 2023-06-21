/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:00:04 by eablak            #+#    #+#             */
/*   Updated: 2023/06/21 11:00:05 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_map_end(t_cub *cub, int i)
{
	while (cub->map_reference[i] != '\0')
	{
		if (cub->map_reference[i] != ' ' && cub->map_reference[i] != '\t'
			&& cub->map_reference[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	map_count_loop(t_cub *cub, int *i, int *flag)
{
	while (cub->map_reference[*i] && cub->map_reference[*i] != '\n')
	{
		if (cub->map_reference[*i] == '1' || cub->map_reference[*i] == '0'
			|| cub->map_reference[*i] == 'N' || cub->map_reference[*i] == 'S'
			|| cub->map_reference[*i] == 'W' || cub->map_reference[*i] == 'E')
		{
			*flag = 1;
			break ;
		}
		if (cub->map_reference[*i])
			*i += 1;
	}
}

int	map_count_main_loop(t_cub *cub, int i, int flag)
{
	while (cub->map_reference[i])
	{
		if (cub->map_reference[i] == '\n')
		{
			i += 1;
			if (cub->map_reference[i] == '\n')
			{
				if (check_map_end(cub, i))
					return (0);
				return (1);
			}
			flag = 0;
			map_count_loop(cub, &i, &flag);
			if (flag == 0)
				return (1);
		}
		if (cub->map_reference[i])
			i += 1;
	}
	return (0);
}

int	map_count(t_cub *cub)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (cub->map_reference[i])
	{
		if (cub->map_reference[i] == '1' || cub->map_reference[i] == '0')
			break ;
		if (cub->map_reference[i])
			i++;
	}
	if (map_count_main_loop(cub, i, flag))
		return (1);
	return (0);
}

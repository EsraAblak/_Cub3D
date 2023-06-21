/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part_checkers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:58:12 by eablak            #+#    #+#             */
/*   Updated: 2023/06/21 11:07:48 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	map_character(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map_reference[i])
	{
		if (cub->map_reference[i] != '0' && cub->map_reference[i] != '1'
			&& cub->map_reference[i] != ' ' && cub->map_reference[i] != '\n'
			&& cub->map_reference[i] != 'N' && cub->map_reference[i] != 'S'
			&& cub->map_reference[i] != 'W' && cub->map_reference[i] != 'E'
			&& cub->map_reference[i] != '\t' && cub->map_reference[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	zero_location(char **split, int i, int j)
{
	if (i - 1 < 0 || i + 1 >= double_pointer_len(split) || j - 1 < 0 || j
		+ 1 > (int)ft_strlen(split[i]) - 1)
		return (0);
	if ((int)ft_strlen(split[i - 1]) < j)
		return (0);
	if (split[i - 1][j] == ' ' || split[i + 1][j] == ' ' || split[i][j
		- 1] == ' ' || split[i][j + 1] == ' ')
		return (0);
	if (split[i - 1][j] == '\0' || split[i + 1][j] == '\0' || split[i][j
		- 1] == '\0' || split[i][j + 1] == '\0')
		return (0);
	return (1);
}

int	wall_check(t_cub *cub)
{
	char	**split;
	int		i;
	int		j;

	split = ft_split(cub->map_reference, '\n');
	i = 0;
	j = 0;
	while (split[i] != NULL)
	{
		j = 0;
		while (split[i][j] != '\0')
		{
			if (split[i][j] == '0' || split[i][j] == 'N' || split[i][j] == 'S'
				|| split[i][j] == 'W' || split[i][j] == 'E')
				if (check_zero_location(split, i, j))
					return (1);
			j++;
		}
		i++;
	}
	free_double_pointer(split);
	return (0);
}

int	player_count(t_cub *cub)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cub->map_reference[i])
	{
		if (cub->map_reference[i] == 'N' || cub->map_reference[i] == 'W'
			|| cub->map_reference[i] == 'S' || cub->map_reference[i] == 'E')
			count++;
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

void	second_part_checkers(t_cub *cub)
{
	if (map_character(cub) || map_count(cub) || wall_check(cub)
		|| player_count(cub))
	{
		printf("Error\n");
		if (cub->map_reference != NULL)
			free(cub->map_reference);
		free_first_part(cub);
		exit(1);
	}
}

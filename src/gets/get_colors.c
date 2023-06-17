/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:16:32 by eablak            #+#    #+#             */
/*   Updated: 2023/06/05 16:16:36 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// int	is_num(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if (ft_isdigit(str[i]) == 0)
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }

// int	check_color(char *num)
// {
// 	int	nbr;

// 	if (is_num(num))
// 	{
// 		nbr = ft_atoi(num);
// 		if (nbr < 0 || nbr > 255)
// 			return (-1);
// 	}
// 	else
// 		return (-1);
// 	return (nbr);
// }

// int	convert_int(char *str)
// {
// 	char	**split;
// 	int		red;
// 	int		blue;
// 	int		green;
// 	int		rgb_int;

// 	split = ft_split(str, ',');
// 	red = check_color(split[0]);
// 	green = check_color(split[1]);
// 	blue = check_color(split[2]);
// 	if (red == -1 || green == -1 || blue == -1)
// 	{
// 		free_double_pointer(split);
// 		return (-1);
// 	}
// 	rgb_int = (red << 16) + (green << 8) + blue;
// 	free_double_pointer(split);
// 	return (rgb_int);
// }

// void	get_color(t_map *map, char *str)
// {
// 	char	**split;

// 	split = ft_split(str, ' ');
// 	if (split[2] != NULL)
// 	{
// 		free_double_pointer(split);
// 		safe_exit(map);
// 	}
// 	if (split[0][0] == 'F' && split[0][1] == '\0')
// 		map->floor_color = convert_int(split[1]);
// 	if (split[0][0] == 'C' && split[0][1] == '\0')
// 		map->ceiling_color = convert_int(split[1]);
// 	free_double_pointer(split);
// }

void	get_colors(char **all_map, int i, t_map *map)
{
	// int	count;

	// map->ceiling_color = -1;
	// map->floor_color = -1;
	// count = 0;
	// i = 0;
	// while (all_map[i] != NULL && count < 6)
	// {
	// 	if (check_str(all_map[i]) == 1 && is_color(all_map[i]))
	// 	{
	// 		get_color(map, all_map[i]);
	// 		count++;
	// 	}
	// 	i++;
	// }
	(void) map;
	get_map(all_map, i, map);
}

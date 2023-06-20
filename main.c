/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:18:27 by eablak            #+#    #+#             */
/*   Updated: 2023/06/05 16:18:28 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*get_map_struct(char *arg)
{
	t_map	*map;
	char	**all_map;

	map = malloc(sizeof(t_map));
	map->image = NULL;
	map->map = NULL;
	all_map = read_map(arg, map);
	if (all_map == NULL)
	{
		free(map);
		printf("Error\n");
		exit(1);
	}
	get_images(all_map, map);
	free_double_pointer(all_map);
	return (map); 
}

int	main(int ac, char **av)
{
	// t_map	*map;
	// // t_all	*all;

	if (ac != 2 || !check_cub(av[1]))
		return (1);
	// map = get_map_struct(av[1]);
	// map->mmap = NULL;
	// checkers(map);
	// // all = first_definitions(map);
	// // _mlx(all); 
	// return (0);

	t_cub *cub;
	t_all *all;
    cub = malloc(sizeof(t_cub));
	get_cub(av[1], cub);
	divide_cub(cub);
	all = first_definitions(cub);
	_mlx(all);
}

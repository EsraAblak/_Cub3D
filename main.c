/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:18:27 by eablak            #+#    #+#             */
/*   Updated: 2023/06/20 12:27:53 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2 || !check_cub(av[1]))
		return (1);
	t_cub *cub;
	t_all *all;
    cub = malloc(sizeof(t_cub));
	get_cub(av[1], cub);
	divide_cub(cub);
	all = first_definitions(cub);
	_mlx(all);
	return(0);
}

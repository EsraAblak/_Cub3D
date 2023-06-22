/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:18:27 by eablak            #+#    #+#             */
/*   Updated: 2023/06/22 14:29:56 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_cub(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (arg[len - 1] == 'b' && arg[len - 2] == 'u' && arg[len - 3] == 'c'
		&& arg[len - 4] == '.')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	*cub;
	t_all	*all;

	if (ac != 2 || !check_cub(av[1]))
		return (1);
	cub = malloc(sizeof(t_cub));
	get_cub(av[1], cub);
	divide_cub(cub);
	all = first_definitions(cub);
	_mlx(all);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:45:51 by mmesum            #+#    #+#             */
/*   Updated: 2023/06/05 15:35:34 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	find_max_len(char **map)
{
	int	i;
	int	max_len;

	i = 0;
	max_len = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > max_len)
			max_len = ft_strlen(map[i]);
		i++;
	}
	return (max_len);
}

void	free_all(t_all *all)
{
	free(all->rc);
	free(all->mlx);
	free(all->cub);
	free(all);
}

int	ft_close(t_all *all)
{
	free_all(all);
	exit(1);
	return (1);
}

int	is_empty(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			k++;
		i++;
	}
	if (k == (int)ft_strlen(str))
		return (1);
	return (0);
}

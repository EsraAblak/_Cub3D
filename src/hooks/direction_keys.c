/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_keys.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:39:32 by mmesum            #+#    #+#             */
/*   Updated: 2023/06/05 16:20:28 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	handle_right(t_all *all)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->rc->dir_x;
	all->rc->dir_x = all->rc->dir_x * cos(-all->rc->rot_speed) - all->rc->dir_y
		* sin(-all->rc->rot_speed);
	all->rc->dir_y = old_dir_x * sin(-all->rc->rot_speed) + all->rc->dir_y
		* cos(-all->rc->rot_speed);
	old_plane_x = all->rc->plane_x;
	all->rc->plane_x = all->rc->plane_x * cos(-all->rc->rot_speed)
		- all->rc->plane_y * sin(-all->rc->rot_speed);
	all->rc->plane_y = old_plane_x * sin(-all->rc->rot_speed) + all->rc->plane_y
		* cos(-all->rc->rot_speed);
}

void	handle_left(t_all *all)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = all->rc->dir_x;
	all->rc->dir_x = all->rc->dir_x * cos(all->rc->rot_speed) - all->rc->dir_y
		* sin(all->rc->rot_speed);
	all->rc->dir_y = old_dir_x * sin(all->rc->rot_speed) + all->rc->dir_y
		* cos(all->rc->rot_speed);
	old_plane_x = all->rc->plane_x;
	all->rc->plane_x = all->rc->plane_x * cos(all->rc->rot_speed)
		- all->rc->plane_y * sin(all->rc->rot_speed);
	all->rc->plane_y = old_plane_x * sin(all->rc->rot_speed) + all->rc->plane_y
		* cos(all->rc->rot_speed);
}

int	check_direction(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (all->cub->double_ptr_map[i])
	{
		j = 0;
		while (all->cub->double_ptr_map[i][j] != '\0')
		{
			if (all->cub->double_ptr_map[i][j] == 'N' || all->cub->double_ptr_map[i][j] == 'S')
				return (1);
			else if (all->cub->double_ptr_map[i][j] == 'E' || all->cub->double_ptr_map[i][j] == 'W')
				return (2);
			j++;
		}
		i++;
	}
	return (-1);
}

void	handle_directions(t_all *all, int keycode)
{
	int	type;

	type = check_direction(all);
	if (type == -1)
		return ;
	if (type == 2)
	{
		if (keycode == RIGHT_ARROW_KEY)
			handle_right(all);
		else if (keycode == LEFT_ARROW_KEY)
			handle_left(all);
	}
	else
	{
		if (keycode == RIGHT_ARROW_KEY)
			handle_left(all);
		else if (keycode == LEFT_ARROW_KEY)
			handle_right(all);
	}
}

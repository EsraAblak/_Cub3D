/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:55:42 by mmesum            #+#    #+#             */
/*   Updated: 2023/06/21 10:57:11 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_keys_horizontal(t_all *all)
{
	if (all->rc->a_key == 1)
	{
		if (all->cub->double_ptr_map[(int)(all->rc->pos_y - all->rc->plane_y
				* all->rc->move_speed)][(int)(all->rc->pos_x - all->rc->plane_x
				* all->rc->move_speed)] != '1')
		{
			all->rc->pos_x -= all->rc->plane_x * all->rc->move_speed;
			all->rc->pos_y -= all->rc->plane_y * all->rc->move_speed;
		}
	}
	else if (all->rc->d_key == 1)
	{
		if (all->cub->double_ptr_map[(int)(all->rc->pos_y + all->rc->plane_y
				* all->rc->move_speed)][(int)(all->rc->pos_x + all->rc->plane_x
				* all->rc->move_speed)] != '1')
		{
			all->rc->pos_x += all->rc->plane_x * all->rc->move_speed;
			all->rc->pos_y += all->rc->plane_y * all->rc->move_speed;
		}
	}
}

void	check_keys(t_all *all)
{
	if (all->rc->w_key == 1)
	{
		if (all->cub->double_ptr_map[(int)(all->rc->pos_y + all->rc->dir_y
				* all->rc->move_speed)][(int)(all->rc->pos_x + all->rc->dir_x
				* all->rc->move_speed)] != '1')
		{
			all->rc->pos_x += all->rc->dir_x * all->rc->move_speed;
			all->rc->pos_y += all->rc->dir_y * all->rc->move_speed;
		}
	}
	else if (all->rc->s_key == 1)
	{
		if (all->cub->double_ptr_map[(int)(all->rc->pos_y - all->rc->dir_y
				* all->rc->move_speed)][(int)(all->rc->pos_x - all->rc->dir_x
				* all->rc->move_speed)] != '1')
		{
			all->rc->pos_x -= all->rc->dir_x * all->rc->move_speed;
			all->rc->pos_y -= all->rc->dir_y * all->rc->move_speed;
		}
	}
	check_keys_horizontal(all);
}

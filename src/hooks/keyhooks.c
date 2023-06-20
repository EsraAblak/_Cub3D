/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:39:52 by mmesum            #+#    #+#             */
/*   Updated: 2023/06/05 16:20:28 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	handle_left_right_keys(t_all *all, int keycode)
{
	if (keycode == A_KEY)
	{
		if (all->cub->double_ptr_map[(int)(all->rc->pos_y - all->rc->plane_y
				* all->rc->move_speed)][(int)(all->rc->pos_x - all->rc->plane_x
				* all->rc->move_speed)] != '1')
		{
			all->rc->pos_x -= all->rc->plane_x * all->rc->move_speed;
			all->rc->pos_y -= all->rc->plane_y * all->rc->move_speed;
		}
	}
	else if (keycode == D_KEY)
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

void	move_keys(t_all *all, int keycode)
{
	if (keycode == W_KEY)
	{
		if (all->cub->double_ptr_map[(int)(all->rc->pos_y + all->rc->dir_y
				* all->rc->move_speed)][(int)(all->rc->pos_x + all->rc->dir_x
				* all->rc->move_speed)] != '1')
		{
			all->rc->pos_x += all->rc->dir_x * all->rc->move_speed;
			all->rc->pos_y += all->rc->dir_y * all->rc->move_speed;
		}
	}
	else if (keycode == S_KEY)
	{
		if (all->cub->double_ptr_map[(int)(all->rc->pos_y - all->rc->dir_y
				* all->rc->move_speed)][(int)(all->rc->pos_x - all->rc->dir_x
				* all->rc->move_speed)] != '1')
		{
			all->rc->pos_x -= all->rc->dir_x * all->rc->move_speed;
			all->rc->pos_y -= all->rc->dir_y * all->rc->move_speed;
		}
	}
	handle_left_right_keys(all, keycode);
}

int	key_pressed(int keycode, t_all *all)
{
	all->rc->move_speed = 0.1;
	all->rc->rot_speed = 0.1;
	move_keys(all, keycode);
	if (keycode == ESC_KEY)
	{
		mlx_clear_window(all->mlx->mlx_init, all->mlx->mlx_window);
		mlx_destroy_image(all->mlx->mlx_init, all->mlx->mlx_img);
		mlx_destroy_window(all->mlx->mlx_init, all->mlx->mlx_window);
		free_all(all);
		exit(0);
	}
	handle_directions(all, keycode);
	return (0);
}

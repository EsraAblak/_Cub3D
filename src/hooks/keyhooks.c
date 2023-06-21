/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:39:52 by mmesum            #+#    #+#             */
/*   Updated: 2023/06/20 14:28:45 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	handle_left_right_keys(t_all *all, int keycode)
{
	if (keycode == A_KEY)
		all->rc->a_key = 1;
	else if (keycode == D_KEY)
		all->rc->d_key = 1;
}

void	move_keys(t_all *all, int keycode)
{
	if (keycode == W_KEY)
		all->rc->w_key = 1;
	
	else if (keycode == S_KEY)
		all->rc->s_key = 1;
	
	handle_left_right_keys(all, keycode);
}

void	free_images(t_all *all)
{
	int	i;

	i = 0;
	while (i < 4)
		free(all->cub->image[i++].path);
	free(all->cub->image);
}

int	key_pressed(int keycode, t_all *all)
{
	all->rc->move_speed = 0.05;
	all->rc->rot_speed = 0.05;
	move_keys(all, keycode);
	if (keycode == ESC_KEY)
		game_exit(all);
	handle_directions(all, keycode);
	return (0);
}

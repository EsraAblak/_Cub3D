/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:17:10 by eablak            #+#    #+#             */
/*   Updated: 2023/06/20 19:20:21 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	pre_dda(t_all *all)
{
	if (all->rc->raydir_x < 0)
	{
		all->rc->step_x = -1;
		all->rc->sidedist_x = (all->rc->pos_x - all->rc->map_x)
			* all->rc->deltadist_x;
	}
	else
	{
		all->rc->step_x = 1;
		all->rc->sidedist_x = (all->rc->map_x + 1.0 - all->rc->pos_x)
			* all->rc->deltadist_x;
	}
	if (all->rc->raydir_y < 0)
	{
		all->rc->step_y = -1;
		all->rc->sidedist_y = (all->rc->pos_y - all->rc->map_y)
			* all->rc->deltadist_y;
	}
	else
	{
		all->rc->step_y = 1;
		all->rc->sidedist_y = (all->rc->map_y + 1.0 - all->rc->pos_y)
			* all->rc->deltadist_y;
	}
}

void	dda(t_all *all)
{
	all->rc->hit = 0;
	while (!all->rc->hit)
	{
		if (all->rc->sidedist_x < all->rc->sidedist_y)
		{
			all->rc->sidedist_x += all->rc->deltadist_x;
			all->rc->map_x += all->rc->step_x;
			all->rc->side = 0;
		}
		else
		{
			all->rc->sidedist_y += all->rc->deltadist_y;
			all->rc->map_y += all->rc->step_y;
			all->rc->side = 1;
		}
		if (all->cub->double_ptr_map[all->rc->map_y][all->rc->map_x] == '1')
			all->rc->hit = 1;
	}
}

void	draw_wall(t_all *all)
{
	if (all->rc->side == 0)
		all->rc->perpwall_dist = all->rc->sidedist_x - all->rc->deltadist_x;
	else
		all->rc->perpwall_dist = (all->rc->sidedist_y - all->rc->deltadist_y);
	all->rc->line_height = (int)(all->rc->window_height
			/ all->rc->perpwall_dist);
	all->rc->draw_start = -all->rc->line_height / 2 + all->rc->window_height
		/ 2;
	if (all->rc->draw_start < 0)
		all->rc->draw_start = 0;
	all->rc->draw_end = all->rc->line_height / 2 + all->rc->window_height / 2;
	if (all->rc->draw_end >= all->rc->window_height)
		all->rc->draw_end = all->rc->window_height - 1;
}
void	colored(t_all *all, int x)
{
	int	start;

	start = all->rc->draw_start;
	while (start < all->rc->draw_end)
	{
		all->rc->tex_pos += all->rc->tex_step;
		if (all->rc->side == 0 && all->rc->raydir_x > 0)
			all->mlx->mlx_img_addr[start * all->rc->window_width + x] = 0xFF0000;
		else if (all->rc->side == 0 && all->rc->raydir_x < 0)
			all->mlx->mlx_img_addr[start * all->rc->window_width  + x] = 0x0000FF;
		else if (all->rc->side == 1 && all->rc->raydir_x > 0)
			all->mlx->mlx_img_addr[start * all->rc->window_width  + x] = 0xFF00FF;
		else
			all->mlx->mlx_img_addr[start * all->rc->window_width  + x] = 0x00FF00;
		start++;
	}
}

void	ray_casting(t_all *all)
{
	int	x;

	x = 0;
	while (x < all->rc->window_width)
	{
		all->rc->camera_x = 2 * x / (double)all->rc->window_width - 1;
		all->rc->raydir_x = all->rc->dir_x + all->rc->plane_x
			* all->rc->camera_x;
		all->rc->raydir_y = all->rc->dir_y + all->rc->plane_y
			* all->rc->camera_x;
		all->rc->map_x = all->rc->pos_x;
		all->rc->map_y = all->rc->pos_y;
		all->rc->deltadist_x = fabs(1 / all->rc->raydir_x);
		all->rc->deltadist_y = fabs(1 / all->rc->raydir_y);
		pre_dda(all);
		dda(all);
		draw_wall(all);
		draw_images(all,x);

		x++;
	}
	mlx_put_image_to_window(all->mlx->mlx_init, all->mlx->mlx_window,
			all->mlx->mlx_img, 0, 0);
}

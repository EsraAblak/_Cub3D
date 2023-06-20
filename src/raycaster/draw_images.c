/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:41:48 by mmesum            #+#    #+#             */
/*   Updated: 2023/06/20 17:26:59 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	image_get_pixel(t_image *img, int x, int y)
{
	if (x < 0 || x > img->img_width || y < 0 || y > img->img_height)
		return (0);
	return (*((int *)(img->address + (y * img->line_length) + (x * 4))));
}

void	image_put_pixel(t_image *img, int x, t_all *all)
{
	int	texture_y;
	int	color;

	texture_y = (int)all->rc->tex_pos & (img->img_height - 1);
	color = image_get_pixel(img, all->rc->text_x, texture_y);
	(void)color;
	all->mlx->mlx_img_addr[all->rc->start * all->rc->window_width
		+ x] = color;
}

t_image	get_image(t_direction dir, t_all *all)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (all->cub->image[i].type == dir)
			return (all->cub->image[i]);
		i++;
	}
	return (all->cub->image[i]);
}

t_image	get_side_image(t_all *all)
{
	if (all->rc->side == 0 && all->rc->raydir_x > 0)
		return (get_image(SO, all));
	else if (all->rc->side == 0 && all->rc->raydir_x < 0)
		return (get_image(NO, all));
	else if (all->rc->side == 1 && all->rc->raydir_y > 0)
		return (get_image(WE, all));
	else
		return (get_image(EA, all));
}

void	draw_images(t_all *all, int x)
{
	t_image	hit_image;

	hit_image = get_side_image(all);
	if (all->rc->side == 0)
		all->rc->wall_x = all->rc->pos_y + all->rc->perpwall_dist
			* all->rc->raydir_y;
	else
		all->rc->wall_x = all->rc->pos_x + all->rc->perpwall_dist
			* all->rc->raydir_x;
	all->rc->wall_x -= floor((all->rc->wall_x));
	all->rc->text_x = (int)(all->rc->wall_x * (double)hit_image.img_width);
		//check
	if (all->rc->side == 0 && all->rc->raydir_x > 0)
		all->rc->text_x = hit_image.img_width - all->rc->text_x - 1;
	if (all->rc->side == 1 && all->rc->raydir_y < 0)
		all->rc->text_x = hit_image.img_width - all->rc->text_x - 1;
	all->rc->tex_pos = (all->rc->draw_start - all->rc->window_width
			+ all->rc->window_height / 2 + hit_image.line_length / 2)
		* all->rc->step;
	all->rc->start = all->rc->draw_start;
	all->rc->tex_step = 1.0 * hit_image.img_width / all->rc->line_height;
	while (all->rc->start < all->rc->draw_end)
	{
		
		all->rc->tex_pos += all->rc->tex_step;
		image_put_pixel(&hit_image, x, all);
		all->rc->start++;
	}
}

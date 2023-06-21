/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _mlx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:16:58 by eablak            #+#    #+#             */
/*   Updated: 2023/06/21 11:13:10 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	clear_img(t_all *all)
{
	mlx_destroy_image(all->mlx->mlx_init, all->mlx->mlx_img);
	all->mlx->mlx_img = mlx_new_image(all->mlx->mlx_init, all->rc->window_width,
			all->rc->window_height);
	all->mlx->mlx_img_addr = (int *)mlx_get_data_addr(all->mlx->mlx_img,
			&all->mlx->bits_per_pixel,
			&all->mlx->size_line,
			&all->mlx->endian);
}

void	floor_ceiling_color(t_all *all)
{
	int	x;
	int	y;

	x = -1;
	while (++x < all->rc->window_width)
	{
		y = -1;
		while (++y < all->rc->window_height)
		{
			if (y < all->rc->window_height / 2)
			{
				all->mlx->mlx_img_addr[y * all->rc->window_width
					+ x] = all->cub->c_color;
			}
			else
			{
				all->mlx->mlx_img_addr[y * all->rc->window_width
					+ x] = all->cub->f_color;
			}
		}
	}
}

int	engrave(t_all *all)
{
	clear_img(all);
	floor_ceiling_color(all);
	ray_casting(all);
	check_keys(all);
	return (1);
}

int	key_released(int keycode, t_all *all)
{
	if (keycode == W_KEY)
		all->rc->w_key = 0;
	else if (keycode == A_KEY)
		all->rc->a_key = 0;
	else if (keycode == S_KEY)
		all->rc->s_key = 0;
	else if (keycode == D_KEY)
		all->rc->d_key = 0;
	return (0);
}

void	_mlx(t_all *all)
{
	all->mlx->mlx_init = mlx_init();
	all->mlx->mlx_window = mlx_new_window(all->mlx->mlx_init,
			all->rc->window_width,
			all->rc->window_height,
			"cub3d");
	all->mlx->mlx_img = mlx_new_image(all->mlx->mlx_init, all->rc->window_width,
			all->rc->window_height);
	all->mlx->mlx_img_addr = (int *)mlx_get_data_addr(all->mlx->mlx_img,
			&all->mlx->bits_per_pixel,
			&all->mlx->size_line,
			&all->mlx->endian);
	get_xpm(all);
	set_keys(all);
	mlx_hook(all->mlx->mlx_window, 2, 1L << 0, &key_pressed, all);
	mlx_hook(all->mlx->mlx_window, 3, 1L << 0, &key_released, all);
	mlx_loop_hook(all->mlx->mlx_init, &engrave, all);
	mlx_hook(all->mlx->mlx_window, 17, 0, ft_close, all);
	mlx_loop(all->mlx->mlx_init);
}

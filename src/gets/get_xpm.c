/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_xpm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmesum <mmesum@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:36:51 by mmesum            #+#    #+#             */
/*   Updated: 2023/06/04 16:54:28 by mmesum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_color(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'F' || str[i] == 'C')
			return (1);
		i++;
	}
	return (0);
}

void	check_image(t_all *all)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (all->cub->image[i].img == NULL)
		{
			free_all(all);
			ft_putstr_fd("Error\nImage not found", 1);
			exit(0);
		}
		i++;
	}
}

void	get_xpm(t_all *all)
{
	int	i;

	i = 0;

	while (i < 4)
	{
		all->cub->image[i].img = mlx_xpm_file_to_image(all->mlx->mlx_init,
				all->cub->image[i].path,
				&all->cub->image[i].img_width,
				&all->cub->image[i].img_height);
		all->cub->image[i].address = mlx_get_data_addr(all->cub->image[i].img,
				&all->cub->image[i].bits_per_pixel,
				&all->cub->image[i].line_length,
				&all->cub->image[i].endian);
		i++;
	}
	check_image(all);
}

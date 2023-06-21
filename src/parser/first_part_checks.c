/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part_checks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:59:56 by eablak            #+#    #+#             */
/*   Updated: 2023/06/21 10:59:57 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	textures_return(char **split)
{
	free_double_pointer(split);
	return (0);
}

int	check_textures(char *str)
{
	char	**split;
	int		i;
	int		fd;

	i = 0;
	fd = 0;
	split = ft_split((char *)str, ' ');
	while (split[i])
		i++;
	if (i != 2)
		return (textures_return(split));
	if (split[1] == NULL)
		return (textures_return(split));
	fd = open(split[1], O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (textures_return(split));
	}
	close(fd);
	free_double_pointer(split);
	return (1);
}

int	check_color_error(t_cub *cub, char *str)
{
	handle_color(cub, str);
	if (cub->f_color == -1 || cub->c_color == -1)
		return (0);
	return (1);
}

void	first_part_checkers(t_cub *cub)
{
	if ((cub->_ea) == NULL || (cub->_we) == NULL || (cub->_so) == NULL
		|| (cub->_no) == NULL)
		fp_exit(cub);
	if (check_textures(cub->_ea) == 0 || check_textures(cub->_we) == 0
		|| check_textures(cub->_so) == 0 || check_textures(cub->_no) == 0)
		fp_exit(cub);
	if (cub->floor == NULL || cub->ceiling == NULL)
		fp_exit(cub);
	if (check_color_error(cub, cub->ceiling) == 0 || check_color_error(cub,
			cub->floor) == 0)
		fp_exit(cub);
}

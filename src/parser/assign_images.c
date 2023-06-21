/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:59:48 by eablak            #+#    #+#             */
/*   Updated: 2023/06/21 10:59:49 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*img_path(char *str)
{
	char	**ret;
	char	*val;

	ret = ft_split(str, ' ');
	if (ret[2] != NULL)
	{
		free_double_pointer(ret);
		return (NULL);
	}
	if (ret[1] != NULL)
	{
		val = ft_strdup(ret[1]);
		free_double_pointer(ret);
		return (val);
	}
	free_double_pointer(ret);
	return (NULL);
}

t_direction	get_img_type(char *str)
{
	while (*str == ' ' && *str)
		str++;
	if (str[0] == 'N' && str[1] == 'O' && str[2] == ' ')
		return (NO);
	if (str[0] == 'S' && str[1] == 'O' && str[2] == ' ')
		return (SO);
	if (str[0] == 'W' && str[1] == 'E' && str[2] == ' ')
		return (WE);
	if (str[0] == 'E' && str[1] == 'A' && str[2] == ' ')
		return (EA);
	return (UNKNOWN);
}

void	assign_images(t_cub *cub)
{
	cub->image = malloc(sizeof(t_image) * 4);
	cub->image[0].type = get_img_type(cub->_ea);
	cub->image[0].path = img_path(cub->_ea);
	cub->image[1].type = get_img_type(cub->_no);
	cub->image[1].path = img_path(cub->_no);
	cub->image[2].type = get_img_type(cub->_so);
	cub->image[2].path = img_path(cub->_so);
	cub->image[3].type = get_img_type(cub->_we);
	cub->image[3].path = img_path(cub->_we);
}

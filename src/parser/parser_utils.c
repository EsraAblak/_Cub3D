#include "../../cub3d.h"

int double_pointer_len(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

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
	cub->image[0].type =  get_img_type(cub->_ea);
    cub->image[0].path = img_path(cub->_ea);
	cub->image[1].type =  get_img_type(cub->_no);
    cub->image[1].path = img_path(cub->_no);
	cub->image[2].type =  get_img_type(cub->_so);
    cub->image[2].path = img_path(cub->_so);
	cub->image[3].type =  get_img_type(cub->_we);
    cub->image[3].path = img_path(cub->_we);
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


void	free_all(t_all *all)
{
	free(all->rc);
	free(all->mlx);
	free(all->cub);
	free(all);
}

int	ft_close(t_all *all)
{	
	game_exit(all);
	return (1);
}

void	free_double_pointer(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	check_cub(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (arg[len - 1] == 'b' && arg[len - 2] == 'u' && arg[len - 3] == 'c'
		&& arg[len - 4] == '.')
		return (1);
	return (0);
}
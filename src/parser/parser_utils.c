#include "../../cub3d.h"

int double_pointer_len(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void	free_all(t_all *all)
{
	free(all->rc);
	free(all->mlx);
	free(all->cub);
	free(all);
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

void free_first_part(t_cub *cub)
{
    if (cub->_ea != NULL)
        free(cub->_ea);
    if (cub->_we != NULL)
        free(cub->_we);
    if (cub->_so != NULL)
        free(cub->_so);
    if (cub->_no != NULL)
        free(cub->_no);
    if (cub->floor != NULL)
        free(cub->floor);
    if (cub->ceiling != NULL)
        free(cub->ceiling);
}
#include "../../cub3d.h"

void initalize_cub(t_cub *cub)
{
    cub->_ea = NULL;
    cub->_we = NULL;
    cub->_so = NULL;
    cub->_no = NULL;
    cub->floor = NULL;
    cub->ceiling = NULL;
}

void fp_exit(t_cub *cub)
{
    printf("Error\n");
    free_first_part(cub);
    exit(1);
}

void sp_exit(t_cub *cub)
{
    if (cub->map_reference != NULL)
        free(cub->map_reference);
    printf("Error\n");
    free_first_part(cub);
    exit(1);
}

int	ft_close(t_all *all)
{	
	game_exit(all);
	return (1);
}

void game_exit(t_all *all)
{
        mlx_clear_window(all->mlx->mlx_init, all->mlx->mlx_window);
		mlx_destroy_image(all->mlx->mlx_init, all->mlx->mlx_img);
		mlx_destroy_window(all->mlx->mlx_init, all->mlx->mlx_window);
		free_double_pointer(all->cub->double_ptr_map);
		free_first_part(all->cub);
		free(all->cub->map_reference);
    	free(all->cub->map);
		free_images(all);
		free_all(all);
        exit(0);
}
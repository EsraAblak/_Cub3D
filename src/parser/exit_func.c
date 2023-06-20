#include "../../cub3d.h"

void fp_exit(t_cub *cub)
{
    printf("first part wrong\n");
    free_first_part(cub);
    system("leaks cub3d");
    exit(1);
}

void sp_exit(t_cub *cub)
{
    if (cub->map_reference != NULL)
        free(cub->map_reference);
    printf("null mapreference\n");
    free_first_part(cub);
    exit(1);
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
        system("leaks cub3d");
		exit(0);
}
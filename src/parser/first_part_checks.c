#include "../../cub3d.h"

int check_textures(char *str)
{
    char **split;
    int i;
    int fd;

    i = 0;
    fd = 0;
    split = ft_split((char *)str,' ');
    while(split[i])
        i++;
    if (i != 2)
    {
        free_double_pointer(split);
        return (0);
    }
    if (split[1] == NULL)
    {
        free_double_pointer(split);
        return (0);
    }
    fd = open(split[1],O_RDONLY);
    if (fd < 0)
    {
        free_double_pointer(split);
        return (0);
    }
    close(fd);
    return(1);
}

int check_color_error(t_cub *cub, char *str)
{
    handle_color(cub,str);
    if (cub->f_color == -1 || cub->c_color == -1)
        return (0);
    return (1);
}

void first_part_checkers(t_cub *cub)
{
    if (check_textures(cub->_ea) == 0 || check_textures(cub->_we) == 0
        || check_textures(cub->_so) == 0|| check_textures(cub->_no) == 0)
    {
        printf("hatalı texturtes\n");
        system("leaks cub3d");
        free_first_part(cub);
        exit(1);
    }
    if (check_color_error(cub, cub->ceiling) == 0 || check_color_error(cub, cub->floor) == 0)
    {
        printf("hatalı color\n");
        system("leaks cub3d");
        free_first_part(cub);
        exit(1);
    }
}
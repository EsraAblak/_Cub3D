#include "../../cub3d.h"

char	*read_cubfile(int fd)
{
	char	*line;
	char	*all_line;

	all_line = NULL;
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		all_line = ft_g_strjoin(all_line, line);
		if (line != NULL)
			free(line);
	}
	return (all_line);
}

void read_cub(char *arg, t_cub *cub)
{
    int fd;

    cub->map = NULL;
    fd = open(arg,O_RDWR);
    if (fd < 0)
    {
        printf("file open error\n");
        return ;
    }
    cub->map = read_cubfile(fd);
    if (cub->map == NULL)
        return ;
    close (fd);
}

void control_cub(t_cub *cub)
{
    int i;
    int is_empty;
    
    i = 0;
    is_empty = 1;
    while (cub->map[i])
    {
        if ((cub->map[i] >= 65 && cub->map[i] <= 90) 
            || (cub->map[i] >= 97 && cub->map[i] <= 122)
            || (cub->map[i] >= 48 && cub->map[i] <= 57))
            {
                is_empty = 0;            
                break;
            }
        i++;
    }
    if (is_empty)
    {
        printf("unworkable cub file\n");
        free(cub);
        exit(1);
    }
}

void get_cub(char *arg, t_cub *cub)
{
    cub->map = NULL;
    read_cub(arg,cub);
    if (!cub->map)
    {
        printf("empty cub\n");
        free(cub);
        exit(1);
    }
    control_cub(cub);
}
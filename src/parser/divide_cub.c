#include "../../cub3d.h"

int is_full_line(t_cub* cub, int start, int *i)
{
    while(start < *i)
    {
        if ((cub->map[start] >= 65 && cub->map[start] <= 90) 
            || (cub->map[start] >= 97 && cub->map[start] <= 122)
            || (cub->map[start] >= 48 && cub->map[start] <= 57))
                return (1);
        start++;
    }
    return (0);
}

void take_first_part(t_cub *cub, int *i)
{
    int start;
    int count;

    start = 0;
    count = 0;
    while(cub->map[*i])
    {
        start = *i;
        while(cub->map[*i] != '\0' && cub->map[*i] != '\n')
            *i+=1;
        if (cub->map[*i] == '\n')
        {
            if (is_full_line(cub,start,i))
                count++;
        }
        if (cub->map[*i] != '\0')
            *i+=1;
        if (count == 6)
            break;
    }
}

void divide_cub(t_cub *cub)
{
    int i;

    i = 0;
    cub->first_part = NULL;
    cub->fp_last_index = &i;
    take_first_part(cub,&i);
    seperate_first_part(cub);
    first_part_checkers(cub);
    take_second_part(cub);
    second_part_checkers(cub);
    double_ptr_map(cub);
	assign_images(cub);
}
#include "../../cub3d.h"

void take_second_part(t_cub *cub)
{
    int i;
    int keep;

    i = 0;
    keep = *cub->fp_last_index;
    while(cub->map[*cub->fp_last_index])
    {
        *cub->fp_last_index+=1;
        i++;
    }
    cub->map_reference = NULL;
    cub->map_reference = malloc(sizeof(char) * (i + 1));
    i = 0;
    *cub->fp_last_index = keep;
    while(cub->map[*cub->fp_last_index])
    {
        cub->map_reference[i] = cub->map[*cub->fp_last_index];
        *cub->fp_last_index+=1;
        i++;
    }
    cub->map_reference[i] = '\0';
    if (cub->map_reference[0] == '\0')
    {
        free(cub->map_reference);
        printf("null mapreference\n");
        free_first_part(cub);
        exit(1);
    }
    //kontrollerden sonra burada tekrar player ata 
}
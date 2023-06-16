#include "../../cub3d.h"

char *line(t_cub *cub, int index)
{
    int keep_index;
    int i;

    i = 0;
    keep_index = index;
    while(cub->map[index] != '\0' && cub->map[index] != '\n')
    {
        i++;
        index++;
    }
    char *str;
    str = malloc(sizeof(char) * (i + 1));
    i = 0;
    index = keep_index;
    while(cub->map[index] != '\0' && cub->map[index] != '\n')
    {
        str[i] = cub->map[index];
        i++;
        index++;
    }
    if (str[i])
    str[i] = '\0';
    return (str);
}

int match_colors(t_cub *cub, int start)
{
    if (cub->map[start] == 'F' && cub->map[start+1] != '\0'
        &&  cub->map[start+1] == ' ')
    {
        cub->floor = line(cub,start);
        return (1);
    }
    if (cub->map[start] == 'C' && cub->map[start+1] != '\0'
        &&  cub->map[start+1] == ' ')
    {
        cub->ceiling = line(cub,start);
        return (1);
    }
    return (0);
}

int match_line(t_cub *cub, int start)
{
    
    if (cub->map[start] == 'E' && cub->map[start+1] != '\0'
        &&  cub->map[start+1] == 'A' && cub->map[start+2] != '\0'
            && cub->map[start+2] == ' ')
    {
        cub->_ea = line(cub,start);
        return (1);
    }
    if (cub->map[start] == 'N' && cub->map[start+1] != '\0'
        &&  cub->map[start+1] == 'O' && cub->map[start+2] != '\0'
            && cub->map[start+2] == ' ')
    {
        cub->_no = line(cub,start);
        return (1);
    }
    if (cub->map[start] == 'S' && cub->map[start+1] != '\0'
        &&  cub->map[start+1] == 'O' && cub->map[start+2] != '\0'
            && cub->map[start+2] == ' ')
    {
        cub->_so = line(cub,start);
        return (1);
    }
    if (cub->map[start] == 'W' && cub->map[start+1] != '\0'
        &&  cub->map[start+1] == 'E' && cub->map[start+2] != '\0'
            && cub->map[start+2] == ' ')
    {
        cub->_we = line(cub,start);
        return (1);
    }
    if (match_colors(cub,start))
        return (1);
    return (0);
}

void seperate_first_part(t_cub *cub)
{
    int i;
    int correct;
    int start;

    i = 0;
    correct = 0;
    start = 0;
    while(i < *cub->fp_last_index)
    {
        start = i;
        while(cub->map[i] != '\0' && cub->map[i] != '\n')
            i++;
        if (cub->map[i] == '\n')
            if (match_line(cub,start))
                correct++;
        if (cub->map[i] != '\0')
            i++;
    }
    if (correct != 6)
    {
        printf("first part wrong\n");
        exit(1);
    }
    // printf("%s\n",cub->_ea);
    // printf("%s\n",cub->_we);
    // printf("%s\n",cub->_so);
    // printf("%s\n",cub->_no);
    // printf("%s\n",cub->floor);
    // printf("%s\n",cub->ceiling);
}
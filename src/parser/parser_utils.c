#include "../../cub3d.h"

int double_pointer_len(char **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
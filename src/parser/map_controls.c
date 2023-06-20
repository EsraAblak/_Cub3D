#include "../../cub3d.h"

int	zero_location(char **split, int i, int j)
{

	if (i - 1 < 0 || i + 1 >= double_pointer_len(split) || j - 1 < 0 || j
		+ 1 > (int)ft_strlen(split[i]) - 1)
		    return (0);
	if (split[i - 1][j] == ' ' || split[i + 1][j] == ' ' || split[i][j - 1] == ' '
		|| split[i][j + 1] == ' ')
		return (0);
    if (split[i - 1][j] == '\0' || split[i + 1][j] == '\0' || split[i][j - 1] == '\0'
		|| split[i][j + 1] == '\0')
		return (0);
	return (1);
}

int wall_check(t_cub *cub)
{
    char **split;

    split = ft_split(cub->map_reference,'\n');
    int	i;
	int	j;

	i = 0;
	j = 0;
	while (split[i] != NULL)
	{
		j = 0;
		while (split[i][j] != '\0')
		{
			if (split[i][j] == '0' || split[i][j] == 'N' ||  split[i][j] == 'S'
                ||  split[i][j] == 'W' ||  split[i][j] == 'E')
				if (!zero_location(split, i, j))
                {
                    free_double_pointer(split);
                    return (1);
                }
			j++;
		}
		i++;
	}
    free_double_pointer(split);
    return (0);
}

int player_count(t_cub *cub)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while(cub->map_reference[i])
    {
        if (cub->map_reference[i] == 'N' || cub->map_reference[i] == 'W'
            || cub->map_reference[i] == 'S' || cub->map_reference[i] == 'E')
                count++;
        i++;
    }
    if (count != 1)
    {
        printf("player count\n");
        return (1);
    }
    return (0);
}
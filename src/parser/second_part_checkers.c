#include "../../cub3d.h"

int	map_character(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map_reference[i])
	{
		if (cub->map_reference[i] != '0' && cub->map_reference[i] != '1'
			&& cub->map_reference[i] != ' ' && cub->map_reference[i] != '\n'
			&& cub->map_reference[i] != 'N' && cub->map_reference[i] != 'S'
			&& cub->map_reference[i] != 'W' && cub->map_reference[i] != 'E'
			&& cub->map_reference[i] != '\t' && cub->map_reference[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

int	check_map_end(t_cub *cub, int i)
{
	while (cub->map_reference[i] != '\0')
    {
        if(cub->map_reference[i] != ' ' && cub->map_reference[i] != '\t')
            return 0;
        i++;
    }
    return 1;
}

int	map_count(t_cub *cub)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (cub->map_reference[i])
	{
		if (cub->map_reference[i] == '1' || cub->map_reference[i] == '0')
			break ;
		if (cub->map_reference[i])
			i++;
	}
	while (cub->map_reference[i])
	{
		if (cub->map_reference[i] == '\n')
		{
			i += 1;
			if (cub->map_reference[i] == '\n')
				return (1);
			if (check_map_end(cub, i))
				return (0);
			flag = 0;
			while (cub->map_reference[i] && cub->map_reference[i] != '\n')
			{
				if (cub->map_reference[i] == '1' || cub->map_reference[i] == '0'
					|| cub->map_reference[i] == 'N'
					|| cub->map_reference[i] == 'S'
					|| cub->map_reference[i] == 'W'
					|| cub->map_reference[i] == 'E')
				{
					flag = 1;
					break ;
				}
				if (cub->map_reference[i])
					i++;
			}
			if (flag == 0)
				return (1);
		}
		if (cub->map_reference[i])
			i++;
	}
	return (0);
}

void	second_part_checkers(t_cub *cub)
{
	if (map_character(cub) || map_count(cub) || wall_check(cub)
		|| player_count(cub))
	{
		printf("map hatasi\n");
		if (cub->map_reference != NULL)
			free(cub->map_reference);
		free_first_part(cub);
		system("leaks cub3D");
		exit(1);
	}
}
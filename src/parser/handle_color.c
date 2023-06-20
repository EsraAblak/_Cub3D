#include "../../cub3d.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_color(char *num)
{
	int	nbr;

	if (is_num(num))
	{
		nbr = ft_atoi(num);
		if (nbr < 0 || nbr > 255)
			return (-1);
	}
	else
		return (-1);
	return (nbr);
}

int	convert_int(char *str,t_cub *cub)
{
	char	**split;
	int		red;
	int		blue;
	int		green;
	int		rgb_int;

	split = ft_split(str, ',');
	if (double_pointer_len(split) != 3)
	{
		printf("color error\n");
		free_double_pointer(split);
		free_first_part(cub);
		system("leaks cub3d");
		exit(1);
	}
	red = check_color(split[0]);
	green = check_color(split[1]);
	blue = check_color(split[2]);
	if (red == -1 || green == -1 || blue == -1)
	{
		free_double_pointer(split);
		return (-1);
	}
	rgb_int = (red << 16) + (green << 8) + blue;
	free_double_pointer(split);
	return (rgb_int);
}

void	handle_color(t_cub *cub, char *str)
{
    int i;
	char	**split;

    i = 0;
	split = ft_split(str, ' ');
    while(split[i])
        i++;
    if (i != 2)
    {
		free_double_pointer(split);
        printf("color error\n");
        free_first_part(cub);
        exit(1);
    }
	if (split[0][0] == 'F' && split[0][1] == '\0')
		cub->f_color = convert_int(split[1],cub);
	if (split[0][0] == 'C' && split[0][1] == '\0')
		cub->c_color = convert_int(split[1],cub);
	free_double_pointer(split);
}

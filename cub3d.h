/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eablak <eablak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:20:43 by eablak            #+#    #+#             */
/*   Updated: 2023/06/05 16:21:29 by eablak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// # define W_KEY 13
// # define A_KEY 0
// # define S_KEY 1
// # define D_KEY 2
// # define RIGHT_ARROW_KEY 124
// # define LEFT_ARROW_KEY 123
// # define ESC_KEY 53

#define W_KEY 119
#define A_KEY 97
#define S_KEY 115
#define D_KEY 100
#define RIGHT_ARROW_KEY 65363
#define LEFT_ARROW_KEY 65361
#define ESC_KEY 65307

typedef enum e_direction
{
	NO,
	SO,
	WE,
	EA,
	UNKNOWN
}				t_direction;

typedef struct s_image
{
	t_direction	type;
	char		*path;
	void		*img;
	int			img_width;
	int			img_height;
	char		*address;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_map
{
	t_image		*image;
	char		**map;
	int			floor_color;
	int			ceiling_color;

	int			start_index;
	char		*c_map;
	char		**mmap;
	char		**copy_mmap;
	int			map_x;
	int			map_y;
}				t_map;

typedef struct s_map_help
{
	int			i;
	int			no;
	int			fd;
	int			so;
	int			we;
	int			ea;
	int			d;
}				t_help;

typedef struct s_raycasting
{
	int			window_height;
	int			window_width;

	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		scale_x;
	double		scale_y;

	int			key_a;
	int			key_w;
	int			key_s;
	int			key_d;

	double		camera_x;
	double		raydir_x;
	double		raydir_y;

	int			map_x;
	int			map_y;

	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perpwall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			text_x;
	int			tex_num;
	double		tex_step;
	double		tex_pos;
	double		move_speed;
	double		rot_speed;
	int			tex_y;

	double		wall_x;
	double		step;
	int			start;
}				t_rc;

typedef struct s_mlx
{
	void		*mlx_init;
	void		*mlx_window;
	void		*mlx_img;
	int			*mlx_img_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlx;


//new struct
typedef struct s_cub
{
	char	*map;
    char	**first_part;
	int		*fp_last_index;
	char	*_ea;
	char	*_no;
	char	*_so;
	char	*_we;
	char	*floor;
	char	*ceiling;
	int		c_color;
	int		f_color;
	char	*map_reference;
	char **double_ptr_map;
	int	map_x;
	int map_y;
	t_image		*image;
} t_cub;




typedef struct s_all
{
	t_rc		*rc;
	t_mlx		*mlx;
	t_cub		*cub;
}				t_all;




void			free_double_pointer(char **args);
int				check_cub(char *arg);
// char			**read_map(char *map, t_map *_map);
int				check_str(char *str);
void			free_map(t_map *map);
int				double_ptr_len(char **args);
void			safe_exit(t_map *map);
int				find_max_len(char **map);
void			_mlx(t_all *all);
void			ray_casting(t_all *all);
int				key_pressed(int keycode, t_all *all);
int				key_released(int keycode, t_all *all);
void			free_all(t_all *all);
void			handle_directions(t_all *all, int keycode);
void			get_xpm(t_all *all);
void			draw_images(t_all *all, int x);
int				ft_close(t_all *all);
t_direction		get_type(char *str);
int				is_empty(char *str);
void			map_start_index(char *all_line, t_map *map);
int				is_map_started(char *all_line, int start, int end);
void			find_map(char *all_line, int start, t_map *map);

//new functions
void get_cub(char *arg,t_cub *cub);
void divide_cub(t_cub *cub);
void seperate_first_part(t_cub *cub);
void first_part_checkers(t_cub *cub);
void free_first_part(t_cub *cub);
void	handle_color(t_cub *cub, char *str);
void take_second_part(t_cub *cub);
void second_part_checkers(t_cub *cub);
int double_pointer_len(char **str);
int wall_check(t_cub *cub);
int player_count(t_cub *cub);
void double_ptr_map(t_cub *cub);
t_all *first_definitions(t_cub *cub);
void	assign_images(t_cub *cub);
#endif

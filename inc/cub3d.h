/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 12:42:57 by aledos-s          #+#    #+#             */
/*   Updated: 2025/05/30 11:39:16 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"

/* ─── Defines ───────────────────────────────────────────────── */
# define WIN_TITLE "CUB3D"
# define WIN_WIDTH 2500
# define WIN_HEIGHT 1200
# define CELL_WALL '1'
# define CELL_EMPTY '0'
# define START_N 'N'
# define START_S 'S'
# define START_E 'E'
# define START_W 'W'
# define ANGLE_N 4.71238898038
# define ANGLE_S 1.57079632679
# define ANGLE_E 0.0
# define ANGLE_W 3.14159265359
# define PI 3.14159265359
# define FOV 67.0
# define PLAN_LEN 0.66
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.05
# define PLAYER_RADIUS 0.2
# define MOUSE_SENSI 0.0001
# define TEX_N 0
# define TEX_S 1
# define TEX_E 2
# define TEX_W 3
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307
/* ─── Defines minimap ──────────────────────────────────────────── */
# define MINIMAP_SIZE 200
# define CELL_SIZE 10
# define WALL_COLOR 0x444444
# define FLOOR_COLOR 0xAAAAAA
# define PLAYER_COLOR 0xFF0000
# define BORDER_COLOR 0x000000
# define MINIMAP_BORDER 2
# define PLAYER_SIZE 4
# define DIR_LINE_LENGTH 6

/* ─── Structures ─────────────────────────────────────────────── */
typedef struct s_mmap
{
	int			size;
	int			cell_size;
	int			wall_color;
	int			floor_color;
	int			player_color;
	int			border_size;
	int			border_color;
	int			player_size;
	int			dir_length;
	double		center_x;
	double		center_y;
	double		dir_end_x;
	double		dir_end_y;
	int			visible_cells;
	int			map_x;
	int			map_y;
	int			cell_x;
	int			cell_y;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
	int			x;
	int			y;
}	t_mmap;

typedef struct s_ray
{
	double		ray_dir_x;
	double		ray_dir_y;
	double		dist;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			step_x;
	int			step_y;
	int			side;
	int			map_x;
	int			map_y;
	double		wall_x;
}	t_ray;

typedef struct s_map
{
	char		**grid;
	char		*map_path;
	size_t		width;
	size_t		height;
}	t_map;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		angle;
	bool		w;
	bool		a;
	bool		s;
	bool		d;
	bool		r_left;
	bool		r_right;
}	t_player;

typedef struct s_img
{
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*img_ptr;
	int			width;
	int			height;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*texture_paths[4];
	int			floor_color;
	int			ceiling_color;
	t_mmap		mmap;
	t_img		img;
	t_img		textures[4];
	t_player	player;
	t_map		map;
	t_ray		ray;
}	t_game;

/* ─── Prototypes ─────────────────────────────────────────────── */
//PARSING
int				init_game(t_game *game, char *file);
int				init_mlx(t_game *game);
int				parse_game(t_game *game, char *file);
int				parse_file(t_game *game, char *file);
int				parse_color(char *color);
int				parse_map(t_game *game);
int				parse_texture(t_game *game);
int				check_extension(char *file, char *ext);
int				load_textures(t_game *game);
void			flood_fill(char **map, int x, int y, int height);
char			**dup_map(char **map, size_t height, size_t width);
int				check_valid_map(t_game *game, char **map_copy);
void			error_msg(char *msg);
char			*remove_parasite_end(char *str);
int				check_end_line(t_game *game);
int				flood_fill_map(t_game *game);
int				is_valid_char(char c);
void			replace_spaces_with_walls(char **map, size_t height,
					size_t width);
//EXIT
void			free_map(t_map *map);
void			free_array(char **array);
void			free_game(t_game *game);
void			quit_game(t_game *game);
//HOOKS
int				key_press(int key, void *param);
int				key_release(int key, void *param);
void			setup_hook(t_game *game);
//PLAYER
double			angle_direction(char dir);
int				is_start(char c);
void			set_player(t_game *game, size_t i, size_t j);
void			init_player(t_game *game);
int				is_wall(t_game *game, double x, double y);
void			move_forward(t_game *game);
void			move_backward(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			controls_player(t_game *game);
void			rotate_left(t_game *game);
void			rotate_right(t_game *game);
void			rotate_player_mouse(t_game *game, double angle);
//RAYCASTING
void			raycast(t_game *game);
void			init_ray(t_game *game, t_ray *ray, int x);
void			perform_dda(t_game *game, t_ray *ray);
int				get_tex_index(t_ray *ray);
unsigned int	get_tex_color(t_img *tex, t_ray *ray, int y, int line_h);
void			draw(t_ray *ray, int *draw_start, int *draw_end, int *line_h);
void			draw_vertical_line(t_game *game, int x, t_ray *ray);
//MINIMAP
void			init_minimap(t_mmap *mmap);
void			draw_minimap(t_game *game);
void			draw_minimap_cells(t_game *game, t_mmap *mmap);
void			minimap_pixel_put(t_img *img, int x, int y, int color);
void			draw_square(t_img *img, t_mmap *mmap, int color);
void			draw_line(t_img *img, t_mmap *mmap);
void			draw_minimap_border(t_img *img, t_mmap *mmap);
//MOUSE
void			draw_crosshair(t_game *game);
int				mouse_rotate(int x, int y, void *param);
//UTILS
void			pixel_put(t_game *game, int x, int y, int color);
//MAIN
int				game_loop(void *param);

#endif

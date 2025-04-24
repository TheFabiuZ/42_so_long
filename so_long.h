/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famirant <famirant@student.42firenze.it>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:30:06 by famirant          #+#    #+#             */
/*   Updated: 2022/11/28 19:06:35 by famirant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "srcs/libft/fts_libft/libft.h"
# include "srcs/libft/ft_printf/libftprintf.h"
# include "srcs/libft/get_next_line.h"
# include "mlx_linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_mapinfo
{
	int	espace;
	int	wall;
	int	collects;
	int	exit;
	int	start;
	int	enemy;
}	t_mapinfo;

typedef struct s_map
{
	char		**map;
	char		**backup;
	int			x;
	int			y;
	t_mapinfo	info;
}	t_map;

typedef struct s_stats
{
	int	*curr_pos;
	int	moves;
	int	uncollected;
}	t_stats;

typedef struct s_animate
{
	int					n;
	char				*curr;
	struct s_animate	*next;
}	t_animate;

typedef struct s_files
{
	char		*espace;
	char		*wall;
	char		*collectible;
	char		*exit;
	char		*start;
	t_animate	character;
	t_animate	enemy;
	char		*d_down;
	char		*d_left;
	char		*d_right;
	char		*l_border;
	char		*r_border;
	char		*u_left;
	char		*u_right;
	char		*u_up;
	char		*u_upwall;
}	t_files;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_aimgs
{
	int				tot;
	int				n;
	t_img			curr;
	struct s_aimgs	*next;
}	t_aimgs;

typedef struct s_grimgs
{
	t_img		espace;
	t_img		wall;
	t_img		collectible;
	t_img		exit;
	t_img		start;
	t_img		*character;
	t_img		*enemy;

	t_aimgs		acharacter;
	t_aimgs		aenemy;
}	t_grimgs;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_files		textures;
	t_grimgs	grimgs;
	t_stats		stats;
}	t_vars;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

// Functions
// ft_init_vars

void	initialize_vars_textures(t_files *texture);
void	initialize_vars_grimgs(t_grimgs *grimgs);
void	initialize_vars(t_vars	*vars);
void	initialize_display_window(t_vars *vars);

// ft_load_resources

void	add_animations(t_animate *alist, char *path, int n);
void	load_animations_file(int file, t_animate *temp);
void	load_animations(t_files *texture);
void	load_textures(t_files *texture);

// check_map

void	check_map(t_vars *vars, t_map *map);
void	check_map1(t_vars *vars, t_map *map);
void	check_map2(t_vars *vars, t_map *map);
void	check_map3(t_vars *vars, t_map *map, t_point i);
void	check_map4(t_vars *vars, t_map *map);

void	err1_rect(t_vars *vars);
void	err1_path(t_vars *vars);
int		check_map4_collects(t_map *map);
void	check_map_obj(t_vars *vars, char obj);
void	map_path(char **tab, t_point size, t_point begin);

// group_imgs | animgs

void	group_imgs_img(t_vars *vars, t_img *i, char *t);
void	group_imgs(t_vars *vars, t_grimgs *imgs);
t_aimgs	*new_animage(t_vars *vars, t_animate *texture, int n);
void	ani_imgs_atot(t_aimgs *img, int i);
void	ani_imgs_a(t_vars *vars, t_animate *temp, t_aimgs *img);
void	animations_imgs(t_vars *vars, t_grimgs *imgs);

// count_objects

void	count_objects_add(t_map *map, char obj);
void	count_objects(t_map *map);

// player_move

int		curr_uncollected(t_map *map);
void	player_next_pos(t_vars *vars, t_stats *stats, char next_pos);
void	player_movement(int x, int y, t_map	*map, t_vars *vars);

// entity_move

void	entity_move_direction(int movement, int *x, int *y);
void	entity_movement(int movement, t_map	*map, t_vars *vars);

// display_stats

char	*merge_str(char *str1, char *str2);
void	display_stats_str(t_vars *vars, t_stats *stats, char **s_c, char **s_m);
void	display_stats_togheter(char **str_clt, char **s_moves);
void	display_stats(t_vars *vars, t_stats *stats, t_img *i, int *ll);

// game_utils

int		*curr_entity_pos(t_map *map, char e);
void	display_map_terminal(t_map *map, char **mapp);
void	backup_map(t_map *map, int print_map);

// game_end

void	display_win(int collect, int moves, t_vars *vars);
void	display_lose(int uncollect, int collect, t_vars *vars);

// render_frame

int		randint(int next);
void	change_animation(int *an, t_aimgs *img, t_img **curr_img);
int		render_frame(t_vars *vars);

// render_map

void	render_walls(t_vars *vars, t_map *map, t_img *wall);
void	texture_map1(t_vars *vars, char c, int x, int y);
void	texture_map2(t_vars *vars, char c, int x, int y);
void	texture_map(t_vars *vars, char c, int x, int y);
void	my_map_to_window(t_vars *vars, t_map *map);

// render_borders

void	render_borders_up2(t_vars *vars, t_img *i, t_map *map);
void	render_borders_up(t_vars *vars, t_img *i, t_map *map);
void	render_borders_side(t_vars *vars, t_img *i, t_map *map);
void	render_borders_down(t_vars *vars, t_img *i, t_map *map);
void	render_borders(t_vars *vars, t_map *map);

// my_mlx_utils

size_t	ft_sizeelem(int file);
void	texture_credits(t_vars *vars);
int		win_destroy(t_vars *vars, int err);
int		on_keydown(int keycode, t_vars *vars);
void	my_mlx(t_vars *vars);

// free_map

void	free_map_and_backup(t_map *map);
void	free_map(t_map *map);
void	free_map_backup(t_map *map);

// free_imgs

void	free_grimgs_animage_list(t_aimgs *node);
void	free_grimgs_animage_a(void *mlx, t_aimgs *img);
void	free_grimgs_animage(void *mlx, t_grimgs *grimgs);
void	free_grimgs(void *mlx, t_grimgs *grimgs);

// free_textures

void	free_atextures_list(t_animate *node);
void	free_atextures(t_files *textures);

#endif
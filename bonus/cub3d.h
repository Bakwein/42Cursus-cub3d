/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:23:21 by stunca            #+#    #+#             */
/*   Updated: 2023/08/06 12:23:21 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>

# define BUFFER_SIZE 4095

typedef struct s_struct
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;
	int		curs;
}				t_struct;

# define MINIMAP_SIZE 5
# define MOVING_SPEED 0.08
# define ROTATION_SPEED 0.03
# define NUM_SPRITE_BOMUS 28
# define NUM_TEXTURE_BONUS 6
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
#  define KEY_FORWARD 13
#  define KEY_BACKWARD 1
#  define KEY_RIGHT 2
#  define KEY_LEFT 0
#  define KEY_TURN_LEFT 124
#  define KEY_TURN_RIGHT 123
#  define KEY_CROUCH 8
#  define KEY_ESCAPE 53
#  define KEY_SPRINT 126
#  define KEY_DOOR 40
#  define KEY_MOUSE 49
#  define KEY_ATTACK 257
#  define KEY_DEATH_MODE 31

# ifndef BONUS
#  define BONUS 0
# endif

typedef struct s_text {
	char	*path;
	void	*img;
	char	*add;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	int		width;
	int		height;
}				t_text;

typedef struct s_data
{
	t_text			text[50];
	char			*av;
	char			*wl;
	unsigned short	x_screen_size;
	unsigned short	y_screen_size;
	int				floor;
	int				ceiling;
	char			start_dir;
	char			*map[1024];
	int				security[20];
	int				x_map;
	int				y_map;
	int				frame;
	int				time;

	int				x_raymap;
	int				y_raymap;
	double			x_pos;
	double			y_pos;
	double			x_dir;
	double			y_dir;
	double			x_plane;
	double			y_plane;
	double			x_ray_dir;
	double			y_ray_dir;
	double			x_side_dist;
	double			y_side_dist;
	double			dist_wall;
	double			x_delta_dist;
	double			y_delta_dist;
	double			pos_plane;
	double			temp;
	int				x_step;
	int				y_step;
	int				hit;
	int				side;
	int				line_start;
	int				line_end;
	int				line_size;
	double			wall_hit;

	void			*mlx;
	void			*img;
	char			*addr;
	void			*win;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

	int				forward;
	int				sprint;
	int				mouse_flag;
	int				death_flag;
	int				backward;
	int				right;
	int				left;
	int				turn_right;
	int				turn_left;
	double			crouch;
	int				escape;
	int				victory;
	int				life;
	int				door_closed;
	int				attack;
	int				crew;
	int				v_bool_print_score;
	int				heart[11][11];
	int				the_end[19][36];


	int				sprite_num;
	double			sprite[1001][5];
	double			buff[20000];
	double			x_sprite;
	double			y_sprite;
	double			matrice;
	double			x_trans;
	double			y_trans;
	int				x_sprscr;
	int				y_sprscr;
	int				h_sprite;
	int				w_sprite;
	int				x_drawstart;
	int				y_drawstart;
	int				x_drawend;
	int				y_drawend;
	int				x_tex;
	int				y_tex;
	int				x_texture;
	int				y_texture;

	int				mouse_x;
	int				mouse_y;

	int				fd;
}				t_data;

int				get_next_line(int fd, char **line);
int				get_next_line2(int fd, char **line, t_struct *dta);
int				ft_strlen(char *str);
int				ft_strlenn(char *str);
char			*ft_strjoin(char *s1, char *s2, t_struct *dta);
char			*free_null(char *s1);
int				free_int(char **line);

void			ft_putstr_bn(char *str);
int				ft_atoi(char *str);
int				ft_atoi_parsing(char *str, int *i);
char			*ft_strdup(char *s1);

int				get_t(int i);
int				get_r(int i);
int				get_g(int i);
int				get_b(int i);
int				store_color(int i, int j, int k);

void			store_info(int fd, t_data *data, char *line);

void			print_info(t_data *data);
int				free_struct(t_data *data, int m);
void			print_map(t_data *data);
void			store_sprite(t_data *data, int x, int y);

void			turn_left(t_data *data);
void			turn_right(t_data *data);
int				security_check(t_data *data);
int				security_cub(int ac, char **av, t_data *data);
int				security_data(t_data *data);

void			fd_check(int fd);
void			check_map(t_data *data);

void			set_vector_dir(t_data *data);
void			fill_map_one(t_data *data);

int				ft_key_hook2(int keycode, t_data *data);
int				ft_key_hook(int keycode, t_data *data);
int				ft_key_unhook(int keycode, t_data *data);

void			add_minimap_and_company(t_data *data);
void			add_lifebar(t_data *data);
void			add_hud(t_data *data);

void			move_according_to_key_press(t_data *data);

void			texture_check(t_data *data);

void			ft_mlx_pixel_put(t_data *data, int x, int y, int color);
void			sort_sprite(t_data *data);
void			sprite_dist_calc(t_data *data);
void			init_images_mlx(t_data *data);

void			put_column_image(t_data *data, int column);

void			store_map(int fd, t_data *data);

void			raycasting_initialize(t_data *data, int *i);
void			raycasting_move_until_wall(t_data *data);
void			raycasting_line_position(t_data *data);

void			sprite(t_data *data);

int				clean_exit(int keycode, t_data *data);
int				exit_free(t_data *data);

void			init_images_bonus(t_data *data);
void			initialize_heart(t_data *data);

void			heal_at_spawn(t_data *data);
void			initialize_the_end(t_data *data);
void			end_names(char *tab[]);
void			echo_the_end(t_data *data);

int				is_in(char c, char *str);
int				ft_strncmp_loc(const char *s1, const char *s2, int n);
void			victory_exit_check(t_data *data);
void			attack_if_possible(t_data *data);

void			ft_putnbr(int n);
void			ft_putchar(char c);
int				ft_strncmp(char *s1, char *s2, int n);

void			close_door(t_data *data);
void			open_door(t_data *data);

int				long_condition(char *line);
void			store_path1(t_data *data, char *line);
void			store_path2(t_data *data, char *line);
void			store_path3(t_data *data, char *line);
void			store_path4(t_data *data, char *line);

void			set_vector_dir_extension(t_data *data);
void			store_fc2(char c, int *i, unsigned short *red);
void			multiple_empty_lines(t_data *data);

void			mouse_move(t_data *data);
void			handle_mouse(t_data *data);

#endif

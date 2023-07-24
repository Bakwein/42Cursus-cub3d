/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 10:56:04 by bmerchin          #+#    #+#             */
/*   Updated: 2021/01/12 16:17:14 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** List data->security possible errors
** security 0 : Resolution
** security 1 : Floor
** security 2 : Ceiling
** security 3 : Sprite
** security 4 : NO
** security 5 : SO
** security 6 : WE
** security 7 : EA
** security 8 : Starting Direction in the map
** security 9 : If there is a missing wall
** security 10 : Wrong character
** security 11 : Texture opening check
*/

void	raycasting_calculation(t_data *data)
{
	int i;

	i = 0;
	while (i < data->x_screen_size)
	{
		raycasting_initialize(data, &i);
		raycasting_move_until_wall(data);
		raycasting_line_position(data);
		put_column_image(data, i);
		data->buff[i] = data->dist_wall;
		data->hit = 0;
		i++;
	}
	sprite_dist_calc(data);
	sort_sprite(data);
	sprite(data);
	save_image(data);
}

int		render_next_frame(t_data *data)
{
	if (data->save == 0)
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	victory_exit_check(data);
	if (data->life == 0)
	{
		echo_the_end(data);
		return (0);
	}
	move_according_to_key_press(data);
	heal_at_spawn(data);
	attack_if_possible(data);
	raycasting_calculation(data);
	if (MINIMAP_SIZE * data->x_map <= data->x_screen_size
	&& MINIMAP_SIZE * data->y_map <= data->y_screen_size && BONUS)
		add_minimap_and_company(data);
	data->frame++;
	open_door(data);
	if (data->frame % 40 > 19)
		data->time = 1;
	else
		data->time = 0;
	return (0);
}

void	run_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->save == 0)
	{
		screen_resize(data);
		data->win = mlx_new_window(data->mlx, data->x_screen_size,
		data->y_screen_size, "Among Us in cub3D - A 42 Paris Project");
		mlx_loop_hook(data->mlx, render_next_frame, data);
		mlx_hook(data->win, 2, 1L << 0, ft_key_hook, data);
		mlx_hook(data->win, 3, 1L << 1, ft_key_unhook, data);
		if (LINUX)
			mlx_hook(data->win, 33, 1L << 5, exit_free, data);
	}
	data->img = mlx_new_image(data->mlx, data->x_screen_size,
		data->y_screen_size);
	data->addr = mlx_get_data_addr(data->img,
		&data->bits_per_pixel, &data->line_length, &data->endian);
	init_images_mlx(data);
	if (data->save == 1)
		render_next_frame(data);
	mlx_loop(data->mlx);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	t_data	data;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	data.av = av[1];
	if (security_cub(ac, av, &data, fd) == 1)
		return (0);
	store_info(fd, &data, line);
	if (security_data(&data) == 1)
		return (free_struct(&data, 0));
	store_map(fd, &data);
	check_map(&data);
	if (security_check(&data) == 1)
		return (free_struct(&data, 1));
	fill_map_one(&data);
	texture_check(&data);
	if (data.security[11] == 1)
		return (free_struct(&data, 1));
	print_info(&data);
	set_vector_dir(&data);
	print_map(&data);
	run_mlx(&data);
	return (free_struct(&data, 1));
}

/*
** List of Bonus
** 1 : Minimap
** 2 : Sprint
** 3 : Different Sprites (15+)
** 4 : Animated Sprites
** 5 : Crouch
** 6 : Colision with walls
** 7 : Colision with sprites
** 8 : Life Bar
** 9 : HUD
** 10 : Enemy can damage your life
** 11 : Exit message on the screen
** 12 : Multiple level in the game
** 13 : Hiden doors
** 14 : Doors
** 15 : Gameplay
** 16 : Possibility to heal at spawn
** 17 : Different textures for one side
** 18 : Handmade pixel art for this game
*/

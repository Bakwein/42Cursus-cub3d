/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:52:54 by bmerchin          #+#    #+#             */
/*   Updated: 2021/02/23 11:52:55 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycasting_initialize2(t_data *data)
{
	if (data->x_ray_dir < 0)
	{
		data->x_step = -1;
		data->x_side_dist =
		(data->x_pos - data->x_raymap) * data->x_delta_dist;
	}
	else
	{
		data->x_step = 1;
		data->x_side_dist =
		(data->x_raymap + 1.0 - data->x_pos) * data->x_delta_dist;
	}
	if (data->y_ray_dir < 0)
	{
		data->y_step = -1;
		data->y_side_dist =
		(data->y_pos - data->y_raymap) * data->y_delta_dist;
	}
	else
	{
		data->y_step = 1;
		data->y_side_dist =
		(data->y_raymap + 1.0 - data->y_pos) * data->y_delta_dist;
	}
}

void	raycasting_initialize(t_data *data, int *i)
{
	data->pos_plane = 2 * (*i) / (double)data->x_screen_size - 1;
	data->x_ray_dir = data->x_dir + data->x_plane * data->pos_plane;
	data->y_ray_dir = data->y_dir + data->y_plane * data->pos_plane;
	data->x_raymap = (int)data->x_pos;
	data->y_raymap = (int)data->y_pos;
	if (data->x_ray_dir == 0)
		data->x_delta_dist = 1000000;
	else
	{
		if (data->x_ray_dir == 0)
			data->x_delta_dist = 1;
		else
			data->x_delta_dist = fabs(1 / data->x_ray_dir);
	}
	if (data->y_ray_dir == 0)
		data->y_delta_dist = 1000000;
	else
	{
		if (data->y_ray_dir == 0)
			data->y_delta_dist = 1;
		else
			data->y_delta_dist = fabs(1 / data->y_ray_dir);
	}
	raycasting_initialize2(data);
}

void	raycasting_move_until_wall(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->x_side_dist < data->y_side_dist)
		{
			data->x_side_dist += data->x_delta_dist;
			data->x_raymap += data->x_step;
			data->side = 0;
		}
		else
		{
			data->y_side_dist += data->y_delta_dist;
			data->y_raymap += data->y_step;
			data->side = 1;
		}
		if (is_in(data->map[data->y_raymap][data->x_raymap], "135.,_@#$"))
			data->hit = 1;
	}
}

void	raycasting_line_position(t_data *data)
{
	if (data->side == 0)
		data->dist_wall = (data->x_raymap -
		data->x_pos + (1 - data->x_step) / 2) / data->x_ray_dir;
	else
		data->dist_wall = (data->y_raymap -
		data->y_pos + (1 - data->y_step) / 2) / data->y_ray_dir;
	data->line_size = (int)(data->y_screen_size / data->dist_wall);
	data->line_start = -data->line_size / 2
	+ data->y_screen_size / 2 + data->crouch;
	if (data->line_start < 0)
		data->line_start = 0;
	data->line_end = data->line_size / 2
	+ data->y_screen_size / 2 + data->crouch;
	if (data->line_end >= data->y_screen_size)
		data->line_end = data->y_screen_size - 1;
}

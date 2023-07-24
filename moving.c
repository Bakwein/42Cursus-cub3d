/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:57:21 by bmerchin          #+#    #+#             */
/*   Updated: 2021/02/23 10:57:23 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		mv(t_data *data, int i)
{
	if (is_in(i, "15.,_@#$"))
		return (0);
	if (BONUS && is_in(i, "2klm"))
	{
		data->life--;
		return (0);
	}
	return (1);
}

void	move_right_left(t_data *data)
{
	if (data->right == 1)
	{
		if (mv(data, data->map[(int)(data->y_pos)][(int)(data->x_pos -
		data->y_dir * MOVING_SPEED * 2)]))
			data->x_pos -= data->y_dir * MOVING_SPEED;
		if (mv(data, data->map[(int)(data->y_pos +
		data->x_dir * MOVING_SPEED * 2)][(int)(data->x_pos)]))
			data->y_pos += data->x_dir * MOVING_SPEED;
	}
	if (data->left == 1)
	{
		if (mv(data, data->map[(int)(data->y_pos)][(int)(data->x_pos +
		data->y_dir * MOVING_SPEED * 2)]))
			data->x_pos += data->y_dir * MOVING_SPEED;
		if (mv(data, data->map[(int)(data->y_pos - data->x_dir *
		MOVING_SPEED * 2)][(int)(data->x_pos)]))
			data->y_pos -= data->x_dir * MOVING_SPEED;
	}
}

void	turn_right(t_data *data)
{
	if (data->turn_right == 1)
	{
		data->temp = data->x_dir;
		data->x_dir = data->x_dir * cos(-ROTATION_SPEED)
		- data->y_dir * sin(-ROTATION_SPEED);
		data->y_dir = data->temp * sin(-ROTATION_SPEED)
		+ data->y_dir * cos(-ROTATION_SPEED);
		data->temp = data->x_plane;
		data->x_plane = data->x_plane * cos(-ROTATION_SPEED)
		- data->y_plane * sin(-ROTATION_SPEED);
		data->y_plane = data->temp * sin(-ROTATION_SPEED)
		+ data->y_plane * cos(-ROTATION_SPEED);
	}
}

void	turn_left(t_data *data)
{
	if (data->turn_left == 1)
	{
		data->temp = data->x_dir;
		data->x_dir = data->x_dir * cos(ROTATION_SPEED)
		- data->y_dir * sin(ROTATION_SPEED);
		data->y_dir = data->temp * sin(ROTATION_SPEED)
		+ data->y_dir * cos(ROTATION_SPEED);
		data->temp = data->x_plane;
		data->x_plane = data->x_plane * cos(ROTATION_SPEED)
		- data->y_plane * sin(ROTATION_SPEED);
		data->y_plane = data->temp * sin(ROTATION_SPEED)
		+ data->y_plane * cos(ROTATION_SPEED);
	}
}

void	move_according_to_key_press(t_data *data)
{
	if (data->forward == 1)
	{
		if (mv(data, data->map[(int)data->y_pos][(int)(data->x_pos
		+ data->x_dir * MOVING_SPEED * (2 + data->sprint))]))
			data->x_pos += data->x_dir * MOVING_SPEED
			+ data->sprint * data->x_dir * MOVING_SPEED;
		if (mv(data, data->map[(int)(data->y_pos
		+ data->y_dir * MOVING_SPEED * 3)][(int)(data->x_pos)]))
			data->y_pos += data->y_dir * MOVING_SPEED
			+ data->sprint * data->y_dir * MOVING_SPEED;
	}
	if (data->backward == 1)
	{
		if (mv(data, data->map[(int)data->y_pos][(int)(data->x_pos
		- data->x_dir * MOVING_SPEED * (2 + data->sprint))]))
			data->x_pos -= data->x_dir * MOVING_SPEED;
		if (mv(data, data->map[(int)(data->y_pos
		- data->y_dir * MOVING_SPEED * 2)][(int)(data->x_pos)]))
			data->y_pos -= data->y_dir * MOVING_SPEED;
	}
	move_right_left(data);
	turn_right(data);
	turn_left(data);
}

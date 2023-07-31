/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:19:39 by stunca            #+#    #+#             */
/*   Updated: 2023/07/31 13:28:01 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mouse_move_1(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->x_dir;
	oldplanex = data->x_plane;
	data->x_dir = data->x_dir * cos(ROTATION_SPEED) - \
		data->y_dir * sin(ROTATION_SPEED);
	data->y_dir = olddirx * sin(ROTATION_SPEED) + \
		data->y_dir * cos(ROTATION_SPEED);
	data->x_plane = data->x_plane * cos(ROTATION_SPEED) - \
		data->y_plane * sin(ROTATION_SPEED);
	data->y_plane = oldplanex * sin(ROTATION_SPEED) + \
		data->y_plane * cos(ROTATION_SPEED);
}

void	mouse_move_2(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->x_dir;
	oldplanex = data->x_plane;
	data->x_dir = data->x_dir * cos(-ROTATION_SPEED) - \
		data->y_dir * sin(-ROTATION_SPEED);
	data->y_dir = olddirx * sin(-ROTATION_SPEED) + \
		data->y_dir * cos(-ROTATION_SPEED);
	data->x_plane = data->x_plane * cos(-ROTATION_SPEED) - \
		data->y_plane * sin(-ROTATION_SPEED);
	data->y_plane = oldplanex * sin(-ROTATION_SPEED) + \
		data->y_plane * cos(-ROTATION_SPEED);
}

void	mouse_move(t_data *data)
{
	mlx_mouse_get_pos(data->win, &data->mouse_x, &data->mouse_y);
	if (data->mouse_x > data->x_screen_size / 2)
		mouse_move_1(data);
	else if (data->mouse_x < data->x_screen_size / 2)
		mouse_move_2(data);
	mlx_mouse_move(data->win, data->x_screen_size / 2, data->y_screen_size / 2);
}

void	handle_mouse(t_data *data)
{
	if (BONUS && data->frame % 10 == 0 && data->mouse_flag == 1)
		mlx_mouse_hide();
	if (BONUS && data->mouse_flag == 0)
		mlx_mouse_show();
	if (BONUS && data->mouse_flag)
		mouse_move(data);
}

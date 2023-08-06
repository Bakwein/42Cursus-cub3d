/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:19:39 by stunca            #+#    #+#             */
/*   Updated: 2023/08/06 12:21:19 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mouse_move(t_data *data)
{
	mlx_mouse_get_pos(data->win, &data->mouse_x, &data->mouse_y);
	if (data->mouse_x < data->x_screen_size / 2)
	{
		data->turn_right = 1;
		turn_right(data);
		data->turn_right = 0;
	}
	else if (data->mouse_x > data->x_screen_size / 2)
	{
		data->turn_left = 1;
		turn_left(data);
		data->turn_left = 0;
	}
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

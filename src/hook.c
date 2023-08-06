/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:24:25 by stunca            #+#    #+#             */
/*   Updated: 2023/08/06 12:24:26 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_key_hook2(int keycode, t_data *data)
{
	if (keycode == KEY_DOOR && BONUS)
		close_door(data);
	if (keycode == KEY_MOUSE && BONUS && data->mouse_flag == 0)
		data->mouse_flag = 1;
	else if (keycode == KEY_MOUSE && BONUS && \
		data->mouse_flag == 1)
		data->mouse_flag = 0;
	return (0);
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_FORWARD)
		data->forward = 1;
	if (keycode == KEY_BACKWARD)
		data->backward = 1;
	if (keycode == KEY_RIGHT)
		data->right = 1;
	if (keycode == KEY_LEFT)
		data->left = 1;
	if (keycode == KEY_TURN_LEFT)
		data->turn_left = 1;
	if (keycode == KEY_TURN_RIGHT)
		data->turn_right = 1;
	if (keycode == KEY_CROUCH && BONUS)
		data->crouch = -30;
	if (keycode == KEY_ESCAPE)
		data->escape = 1;
	if (keycode == KEY_ATTACK && BONUS && data->attack == 0)
		data->attack = 30;
	else if (keycode == KEY_ATTACK && BONUS)
		printf("You have still %d frames of cooldown left\n", data->attack);
	if (keycode == KEY_SPRINT && BONUS)
		data->sprint = 1;
	ft_key_hook2(keycode, data);
	return (0);
}

int	ft_key_unhook(int keycode, t_data *data)
{
	if (keycode == KEY_FORWARD)
		data->forward = 0;
	if (keycode == KEY_BACKWARD)
		data->backward = 0;
	if (keycode == KEY_RIGHT)
		data->right = 0;
	if (keycode == KEY_LEFT)
		data->left = 0;
	if (keycode == KEY_TURN_LEFT)
		data->turn_left = 0;
	if (keycode == KEY_TURN_RIGHT)
		data->turn_right = 0;
	if (keycode == KEY_CROUCH)
		data->crouch = 0;
	if (keycode == KEY_ESCAPE)
		data->escape = 0;
	if (keycode == KEY_SPRINT)
		data->sprint = 0;
	return (0);
}

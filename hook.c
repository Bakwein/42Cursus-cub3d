/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:02:34 by bmerchin          #+#    #+#             */
/*   Updated: 2021/02/23 10:02:50 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_key_hook(int keycode, t_data *data)
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
		data->attack = 300;
	else if (keycode == KEY_ATTACK && BONUS)
		printf("You have still %d frames of cooldown left\n", data->attack);
	if (keycode == KEY_SPRINT && BONUS)
		data->sprint = 1;
	if (keycode == KEY_DOOR && BONUS)
		close_door(data);
	return (0);
}

int		ft_key_unhook(int keycode, t_data *data)
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

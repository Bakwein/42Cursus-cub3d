/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:02:34 by bmerchin          #+#    #+#             */
/*   Updated: 2021/02/23 10:02:50 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	close_door(t_data *data)
{
	int i;
	int j;

	i = 0;
	if (!BONUS)
		return ;
	data->door_closed = 400;
	while (i < data->x_map)
	{
		j = 0;
		while (j < data->y_map)
		{
			if (data->map[j][i] == '4')
			{
				data->map[j][i] = '5';
			}
			j++;
		}
		i++;
	}
}

void	open_door(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	data->door_closed--;
	if (data->door_closed != 0)
		return ;
	if (!BONUS)
		return ;
	while (i < data->x_map)
	{
		j = 0;
		while (j < data->y_map)
		{
			if (data->map[j][i] == '5')
				data->map[j][i] = '4';
			j++;
		}
		i++;
	}
}

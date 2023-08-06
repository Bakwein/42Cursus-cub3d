/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:19:33 by stunca            #+#    #+#             */
/*   Updated: 2023/08/06 12:19:35 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	close_door(t_data *data)
{
	int	i;
	int	j;

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
	int	i;
	int	j;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_initialize_struct_map.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 15:47:55 by bmerchin          #+#    #+#             */
/*   Updated: 2023/08/01 23:04:06 by hsozan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initialize_struct2(t_data *data)
{
	int	i;
	int	j;

	data->time = 0;
	data->life = 30;
	data->sprint = 0;
	data->mouse_flag = 0;
	data->door_closed = 0;
	data->v_bool_print_score = 0;
	if (!BONUS)
		return ;
	i = 0;
	j = 0;
	while (i < 500)
	{
		if (data->map[(int)data->sprite[i][1]][(int)data->sprite[i][0]] == '2')
		{
			data->sprite[i][4] = (j * 2 + 22) % 12; 
			j++;
		}
		i++;
	}
	initialize_heart(data);
}

void	intialize_struct(t_data *data)
{
	int	i;

	i = -1;
	data->forward = 0;
	data->backward = 0;
	data->right = 0;
	data->left = 0;
	data->turn_right = 0;
	data->turn_left = 0;
	data->hit = 0;
	data->frame = 0;
	data->crouch = 0;
	data->escape = 0;
	data->victory = 0;
	data->attack = 0;
	initialize_the_end(data);
	while (++i < 500)
		data->sprite[i][4] = 0;
	initialize_struct2(data);
}

void	set_vector_dir(t_data *data)
{
	if (data->start_dir == 'N')
	{
		data->x_dir = 0;
		data->y_dir = -1;
		data->x_plane = 0.66;
		data->y_plane = 0;
	}
	if (data->start_dir == 'S')
	{
		data->x_dir = 0;
		data->y_dir = 1;
		data->x_plane = -0.66;
		data->y_plane = 0;
	}
	if (data->start_dir == 'E')
	{
		data->x_dir = 1;
		data->y_dir = 0;
		data->x_plane = 0;
		data->y_plane = 0.66;
	}
	set_vector_dir_extension(data);
	intialize_struct(data);
}

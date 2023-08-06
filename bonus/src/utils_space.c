/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:22:49 by stunca            #+#    #+#             */
/*   Updated: 2023/08/06 15:55:02 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_vector_dir_extension(t_data *data)
{
	if (data->start_dir == 'W')
	{
		data->x_dir = -1;
		data->y_dir = 0;
		data->x_plane = 0;
		data->y_plane = -0.66;
	}
}

void	store_fc2(char c, int *i, unsigned short *red)
{
	if (c == ',')
		(*i)++;
	else
	{
		(*i)--;
		*red = 1000;
	}
}

void	multiple_empty_lines(t_data *data)
{
	if (data->y_map < 2)
		return ;
	if (ft_strlen(data->map[data->y_map]) == 0 && \
	ft_strlen(data->map[data->y_map - 1]) == 0)
	{
		data->security[11] = 1;
		ft_putstr_bn("Error\nMultiple empty lines at the end of the file");
	}
}

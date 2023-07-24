/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:15:14 by bmerchin          #+#    #+#             */
/*   Updated: 2021/02/23 11:15:15 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * 4);
	*(unsigned int*)dst = color;
}

void	switch_data_sprite(t_data *data, int i, int j)
{
	data->sprite[500][0] = data->sprite[i][0];
	data->sprite[500][1] = data->sprite[i][1];
	data->sprite[500][2] = data->sprite[i][2];
	data->sprite[500][3] = data->sprite[i][3];
	data->sprite[500][4] = data->sprite[i][4];
	data->sprite[i][0] = data->sprite[j][0];
	data->sprite[i][1] = data->sprite[j][1];
	data->sprite[i][2] = data->sprite[j][2];
	data->sprite[i][3] = data->sprite[j][3];
	data->sprite[i][4] = data->sprite[j][4];
	data->sprite[j][0] = data->sprite[500][0];
	data->sprite[j][1] = data->sprite[500][1];
	data->sprite[j][2] = data->sprite[500][2];
	data->sprite[j][3] = data->sprite[500][3];
	data->sprite[j][4] = data->sprite[500][4];
}

void	sort_sprite(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (++i < data->sprite_num)
	{
		j = i;
		while (++j < data->sprite_num)
		{
			if (data->sprite[i][3] < data->sprite[j][3])
				switch_data_sprite(data, i, j);
		}
	}
}

void	sprite_dist_calc(t_data *data)
{
	int i;

	i = 0;
	while (i < data->sprite_num)
	{
		data->sprite[i][3] = ((data->x_pos - data->sprite[i][0]) *
		(data->x_pos - data->sprite[i][0]) + (data->y_pos - data->sprite[i][1])
		* (data->y_pos - data->sprite[i][1]));
		i++;
	}
}

void	init_images_mlx(t_data *data)
{
	int i;

	i = 0;
	while (i < 5)
	{
		data->text[i].img = mlx_xpm_file_to_image(data->mlx, data->text[i].path,
		&data->text[i].width, &data->text[i].height);
		data->text[i].add = mlx_get_data_addr(data->text[i].img,
		&data->text[i].bits_per_pixel, &data->text[i].line_length,
		&data->text[i].endian);
		i++;
	}
	init_images_bonus(data);
}

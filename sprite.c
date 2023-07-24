/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 13:05:13 by bmerchin          #+#    #+#             */
/*   Updated: 2021/02/23 13:05:17 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite2(t_data *data, int i)
{
	data->x_sprite = data->sprite[i][0] - data->x_pos;
	data->y_sprite = data->sprite[i][1] - data->y_pos;
	data->matrice =
	1 / (data->x_plane * data->y_dir - data->x_dir * data->y_plane);
	data->x_trans = data->matrice *
	(data->y_dir * data->x_sprite - data->x_dir * data->y_sprite);
	data->y_trans = data->matrice *
	(-data->y_plane * data->x_sprite + data->x_plane * data->y_sprite);
	data->x_sprscr = (int)((data->x_screen_size / 2) *
	(1 + data->x_trans / data->y_trans));
	data->h_sprite = abs((int)(data->y_screen_size / data->y_trans));
	data->y_drawstart = -data->h_sprite / 2
	+ data->y_screen_size / 2 + data->crouch;
}

void	sprite3(t_data *data)
{
	if (data->y_drawstart < 0)
		data->y_drawstart = 0;
	data->y_drawend = data->h_sprite / 2
	+ data->y_screen_size / 2 + data->crouch;
	if (data->y_drawend >= data->y_screen_size)
		data->y_drawend = data->y_screen_size;
	data->w_sprite = abs((int)(data->y_screen_size / data->y_trans));
	data->x_drawstart = -data->w_sprite / 2 + data->x_sprscr;
	if (data->x_drawstart < 0)
		data->x_drawstart = 0;
	data->x_drawend = data->w_sprite / 2 + data->x_sprscr;
	if (data->x_drawend >= data->x_screen_size)
		data->x_drawend = data->x_screen_size;
}

void	draw_sprite_column(t_data *data, int j, int id)
{
	int k;
	int d;

	k = data->y_drawstart;
	while (k < data->y_drawend)
	{
		d = (k - data->crouch) * 256 - data->y_screen_size * 128
		+ data->h_sprite * 128;
		data->y_tex = abs(((d * data->text[id].height) / data->h_sprite) / 256);
		if (*(unsigned int *)(data->text[id].add +
		data->text[id].line_length * data->y_tex + data->x_tex * 4) != 0)
			*(unsigned int *)(data->addr + (k * data->line_length + j * 4)) =
			*(unsigned int *)(data->text[id].add +
			data->text[id].line_length * data->y_tex + data->x_tex * 4);
		k++;
	}
}

void	sprite(t_data *data)
{
	int i;
	int j;
	int	id;

	i = 0;
	while (i < data->sprite_num)
	{
		id = data->sprite[i][4] + 4;
		if (id == 104)
			id = 23 + data->time * 2;
		sprite2(data, i);
		sprite3(data);
		j = data->x_drawstart;
		while (j < data->x_drawend)
		{
			data->x_tex = abs((256 * (j - (-data->w_sprite / 2 +
			data->x_sprscr)) * data->text[id].width / data->w_sprite) / 256);
			if (data->y_trans > 0 && j >= 0 && j < data->x_screen_size &&
			data->y_trans < data->buff[j])
				draw_sprite_column(data, j, id);
			j++;
		}
		i++;
	}
}

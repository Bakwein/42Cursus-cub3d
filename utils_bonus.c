/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:45:12 by bmerchin          #+#    #+#             */
/*   Updated: 2021/02/24 15:45:13 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_heart2(t_data *data, char *tab[11])
{
	int i;
	int j;

	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 11)
		{
			if (tab[j][i] == '0')
				data->heart[j][i] = 0;
			else if (tab[j][i] == '1')
				data->heart[j][i] = 131072;
			else if (tab[j][i] == '2')
				data->heart[j][i] = 10944515;
			else if (tab[j][i] == '3')
				data->heart[j][i] = 16709366;
			else if (tab[j][i] == '4')
				data->heart[j][i] = 15269892;
			j++;
		}
		i++;
	}
}

void	initialize_heart(t_data *data)
{
	char *tab[11];

	tab[0] = "00110001100";
	tab[1] = "01221012210";
	tab[2] = "12342124421";
	tab[3] = "12344244421";
	tab[4] = "12444444421";
	tab[5] = "12444444421";
	tab[6] = "01244444210";
	tab[7] = "00124442100";
	tab[8] = "00012421000";
	tab[9] = "00001210000";
	tab[10] = "00000100000";
	initialize_heart2(data, tab);
}

void	put_sprite_id(t_data *data)
{
	int i;

	i = 0;
	while (i < data->sprite_num)
	{
		if (data->map[(int)data->sprite[i][1]][(int)data->sprite[i][0]] == 'j')
			data->sprite[i][4] = 100;
		else if (data->map[(int)data->sprite[i][1]][(int)data->sprite[i][0]]
		== 'k')
			data->sprite[i][4] = 24;
		else if (data->map[(int)data->sprite[i][1]][(int)data->sprite[i][0]]
		== 'l')
			data->sprite[i][4] = 25;
		else if (data->map[(int)data->sprite[i][1]][(int)data->sprite[i][0]]
		== 'm')
			data->sprite[i][4] = 26;
		else if (data->map[(int)data->sprite[i][1]][(int)data->sprite[i][0]]
		== 'n')
			data->sprite[i][4] = 27;
		else if (data->map[(int)data->sprite[i][1]][(int)data->sprite[i][0]]
		== 'o')
			data->sprite[i][4] = 28;
		i++;
	}
}

void	put_heal_at_spawn(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->x_map)
	{
		j = 0;
		while (j < data->y_map)
		{
			if (is_in(data->map[j][i], "NSEW"))
			{
				data->map[j][i] = 'n';
				store_sprite(data, i, j);
				data->sprite[data->sprite_num - 1][4] = 27;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_images_bonus(t_data *data)
{
	int i;

	if (!BONUS)
		return ;
	i = 5;
	while (i < 5 + NUM_SPRITE_BOMUS + NUM_TEXTURE_BONUS)
	{
		data->text[i].img = mlx_xpm_file_to_image(data->mlx, data->text[i].path,
		&data->text[i].width, &data->text[i].height);
		data->text[i].add = mlx_get_data_addr(data->text[i].img,
		&data->text[i].bits_per_pixel, &data->text[i].line_length,
		&data->text[i].endian);
		i++;
	}
	put_sprite_id(data);
	put_heal_at_spawn(data);
}

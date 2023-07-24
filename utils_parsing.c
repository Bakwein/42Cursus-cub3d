/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:48:47 by bmerchin          #+#    #+#             */
/*   Updated: 2021/01/12 15:32:13 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_info(t_data *data)
{
	if (BONUS)
		return ;
	printf("\nYour Map is Correct\n");
	printf("------------------------------\n");
	printf("Screen Size x : %hu\n", data->x_screen_size);
	printf("Screen Size y : %hu\n", data->y_screen_size);
	printf("Floor Color : %d\n", data->floor);
	printf("Ceiling Color : %d\n", data->ceiling);
	printf("------------------------------\n");
	printf("Sprite Texture Path : %s\n", data->text[4].path);
	printf("NO Texture Path : %s\n", data->text[0].path);
	printf("SO Texture Path : %s\n", data->text[1].path);
	printf("WE Texture Path : %s\n", data->text[3].path);
	printf("EA Texture Path : %s\n", data->text[2].path);
	printf("------------------------------\n");
	printf("X Position : %f\n", data->x_pos);
	printf("Y Position : %f\n", data->y_pos);
	printf("Starting Direction : %c\n", data->start_dir);
	printf("Number of Sprite : %d\n", data->sprite_num);
	printf("X Map Size : %d\n", data->x_map);
	printf("Y Map Size : %d\n", data->y_map);
}

int		free_struct(t_data *data, int m)
{
	int i;

	free(data->text[0].path);
	free(data->text[1].path);
	free(data->text[2].path);
	free(data->text[3].path);
	free(data->text[4].path);
	if (BONUS)
	{
		i = 5;
		while (i < 5 + NUM_SPRITE_BOMUS + NUM_TEXTURE_BONUS)
		{
			free(data->text[i].path);
			i++;
		}
	}
	i = -1;
	if (m == 1)
	{
		while (++i <= data->y_map)
			free(data->map[i]);
	}
	return (0);
}

void	print_map(t_data *data)
{
	int i;

	i = 0;
	if (BONUS)
		return ;
	printf("---------------------------------\n");
	while (i < data->y_map)
	{
		printf("%s\n", data->map[i]);
		i++;
	}
	printf("---------------------------------\n");
}

void	store_sprite(t_data *data, int x, int y)
{
	data->sprite_num++;
	if (data->map[y][x] == '2')
		data->crew++;
	if (data->sprite_num > 499)
		return ;
	data->sprite[data->sprite_num - 1][0] = x + 0.5;
	data->sprite[data->sprite_num - 1][1] = y + 0.5;
	data->sprite[data->sprite_num - 1][2] = (double)data->map[y][x] + 0.5;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:45:12 by bmerchin          #+#    #+#             */
/*   Updated: 2021/02/24 15:45:13 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	heal_at_spawn(t_data *data)
{
	if (!BONUS)
		return ;
	if (data->map[(int)data->y_pos][(int)data->x_pos] == 'n')
	{
		if (data->life < 30 && data->frame % 10 == 0)
			data->life++;
	}
}

void	initialize_the_end(t_data *data)
{
	int		i;
	int		j;
	char	*tab[5];

	tab[0] = "000001011010000111111000010111010001";
	tab[1] = "110111011010111111111011110011010110";
	tab[2] = "110111000010001111111000110101010110";
	tab[3] = "110111011010111111111011110110010110";
	tab[4] = "110111011010000111111000010111010001";
	i = 0;
	while (i < 36)
	{
		j = 0;
		while (j < 5)
		{
			if (tab[j][i] == '0')
				data->the_end[j][i] = 16709366;
			else
				data->the_end[j][i] = 0;
			j++;
		}
		i++;
	}
}

void	add_the_end(t_data *data)
{
	int i;
	int j;
	int k;
	int w_center;
	int h_center;

	i = 0;
	w_center = data->x_screen_size / 2 - 148;
	h_center = data->y_screen_size / 2 - 50;
	while (i < 5)
	{
		j = 0;
		while (j < 36 && j * 8 < data->x_screen_size)
		{
			k = -1;
			while (++k < 64)
			{
				if (data->the_end[i][j] == 16709366)
					ft_mlx_pixel_put(data, j * 8 + k / 8 + w_center,
					i * 8 + k % 8 + h_center, 16709366);
			}
			j++;
		}
		i++;
	}
}

void	echo_the_end(t_data *data)
{
	int i;
	int j;

	i = 0;
	if (data->x_screen_size < 400 || data->y_screen_size < 150)
		return ;
	while (i < data->x_screen_size)
	{
		j = 0;
		while (j < data->y_screen_size)
		{
			ft_mlx_pixel_put(data, i, j, 1);
			j++;
		}
		i++;
	}
	if (data->v_bool_print_score == 0 && data->life > 0 && data->victory == 1)
	{
		printf("Good Game! Your final score is %d frames. ", data->frame);
		printf("You can try again to get a lower time.\n");
		if (ft_strncmp_loc(data->av, "mapbonus_lvl0.cub", 18) == 0)
			printf("Congratulations, Green was the Impostor.\n");
	}
	data->v_bool_print_score = 1;
	add_the_end(data);
}

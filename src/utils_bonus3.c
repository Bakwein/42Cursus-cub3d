/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:25:29 by stunca            #+#    #+#             */
/*   Updated: 2023/08/06 12:25:29 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	add_the_end(t_data *data)
{
	int	i;
	int	j;
	int	k;
	int	w_center;
	int	h_center;

	i = 0;
	w_center = data->x_screen_size / 2 - 148;
	h_center = data->y_screen_size / 2 - 50;
	while (i < 19)
	{
		j = 0;
		while (j < 36 && j * 8 < data->x_screen_size)
		{
			k = -1;
			while (++k < 64)
			{
				if (data->the_end[i][j] != 0)
					ft_mlx_pixel_put(data, j * 8 + k / 8 + w_center,
						i * 8 + k % 8 + h_center, data->the_end[i][j]);
			}
			j++;
		}
		i++;
	}
}

void	echo_the_end(t_data *data)
{
	int	i;
	int	j;

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
		if (ft_strncmp_loc(data->av, "maps/mapbonus_lvl0.cub", 23) == 0)
			printf("Congratulations, Green was the Impostor.\n");
	}
	data->v_bool_print_score = 1;
	add_the_end(data);
}

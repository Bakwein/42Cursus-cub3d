/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:06:22 by bmerchin          #+#    #+#             */
/*   Updated: 2023/07/25 23:10:55 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	clean_exit(int keycode, t_data *data)
{
	if (keycode == KEY_ESCAPE)
		data->escape = 1;
	return (0);
}

#if LINUX == 1

int	exit_free(t_data *data)
{
	int i;

	i = 0;
	if (BONUS)
		echo_the_end(data);
	free_struct(data, 1);
	mlx_destroy_image(data->mlx, data->img);
	while (i < 5 + BONUS * (NUM_SPRITE_BOMUS + NUM_TEXTURE_BONUS))
	{
		mlx_destroy_image(data->mlx, data->text[i].img);
		i++;
	}
	if (data->save == 0)
		mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

#else

int	exit_free(t_data *data)
{
	int i;

	i = 0;
	if (BONUS)
		echo_the_end(data);
	free_struct(data, 1);
	mlx_destroy_image(data->mlx, data->img);
	while (i < 5 + BONUS * (NUM_SPRITE_BOMUS + NUM_TEXTURE_BONUS))
	{
		mlx_destroy_image(data->mlx, data->text[i].img);
		i++;
	}
	if (data->save == 0)
		mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	exit(0);
}

#endif

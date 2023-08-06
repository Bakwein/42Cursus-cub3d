/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:19:12 by stunca            #+#    #+#             */
/*   Updated: 2023/08/06 12:19:12 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	clean_exit(int keycode, t_data *data)
{
	if (keycode == KEY_ESCAPE)
		data->escape = 1;
	return (0);
}

int	exit_free(t_data *data)
{
	int	i;

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
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

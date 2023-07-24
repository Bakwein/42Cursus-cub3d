/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:53:02 by bmerchin          #+#    #+#             */
/*   Updated: 2021/02/23 10:53:04 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_hud(t_data *data)
{
	int i;
	int j;
	int center_w;
	int center_h;

	i = -7;
	j = -7;
	center_w = data->x_screen_size / 2;
	center_h = data->y_screen_size / 2;
	if (data->x_screen_size < 400 || data->y_screen_size < 300)
		return ;
	while (++i < 8)
	{
		ft_mlx_pixel_put(data, center_w + i, center_h, 131072);
		ft_mlx_pixel_put(data, center_w + i, center_h + 1, 131072);
	}
	while (++j < 8)
	{
		ft_mlx_pixel_put(data, center_w, center_h + j, 131072);
		ft_mlx_pixel_put(data, center_w + 1, center_h + j, 131072);
	}
}

void	add_lifebar2(t_data *data, int i, int a, int b)
{
	int j;

	j = 0;
	while (j < 11)
	{
		if (data->heart[i][j] != 0)
			ft_mlx_pixel_put(data, j + b, a + i, data->heart[i][j]);
		j++;
	}
}

void	add_lifebar(t_data *data)
{
	int i;
	int k;
	int a;
	int b;

	k = 0;
	b = 10;
	a = data->y_screen_size - 21;
	if (data->x_screen_size < 400 || data->y_screen_size < 50)
		return ;
	while (k < (data->life + 2) / 3)
	{
		i = 0;
		while (i < 11)
		{
			add_lifebar2(data, i, a, b);
			i++;
		}
		b += 15;
		k++;
	}
}

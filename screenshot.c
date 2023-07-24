/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:07:48 by bmerchin          #+#    #+#             */
/*   Updated: 2021/02/23 11:07:49 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_top_info(t_data *data, int fd)
{
	int buff;
	int i;

	write(fd, "BM", 2);
	buff = 14 + 40 + 4 * data->x_screen_size * data->y_screen_size;
	write(fd, &buff, 4);
	buff = 0;
	write(fd, &buff, 4);
	buff = 54;
	write(fd, &buff, 4);
	buff = 40;
	write(fd, &buff, 4);
	buff = data->x_screen_size;
	write(fd, &buff, 4);
	buff = data->y_screen_size;
	write(fd, &buff, 4);
	buff = 1;
	write(fd, &buff, 2);
	buff = data->bits_per_pixel;
	write(fd, &buff, 2);
	buff = 0;
	i = 0;
	while (i++ < 6)
		write(fd, &buff, 4);
}

void	screenshot(t_data *data)
{
	int fd;
	int	x;
	int	y;

	fd = open("screenshot.bmp", O_CREAT | O_RDWR);
	bmp_top_info(data, fd);
	y = data->y_screen_size - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->x_screen_size)
		{
			write(fd, &data->addr[y * data->line_length + x * 4], 4);
			x++;
		}
		y--;
	}
}

void	save_image(t_data *data)
{
	if (data->save == 1)
	{
		if (MINIMAP_SIZE * data->x_map <= data->x_screen_size &&
		MINIMAP_SIZE * data->y_map <= data->y_screen_size && BONUS)
		{
			add_minimap_and_company(data);
			add_lifebar(data);
			add_hud(data);
		}
		screenshot(data);
		exit_free(data);
	}
}

#if LINUX == 1

void	screen_resize(t_data *data)
{
	int x;
	int y;

	mlx_get_screen_size(data->mlx, &x, &y);
	if (data->x_screen_size > x && data->save == 0)
		data->x_screen_size = x;
	if (data->y_screen_size > y && data->save == 0)
		data->y_screen_size = y;
}

#else

void	screen_resize(t_data *data)
{
	(void)data;
}

#endif

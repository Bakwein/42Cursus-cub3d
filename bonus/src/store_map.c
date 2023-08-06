/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:21:41 by stunca            #+#    #+#             */
/*   Updated: 2023/08/06 17:49:06 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	store_map2(int fd, t_data *data)
{
	while ((get_next_line(fd, &data->map[data->y_map])) == 1 || \
	data->map[data->y_map][0] != '\0')
	{
		data->y_map = data->y_map + 1;
		if (data->y_map == 1024)
		{
			ft_putstr_bn("Error\nYour Map Is Too Long");
			break ;
		}
	}
}

void	store_map(int fd, t_data *data)
{
	int	i;

	data->y_map = 0;
	while (get_next_line(fd, &data->map[0]) == 1)
	{
		i = 0;
		while (i < ft_strlen(data->map[0]))
		{
			if (is_in(data->map[0][i], data->wl))
			{
				data->y_map = 1;
				break ;
			}
			i++;
		}
		if (is_in(data->map[0][i], data->wl))
			break ;
		if (data->map[0][0] != 0)
			data->security[9] += 1;
		free(data->map[0]);
	}
	store_map2(fd, data);
}

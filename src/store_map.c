/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:36:15 by bmerchin          #+#    #+#             */
/*   Updated: 2023/07/25 23:58:18 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	store_map2(int fd, t_data *data, int retour)
{
	while ((retour = get_next_line(fd, &data->map[data->y_map])) == 1 || \
	data->map[data->y_map][0] != '\0')
	{
		if (!BONUS)
			ft_putstr_bn(data->map[data->y_map]);
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
	int	retour;
	int	i;

	data->y_map = 0;
	while ((retour = get_next_line(fd, &data->map[0])) == 1)//map kismini bulmaya calisiyor.ve nasıl önceki kaldığı yerden devam ediyor?.sanirim sadece bir kere calisir.
	{
		if (!BONUS)
			ft_putstr_bn(data->map[0]);
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
		if (is_in(data->map[0][i], data->wl)) // bu neden?
			break ;
		free(data->map[0]);
	}
	store_map2(fd, data, retour);
}

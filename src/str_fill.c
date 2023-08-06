/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:25:08 by stunca            #+#    #+#             */
/*   Updated: 2023/08/06 12:25:09 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	str_fill_helper(char *new, t_data *data)
{
	if (!new)
	{
		printf("Error\nMalloc failed\n");
		data->security[11] = 1;
		return (0);
	}
	else
		return (1);
}

char	*str_fill(char *str, int len, t_data *data)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = -1;
	new = malloc(sizeof(char) * (ft_strlen(str) + len + 1));
	if (!str_fill_helper(new, data))
		return (str);
	while (str[i])
	{
		if (str[i] == ' ')
			new[i] = '1';
		else
			new[i] = str[i];
		i++;
	}
	while (++j < len)
		new[i + j] = '1';
	new[i + j] = '\0';
	free(str);
	return (new);
}

void	fill_map_one(t_data *data)
{
	int	i;

	i = 0;
	data->x_map = 0;
	while (i < data->y_map)
	{
		if (ft_strlen(data->map[i]) > data->x_map)
			data->x_map = ft_strlen(data->map[i]); 
		i++;
	}
	i = 0;
	while (i < data->y_map)
	{
		data->map[i] = str_fill(data->map[i],
				data->x_map - ft_strlen(data->map[i]), data);
		i++;
	}
}

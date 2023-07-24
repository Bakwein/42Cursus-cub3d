/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:28:23 by bmerchin          #+#    #+#             */
/*   Updated: 2021/01/12 15:59:59 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	store_fc(t_data *data, int i, char *line)
{
	unsigned short	red;
	unsigned short	green;
	unsigned short	blue;

	red = ft_atoi_parsing(line, &i);
	store_fc2(line[i], &i, &red);
	green = ft_atoi_parsing(line, &i);
	store_fc2(line[i], &i, &red);
	blue = ft_atoi_parsing(line, &i);
	if (line[i] != '\0')
		blue = 1000;
	if (red < 0 || green < 0 || blue < 0 ||
	red > 255 || green > 255 || blue > 255)
		data->security[1] += 2;
	if (line[0] == 'F')
	{
		data->floor = store_color(0, red, green, blue);
		data->security[1] += 1;
	}
	else
	{
		data->ceiling = store_color(0, red, green, blue);
		data->security[2] += 1;
	}
}

void	store_rfc(t_data *data, char *line)
{
	int i;

	i = 1;
	if (line[0] == 'R')
	{
		data->x_screen_size = ft_atoi_parsing(line, &i);
		data->y_screen_size = ft_atoi_parsing(line, &i);
		if (line[i] != '\0')
			data->security[0] += 1;
		data->security[0] += 1;
	}
	else
		store_fc(data, i, line);
}

void	store_nswe(t_data *data, char *line)
{
	int i;

	i = 3;
	while (line[i] == ' ')
		i++;
	if (line[0] == 'N')
	{
		data->text[0].path = ft_strdup(&line[i]);
		data->security[4] += 1;
	}
	else if (line[0] == 'S')
	{
		data->text[1].path = ft_strdup(&line[i]);
		data->security[5] += 1;
	}
	else if (line[0] == 'W')
	{
		data->text[2].path = ft_strdup(&line[i]);
		data->security[6] += 1;
	}
	else if (line[0] == 'E')
	{
		data->text[3].path = ft_strdup(&line[i]);
		data->security[7] += 1;
	}
}

void	store_path(t_data *data, char *line)
{
	int i;

	if (line[0] == 'S' && line[1] == ' ')
	{
		i = 2;
		while (line[i] == ' ')
			i++;
		data->text[4].path = ft_strdup(&line[i]);
		data->security[3] += 1;
	}
	else if ((is_in(line[0], "GTHUIVJWK")) && line[1] == ' ')
		store_path1(data, line);
	else if ((is_in(line[0], "aLbMcNdOe")) && line[1] == ' ')
		store_path2(data, line);
	else if ((is_in(line[0], "PfQghklmn")) && line[1] == ' ')
		store_path3(data, line);
	else if ((is_in(line[0], "o.,_@#$")) && line[1] == ' ')
		store_path4(data, line);
	else
		store_nswe(data, line);
}

void	store_info(int fd, t_data *data, char *line)
{
	int retour;

	data->sprite_num = 0;
	data->wl = "1.,_@#$";
	while ((retour = get_next_line(fd, &line)) == 1)
	{
		if (!BONUS)
			ft_putstr_bn(line);
		if (is_in(line[0], "RFC") && line[1] == ' ')
			store_rfc(data, line);
		else if (long_condition(line))
			store_path(data, line);
		else
		{
			if (line[0] != 0)
				break ;
		}
		free(line);
		if (data->security[0] == 1 && data->security[1] == 1 &&
		data->security[2] == 1 && data->security[3] == 1 +
		(NUM_SPRITE_BOMUS + NUM_TEXTURE_BONUS) * BONUS &&
		data->security[4] == 1 && data->security[5] == 1 &&
		data->security[6] == 1 && data->security[7] == 1)
			break ;
	}
}

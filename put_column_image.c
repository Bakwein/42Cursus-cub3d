/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_column_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 11:23:58 by bmerchin          #+#    #+#             */
/*   Updated: 2021/02/23 11:23:59 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	determine_id_bonus(t_data *data, int *id)
{
	if (data->map[data->y_raymap][data->x_raymap] == '5')
		*id = 1;
	else if (data->map[data->y_raymap][data->x_raymap] == '.')
		*id = 33;
	else if (data->map[data->y_raymap][data->x_raymap] == ',')
		*id = 34;
	else if (data->map[data->y_raymap][data->x_raymap] == '_')
		*id = 35;
	else if (data->map[data->y_raymap][data->x_raymap] == '@')
		*id = 36;
	else if (data->map[data->y_raymap][data->x_raymap] == '#')
		*id = 37;
	else if (data->map[data->y_raymap][data->x_raymap] == '$')
		*id = 38;
	else if (data->side == 1 && data->y_ray_dir > 0)
		*id = 2;
}

void	determine_id(t_data *data, int *id)
{
	if (data->side == 0)
	{
		if (data->x_ray_dir > 0)
			*id = 3;
		else
			*id = 2;
	}
	else
	{
		if (data->y_ray_dir < 0)
			*id = 0;
		else
			*id = 1;
	}
	if (!BONUS)
		return ;
	determine_id_bonus(data, id);
}

void	texture_calculation(t_data *data, double *step,
		double *tex_pos, int *id)
{
	if (data->side == 0)
		data->wall_hit = data->y_pos + data->dist_wall * data->y_ray_dir;
	else
		data->wall_hit = data->x_pos + data->dist_wall * data->x_ray_dir;
	data->wall_hit -= floor(data->wall_hit);
	data->x_texture = (int)(data->wall_hit * (double)(data->text[*id].width));
	if (data->side == 0 && data->x_ray_dir < 0)
		data->x_texture = data->text[*id].width - data->x_texture - 1;
	if (data->side == 1 && data->y_ray_dir > 0)
		data->x_texture = data->text[*id].width - data->x_texture - 1;
	*step = 1.0 * data->text[*id].height / data->line_size;
	*tex_pos = (data->line_start - data->y_screen_size / 2 +
	data->line_size / 2 - data->crouch) * (*step);
}

void	put_column_image(t_data *data, int column)
{
	int		i;
	double	step;
	double	tex_pos;
	int		id;

	i = -1;
	while (++i < data->line_start)
		ft_mlx_pixel_put(data, column, i, data->ceiling);
	determine_id(data, &id);
	texture_calculation(data, &step, &tex_pos, &id);
	while (i < data->line_end)
	{
		data->y_texture = (int)tex_pos & (data->text[id].height - 1);
		tex_pos += step;
		*(unsigned int *)(data->addr + (i * data->line_length + column * 4)) =
		*(unsigned int *)(data->text[id].add +
		data->y_texture * data->text[id].line_length + data->x_texture * 4);
		i++;
	}
	while (i < data->y_screen_size)
	{
		ft_mlx_pixel_put(data, column, i, data->floor);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 15:45:12 by bmerchin          #+#    #+#             */
/*   Updated: 2021/02/24 15:45:13 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		is_in(char c, char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int		ft_strncmp_loc(const char *s1, const char *s2, int n)
{
	int i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i] && i + 1 < n)
		i++;
	return (s1[i] - s2[i]);
}

void	victory_exit_check(t_data *data)
{
	if (BONUS && (int)data->x_pos == 1 && (int)data->y_pos == 3
	&& ft_strncmp_loc(data->av, "mapbonus_lvl0.cub", 18) == 0)
		data->victory = 1;
	if (BONUS && data->crew == 0
	&& ft_strncmp_loc(data->av, "mapbonus_the_skeld.cub", 23) == 0)
		data->victory = 1;
	if (data->escape == 1 || data->victory == 1)
		exit_free(data);
}

void	search_and_replace(t_data *data, int y, int x)
{
	int i;

	i = 0;
	printf("Kill confirmed, %d crew members left\n", data->crew);
	data->attack--;
	if (data->frame % 10 == 0)
		close_door(data);
	while (i < data->sprite_num)
	{
		if ((int)data->sprite[i][0] == x && (int)data->sprite[i][1] == y)
		{
			data->sprite[i][4] += 1;
			return ;
		}
		i++;
	}
}

void	attack_if_possible(t_data *data)
{
	int i;

	i = -1;
	if (!BONUS)
		return ;
	if (data->attack == 300)
	{
		while (++i < 9)
		{
			if (data->map[(int)data->y_pos
			+ i % 3 - 1][(int)data->x_pos + i / 3 - 1] == '2')
			{
				data->crew--;
				data->map[(int)data->y_pos
				+ i % 3 - 1][(int)data->x_pos + i / 3 - 1] = '0';
				search_and_replace(data, (int)data->y_pos
				+ i % 3 - 1, (int)data->x_pos + i / 3 - 1);
				return ;
			}
		}
		data->attack = 0;
	}
	if (data->attack > 0)
		data->attack--;
}

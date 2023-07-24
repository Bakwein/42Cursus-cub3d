/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_norme.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:04:59 by bmerchin          #+#    #+#             */
/*   Updated: 2021/01/09 18:31:18 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		long_condition(char *line)
{
	if ((line[0] == 'S' && line[1] == ' ') || (is_in(line[0],
		"TUVWabcdefghklmno.,_@#$GHIJKLMNOPQ") &&
			line[1] == ' ' && BONUS) || (((line[0] == 'N' &&
			line[1] == 'O') || (line[0] == 'S' && line[1] == 'O') ||
			(line[0] == 'W' && line[1] == 'E') || (line[0] == 'E' &&
			line[1] == 'A')) && line[2] == ' '))
		return (1);
	return (0);
}

void	store_path1(t_data *data, char *line)
{
	int i;

	i = 2;
	while (line[i] == ' ')
		i++;
	data->security[3] += 1;
	if (line[0] == 'G')
		data->text[5].path = ft_strdup(&line[i]);
	else if (line[0] == 'T')
		data->text[6].path = ft_strdup(&line[i]);
	else if (line[0] == 'H')
		data->text[7].path = ft_strdup(&line[i]);
	else if (line[0] == 'U')
		data->text[8].path = ft_strdup(&line[i]);
	else if (line[0] == 'I')
		data->text[9].path = ft_strdup(&line[i]);
	else if (line[0] == 'V')
		data->text[10].path = ft_strdup(&line[i]);
	else if (line[0] == 'J')
		data->text[11].path = ft_strdup(&line[i]);
	else if (line[0] == 'W')
		data->text[12].path = ft_strdup(&line[i]);
	else if (line[0] == 'K')
		data->text[13].path = ft_strdup(&line[i]);
}

void	store_path2(t_data *data, char *line)
{
	int i;

	i = 2;
	while (line[i] == ' ')
		i++;
	data->security[3] += 1;
	if (line[0] == 'a')
		data->text[14].path = ft_strdup(&line[i]);
	else if (line[0] == 'L')
		data->text[15].path = ft_strdup(&line[i]);
	else if (line[0] == 'b')
		data->text[16].path = ft_strdup(&line[i]);
	else if (line[0] == 'M')
		data->text[17].path = ft_strdup(&line[i]);
	else if (line[0] == 'c')
		data->text[18].path = ft_strdup(&line[i]);
	else if (line[0] == 'N')
		data->text[19].path = ft_strdup(&line[i]);
	else if (line[0] == 'd')
		data->text[20].path = ft_strdup(&line[i]);
	else if (line[0] == 'O')
		data->text[21].path = ft_strdup(&line[i]);
	else if (line[0] == 'e')
		data->text[22].path = ft_strdup(&line[i]);
}

void	store_path3(t_data *data, char *line)
{
	int i;

	i = 2;
	while (line[i] == ' ')
		i++;
	data->security[3] += 1;
	if (line[0] == 'P')
		data->text[23].path = ft_strdup(&line[i]);
	else if (line[0] == 'f')
		data->text[24].path = ft_strdup(&line[i]);
	else if (line[0] == 'Q')
		data->text[25].path = ft_strdup(&line[i]);
	else if (line[0] == 'g')
		data->text[26].path = ft_strdup(&line[i]);
	else if (line[0] == 'h')
		data->text[27].path = ft_strdup(&line[i]);
	else if (line[0] == 'k')
		data->text[28].path = ft_strdup(&line[i]);
	else if (line[0] == 'l')
		data->text[29].path = ft_strdup(&line[i]);
	else if (line[0] == 'm')
		data->text[30].path = ft_strdup(&line[i]);
	else if (line[0] == 'n')
		data->text[31].path = ft_strdup(&line[i]);
}

void	store_path4(t_data *data, char *line)
{
	int i;

	i = 2;
	while (line[i] == ' ')
		i++;
	data->security[3] += 1;
	if (line[0] == 'o')
		data->text[32].path = ft_strdup(&line[i]);
	else if (line[0] == '.')
		data->text[33].path = ft_strdup(&line[i]);
	else if (line[0] == ',')
		data->text[34].path = ft_strdup(&line[i]);
	else if (line[0] == '_')
		data->text[35].path = ft_strdup(&line[i]);
	else if (line[0] == '@')
		data->text[36].path = ft_strdup(&line[i]);
	else if (line[0] == '#')
		data->text[37].path = ft_strdup(&line[i]);
	else if (line[0] == '$')
		data->text[38].path = ft_strdup(&line[i]);
}

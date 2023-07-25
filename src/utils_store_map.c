/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_store_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:28:23 by bmerchin          #+#    #+#             */
/*   Updated: 2023/07/25 23:48:56 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	store_fc(t_data *data, int i, char *line)
{
	unsigned short	red;
	unsigned short	green;
	unsigned short	blue;

	red = ft_atoi_parsing(line, &i); //i artiyor
	store_fc2(line[i], &i, &red);
	green = ft_atoi_parsing(line, &i); //i artiyor
	store_fc2(line[i], &i, &red); // Bu biraz saçma ama mesela yeşilde de aynı sorun olursa kirmiziyi 1000 yapacağından alttaki kisimda zaten hata verecek
	blue = ft_atoi_parsing(line, &i); //i artiyor
	if (line[i] != '\0') // blue atoi sonrasi i. index null olmali yoksa hata vermesi için 1k
		blue = 1000;
	if (red < 0 || green < 0 || blue < 0 ||
	red > 255 || green > 255 || blue > 255)
		data->security[1] += 2; // hata varsa +2, yoksa +1
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
	if (line[0] == 'R') // R ise boyutu ayarlar
	{
		data->x_screen_size = ft_atoi_parsing(line, &i);
		data->y_screen_size = ft_atoi_parsing(line, &i);
		if (line[i] != '\0') // iki atoiden sonra artik i'nin nulla ulasmasi gerekir
			data->security[0] += 1;
		data->security[0] += 1;
	}
	else
		store_fc(data, i, line); //f,c ve i=1
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
	// bonus için TUVWabcdefghklmno.,_@#$GHIJKLMNOPQ kontrolü
	else if ((is_in(line[0], "GTHUIVJWK")) && line[1] == ' ')
		store_path1(data, line);
	else if ((is_in(line[0], "aLbMcNdOe")) && line[1] == ' ')
		store_path2(data, line);
	else if ((is_in(line[0], "PfQghklmn")) && line[1] == ' ')
		store_path3(data, line);
	else if ((is_in(line[0], "o.,_@#$")) && line[1] == ' ')
		store_path4(data, line);
	else
		store_nswe(data, line); //NO,SO,WE,EA
}

void	store_info(int fd, t_data *data, char *line)
{
	int retour;

	data->sprite_num = 0;
	data->wl = "1.,_@#$";
	while ((retour = get_next_line(fd, &line)) == 1) // GET_NEXT_LINE KARIŞIK VE FARKLI!!!!!!!!!
	{
		if (!BONUS)
			ft_putstr_bn(line); //bonus degilse satiri yazdirir
		if (is_in(line[0], "RFC") && line[1] == ' ') //tüm satirlarda ilk karakter R,F,C ve harf sonrasi space kontrolü
			store_rfc(data, line);
		else if (long_condition(line)) // sprite,eşya karakterleri harici bir şey var mı kontrolü
			store_path(data, line);
		else
		{
			if (line[0] != 0) //(?) dosya sonunda break için. NASIL BİLMİYORUM AMA MAP'E KADAR OKUYOR.
				break ;
		}
		free(line);
		if (data->security[0] == 1 && data->security[1] == 1 && \
		data->security[2] == 1 && data->security[3] == 1 + \
		(NUM_SPRITE_BOMUS + NUM_TEXTURE_BONUS) * BONUS && \
		data->security[4] == 1 && data->security[5] == 1 && \
		data->security[6] == 1 && data->security[7] == 1)
			break ;
	}
}

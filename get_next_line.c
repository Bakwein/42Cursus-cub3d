/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 03:32:36 by bmerchin          #+#    #+#             */
/*   Updated: 2021/01/08 12:26:21 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strjoin(char *s1, char *s2, t_struct *dta)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlenn(s2) + 1))))
		return (free_null(s1));
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\n' && s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
		dta->curs += 1;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

int		get_next_line2(int fd, char **line, t_struct *dta)
{
	while (dta->ret > 0)
	{
		if (ft_strlen(dta->buff + dta->curs) !=
		ft_strlenn(dta->buff + dta->curs))
		{
			*line = ft_strjoin(*line, dta->buff + dta->curs, dta);
			if (*line == NULL)
				return (-1);
			dta->curs += 1;
			return (1);
		}
		if (dta->curs < dta->ret)
		{
			*line = ft_strjoin(*line, dta->buff + dta->curs, dta);
			if (*line == NULL)
				return (-1);
		}
		dta->ret = read(fd, dta->buff, BUFFER_SIZE);
		if (dta->ret < 0)
			return (free_int(line));
		dta->buff[dta->ret] = '\0';
		dta->curs = 0;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_struct dta[10241];

	if (read(fd, dta[fd].buff, 0) < 0 || fd < 0 || fd > 10240 || line == NULL)
		return (-1);
	*line = (char *)malloc(sizeof(char));
	if (!*line)
		return (-1);
	*line[0] = '\0';
	if (ft_strlen(dta[fd].buff + dta[fd].curs) !=
	ft_strlenn(dta[fd].buff + dta[fd].curs))
	{
		*line = ft_strjoin(*line, dta[fd].buff + dta[fd].curs, &dta[fd]);
		if (*line == NULL)
			return (-1);
		dta[fd].curs += 1;
		return (1);
	}
	if (dta[fd].ret == 0)
	{
		dta[fd].ret = read(fd, dta[fd].buff, BUFFER_SIZE);
		if (dta[fd].ret < 0)
			return (free_int(line));
		dta[fd].buff[dta[fd].ret] = '\0';
	}
	return (get_next_line2(fd, line, &dta[fd]));
}

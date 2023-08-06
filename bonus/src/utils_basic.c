/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:21:51 by stunca            #+#    #+#             */
/*   Updated: 2023/08/06 14:01:18 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_putstr_bn(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (sign == 1 && nbr > 922337203685477580)
			return (-1);
		else if (nbr > 922337203685477580)
			return (0);
		nbr = nbr * 10 + str[i++] - '0';
	}
	return (nbr * sign);
}

int	ft_atoi_parsing(char *str, int *i)
{
	int		sign;
	long	nbr;
	int		temp;

	nbr = 0;
	sign = 1;
	while (str[*i] && ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' '))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	temp = *i;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		nbr = nbr * 10 + str[*i] - '0';
		(*i)++;
	}
	if (temp == *i)
		return (-1);
	return (nbr * sign);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = ft_strlen(s1);
	new = malloc(sizeof(char) * len + 1);
	if (!(new))
		return (0);
	while (i < len)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

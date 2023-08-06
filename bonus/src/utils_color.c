/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:22:17 by stunca            #+#    #+#             */
/*   Updated: 2023/08/06 12:22:19 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_t(int i)
{
	i /= 256;
	i /= 256;
	i /= 256;
	return (i % 256);
}

int	get_r(int i)
{
	i /= 256;
	i /= 256;
	return (i % 256);
}

int	get_g(int i)
{
	i /= 256;
	return (i % 256);
}

int	get_b(int i)
{
	return (i % 256);
}

int	store_color(int i, int j, int k)
{
	int	color;

	color = (((i * 256) + j) * 256) + k;
	return (color);
}

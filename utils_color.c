/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerchin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:04:59 by bmerchin          #+#    #+#             */
/*   Updated: 2021/01/09 18:31:18 by bmerchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	store_color(int i, int j, int k, int l)
{
	int color;

	color = i;
	color *= 256;
	color += j;
	color *= 256;
	color += k;
	color *= 256;
	color += l;
	return (color);
}

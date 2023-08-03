/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsozan <hsozan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:04:59 by bmerchin          #+#    #+#             */
/*   Updated: 2023/07/31 13:54:07 by hsozan           ###   ########.fr       */
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

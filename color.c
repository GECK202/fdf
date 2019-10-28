/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:39:08 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/23 20:53:20 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	red(int color)
{
	return ((color >> 16) & 0xff);
}

int	green(int color)
{
	return ((color >> 8) & 0xff);
}

int	blue(int color)
{
	return (color & 0xff);
}

int	color(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

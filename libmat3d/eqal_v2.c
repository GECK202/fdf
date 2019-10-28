/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eqal_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:38:44 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/16 20:39:00 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat3d.h"

void	eqal_v2(t_v2 *dst, t_v2 src)
{
	dst->x = src.x;
	dst->y = src.y;
}

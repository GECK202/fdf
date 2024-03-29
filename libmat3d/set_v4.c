/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_v4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:37:42 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/16 20:38:01 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat3d.h"

t_v4	set_v4(double x, double y, double z, double w)
{
	t_v4	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}

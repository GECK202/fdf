/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_m4_rz.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:58:46 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/16 20:58:58 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat3d.h"

void	set_m4_rz(t_m4 *m, double fi)
{
	double s;
	double c;

	s = sin(fi * M_PI / 180);
	c = cos(fi * M_PI / 180);
	m->f0 = set_v4(c, -s, 0, 0);
	m->f1 = set_v4(s, c, 0, 0);
	m->f2 = set_v4(0, 0, 1, 0);
	m->f3 = set_v4(0, 0, 0, 1);
}

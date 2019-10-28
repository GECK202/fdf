/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_m4_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 20:57:39 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/17 22:34:15 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mat3d.h"

void	set_m4_s(t_m4 *m, double s, double amp)
{
	m->f0 = set_v4(s, 0, 0, 0);
	m->f1 = set_v4(0, s, 0, 0);
	m->f2 = set_v4(0, 0, (s + (amp * s / 100)), 0);
	m->f3 = set_v4(0, 0, 0, 1);
}
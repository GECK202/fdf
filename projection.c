/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:08:06 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/22 23:33:55 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection_parall(t_point *pnt, t_param *p)
{
	pnt->pos2d.x = pnt->transf.x + p->img_d.x;
	pnt->pos2d.y = pnt->transf.y + p->img_d.y;
}

void	projection_persp(t_point *pnt, t_param *p)
{
	double k;

	if (pnt->transf.z == 100)
		pnt->transf.z = 99;
	k = fabs(1.0 - (pnt->transf.z * 0.002));
	pnt->pos2d.x = pnt->transf.x / k + p->img_d.x;
	pnt->pos2d.y = pnt->transf.y / k + p->img_d.y;
	if ((pnt->pos2d.x < -p->img_w * 5) || (pnt->pos2d.x > p->img_w * 10) ||
		(pnt->pos2d.y < -p->img_h * 5) || (pnt->pos2d.y > p->img_h * 10))
	{
		pnt->pos2d.x = p->inf;
		pnt->pos2d.y = p->inf;
	}
}

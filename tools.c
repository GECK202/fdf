/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:12:36 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/23 20:49:00 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_param *param)
{
	int cell;

	cell = 0;
	while (cell < param->img_h * param->img_w)
	{
		param->img_data[cell] = param->bgc;
		++cell;
	}
}

void	clear_block(unsigned int *data, t_v2 start, t_v2 end, t_v2 tmp)
{
	int x;
	int y;

	x = start.x;
	while (x < end.x)
	{
		y = start.y;
		while (y < end.y)
		{
			data[y * tmp.x + x] = tmp.y;
			++y;
		}
		++x;
	}
}

int		set_matrix(t_param *p)
{
	set_m4_s(&(p->mrs), p->s, p->amp);
	set_m4_rx(&(p->mrx), p->a);
	set_m4_rz(&(p->mrz), p->c);
	set_m4_pc(&(p->mrpc));
	return (1);
}

void	reset_pos(t_param *p)
{
	p->press1 = 0;
	p->press3 = 0;
	p->a = 45;
	p->c = 45;
	p->view = 0;
	p->an = 0;
	p->cn = 0;
	p->img_d.x = p->img_w / 2 + 50;
	p->img_d.y = p->img_h / 2;
}

void	set_view(t_param *p)
{
	p->a = 0;
	p->c = 0;
	if (p->view == 0)
	{
		p->a = 45;
		p->c = 45;
	}
	if (p->view == 2)
		p->a = 180;
	if (p->view > 2)
		p->a = 90;
	if (p->view == 3)
		p->c = 90;
	else if (p->view == 4)
		p->c = -90;
	else if (p->view == 6)
		p->c = 180;
}

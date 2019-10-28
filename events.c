/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 21:50:21 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/23 20:55:39 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		mouse_move_event(int x, int y, t_param *p)
{
	if (p->press1 == 1)
	{
		p->a += (p->an - y) / 2;
		p->c += (p->cn - x) / 2;
		p->an = y;
		p->cn = x;
		if (p->a > 360)
			p->a -= 360;
		if (p->c > 360)
			p->c -= 360;
		if (p->a < 0)
			p->a += 360;
		if (p->c < 0)
			p->c += 360;
		set_matrix(p);
	}
	if (p->press3)
	{
		p->img_d.x += (x - p->pad.x);
		p->img_d.y += (y - p->pad.y);
		p->pad.x = x;
		p->pad.y = y;
	}
	return (0);
}

int		mouse_down_event(int button, int x, int y, t_param *p)
{
	if (button == 5)
		p->s /= 2;
	if (button == 4)
		p->s *= 2;
	if (button == 1 && p->press1 == 0)
	{
		if (x < 200)
			check_mouse(p, x, y);
		else
		{
			p->an = y;
			p->cn = x;
			p->press1 = 1;
		}
	}
	if (button == 2)
		reset_pos(p);
	if (button == 3 && p->press3 == 0)
	{
		p->press3 = 1;
		p->pad.x = x;
		p->pad.y = y;
	}
	set_matrix(p);
	return (0);
}

int		mouse_up_event(int button, int x, int y, t_param *p)
{
	p->an = x;
	p->cn = y;
	if (button == 1)
	{
		p->press1 = 0;
		p->an = 0;
		p->cn = 0;
		p->view = 0;
	}
	if (button == 3)
	{
		p->press3 = 0;
		p->an = 0;
		p->cn = 0;
	}
	return (0);
}

int		key_event(int key, t_param *p)
{
	if (key == 18)
		p->proj = 1;
	if (key == 19)
		p->proj = 2;
	if (key == 49)
	{
		++(p->view);
		if (p->view == 7)
			p->view = 0;
		p->an = 0;
		p->cn = 0;
		set_view(p);
		set_matrix(p);
	}
	if (key == 53)
	{
		mlx_destroy_window(p->mlx_p, p->win_p);
		free(p->points);
		exit(0);
	}
	return (0);
}

int		key_down(int key, t_param *p)
{
	if (key == 0)
		p->amp += 5;
	if (key == 6)
		p->amp -= 5;
	set_matrix(p);
	return (0);
}

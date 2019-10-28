/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:16:02 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/23 18:36:51 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_color(t_point p0, t_point p1, int i, int len)
{
	int		col;
	int		r;
	int		g;
	int		b;
	double	dx;

	col = p0.color;
	if (!len)
		return (col);
	dx = (double)i / len;
	r = red(p0.color) * (1.0 - dx) + red(p1.color) * dx;
	g = green(p0.color) * (1.0 - dx) + green(p1.color) * dx;
	b = blue(p0.color) * (1.0 - dx) + blue(p1.color) * dx;
	col = color(r, g, b);
	return (col);
}

static void	inc_sx(t_v2 tmp, t_v2 *cur, t_v2 s)
{
	if (tmp.x == 1)
		cur->x += s.x;
	else
		cur->y += s.y;
}

static void	inc_sy(t_v2 tmp, t_v2 *cur, t_v2 s)
{
	if (tmp.x == 1)
		cur->y += s.y;
	else
		cur->x += s.x;
}

static void	init_line(t_v2 *tmp, t_v2 *d, int *error)
{
	tmp->x = 0;
	if (d->y > d->x)
	{
		ft_swap(&(d->x), &(d->y));
		tmp->x = 1;
	}
	*error = 2 * d->y - d->x;
	tmp->y = 0;
}

void		draw_line(t_point p0, t_point p1, t_param *p)
{
	t_v2	d;
	int		error;
	t_v2	s;
	t_v2	cur;
	t_v2	tmp;

	if ((p0.pos2d.x == p->inf) || (p1.pos2d.x == p->inf))
		return ;
	eqal_v2(&cur, p0.pos2d);
	abs_delta_v2(&d, p0.pos2d, p1.pos2d);
	sign_v2(&(s), p0.pos2d, p1.pos2d);
	init_line(&tmp, &d, &error);
	while (tmp.y++ < d.x)
	{
		if (cur.x >= 200 && cur.x < p->img_w && cur.y >= 0 && cur.y < p->img_h)
			p->img_data[cur.y * p->img_w + cur.x] =
					get_color(p0, p1, tmp.y, d.x);
		while (error >= 0)
		{
			inc_sx(tmp, &cur, s);
			error -= 2 * d.x;
		}
		inc_sy(tmp, &cur, s);
		error += 2 * d.y;
	}
}

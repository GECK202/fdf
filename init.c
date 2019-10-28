/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 21:30:44 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/23 20:49:45 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			init_param(t_param *p, char *file)
{
	p->w = 1600;
	p->h = 1200;
	p->inf = 2147483647;
	p->proj = 1;
	p->s_line = 400;
	p->bpp = 32;
	p->endian = 1;
	p->img_w = 1600;
	p->img_h = 1200;
	p->mlx_p = mlx_init();
	p->win_p = mlx_new_window(p->mlx_p, p->w, p->h, file);
	p->img_p = mlx_new_image(p->mlx_p, p->img_w, p->img_h);
	p->img_data = (unsigned int *)mlx_get_data_addr(p->img_p, &(p->bpp),
					&(p->s_line), &(p->endian));
	p->bgc = 0xA7A7A7;
	p->def_col_min = 0x0880F1;
	p->def_col_mid = 0xEAA40B;
	p->def_col_max = 0xF9F5EB;
	reset_pos(p);
	p->s = 10;
	if (!(init_points(p, file)))
		return (0);
	return (set_matrix(p));
}

static void	set_point(t_param *p, double dx, double dy, t_v2 iter)
{
	int		index;
	t_v2	pos;

	index = iter.y * p->len_map.x + iter.x;
	pos.x = iter.x + dx;
	pos.y = iter.y + dy;
	(p->points)[index].pos.x = pos.x;
	(p->points)[index].pos.y = pos.y;
	(p->points)[index].pos.z = 0;
	(p->points)[index].pos.w = 1;
	(p->points)[index].color = 0;
}

static int	set_color(t_param *p, t_point *pnt, t_v3 extr)
{
	t_v3	col;
	double	pc;

	if (pnt->pos.z > extr.y)
	{
		pc = pnt->pos.z / extr.z;
		col.x = red(p->def_col_max) * pc + red(p->def_col_mid) * (1.0 - pc);
		col.y = green(p->def_col_max) * pc + green(p->def_col_mid) * (1.0 - pc);
		col.z = blue(p->def_col_max) * pc + blue(p->def_col_mid) * (1.0 - pc);
		pnt->color = color(col.x, col.y, col.z);
	}
	else if (pnt->pos.z < extr.y)
	{
		pc = pnt->pos.z / extr.y;
		col.x = red(p->def_col_mid) * pc + red(p->def_col_min) * (1.0 - pc);
		col.y = green(p->def_col_mid) * pc + green(p->def_col_min) * (1.0 - pc);
		col.z = blue(p->def_col_mid) * pc + blue(p->def_col_min) * (1.0 - pc);
		pnt->color = color(col.x, col.y, col.z);
	}
	else
		pnt->color = p->def_col_mid;
	return (1);
}

int			set_scale(t_param *p, int check_c)
{
	int		i;
	t_v3	extr;
	int		col;

	extr.x = 0;
	extr.y = 0;
	extr.z = 0;
	i = 0;
	while (i < p->len_map.x * p->len_map.y)
	{
		extr.x = ft_min(extr.x, p->points[i].pos.z);
		extr.z = ft_max(extr.z, p->points[i].pos.z);
		++i;
	}
	extr.y = (extr.x + extr.z) / 2;
	i = 0;
	while (i < p->len_map.x * p->len_map.y)
	{
		col = p->points[i].color;
		if (!col || check_c)
			set_color(p, &(p->points[i]), extr);
		++i;
	}
	return (1);
}

int			init_points(t_param *p, char *file)
{
	t_v2	iter;
	double	dx;
	double	dy;

	if (!(read_len_map(p, file)))
		return (0);
	p->amp = -80;
	p->s = 1000 / (ft_max(p->len_map.x, p->len_map.y));
	dx = (double)(p->len_map.x - 1) / -2.0;
	dy = (double)(p->len_map.y - 1) / -2.0;
	p->points = (t_point*)malloc(sizeof(t_point) * p->len_map.x * p->len_map.y);
	iter.y = 0;
	while (iter.y < p->len_map.y)
	{
		iter.x = 0;
		while (iter.x < p->len_map.x)
		{
			set_point(p, dx, dy, iter);
			iter.x++;
		}
		iter.y++;
	}
	if (!read_z_color(p, file))
		return (0);
	return (set_scale(p, 0));
}

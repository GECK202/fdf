/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:58:51 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/23 20:52:18 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_grad(t_param *p, int index, t_v3 tmp, t_v3 *col)
{
	int r;
	int g;
	int b;

	r = ft_clamp((col->x + tmp.z), 1, 256) - 1;
	g = ft_clamp((col->y + tmp.z), 1, 256) - 1;
	b = ft_clamp((col->z + tmp.z), 1, 256) - 1;
	p->img_data[index] = color(r, g, b);
	if (tmp.x < 33)
		col->y += 8;
	else if (tmp.x < 65)
		col->x -= 8;
	else if (tmp.x < 97)
		col->z += 8;
	else if (tmp.x < 129)
		col->y -= 8;
	else if (tmp.x < 161)
		col->x += 8;
	else if (tmp.x < 193)
		col->z -= 8;
}

void	draw_grad(t_param *p, int px, int py)
{
	t_v3 tmp;
	t_v3 col;

	tmp.z = 256;
	tmp.y = 0;
	while (tmp.y < 128)
	{
		col.x = 256;
		col.y = 0;
		col.z = 0;
		tmp.x = 1;
		while (tmp.x < 193)
		{
			set_grad(p, (py + tmp.y) * p->img_w + tmp.x + px, tmp, &col);
			++tmp.x;
		}
		tmp.z -= 4;
		++tmp.y;
	}
}

void	draw_menu(t_param *p)
{
	draw_panel(p, 0, 0);
	draw_button(p, 2, 20);
	draw_button(p, 2, 64);
	draw_button(p, 2, 108);
	draw_button(p, 2, 152);
	draw_button(p, 2, 196);
	draw_button(p, 2, 240);
	draw_grad(p, 2, 289);
	draw_grad(p, 2, 449);
	draw_grad(p, 2, 609);
	draw_grad(p, 2, 769);
}

void	draw_panel(t_param *p, int x, int y)
{
	t_v2 start;
	t_v2 end;
	t_v2 tmp;

	start.x = x;
	start.y = y;
	end.x = x + 200;
	end.y = p->img_h - y;
	tmp.x = p->img_w;
	tmp.y = 0x505050;
	clear_block(p->img_data, start, end, tmp);
}

void	draw_button(t_param *p, int x, int y)
{
	t_v2 start;
	t_v2 end;
	t_v2 tmp;

	start.x = x;
	start.y = y;
	end.x = x + 196;
	end.y = y + 20;
	tmp.x = p->img_w;
	tmp.y = 0xc0c0c0;
	clear_block(p->img_data, start, end, tmp);
}

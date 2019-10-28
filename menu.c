/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:46:33 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/23 20:43:13 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_mouse(t_param *p, int x, int y)
{
	if (x < 3 || x > 194)
		return ;
	if (y > 289 && y < 417)
	{
		p->bgc = p->img_data[y * p->img_w + x];
		return ;
	}
	if (y > 449 && y < 577)
		p->def_col_max = p->img_data[y * p->img_w + x];
	else if (y > 609 && y < 733)
		p->def_col_mid = p->img_data[y * p->img_w + x];
	else if (y > 769 && y < 897)
		p->def_col_min = p->img_data[y * p->img_w + x];
	set_scale(p, 1);
}

void	draw_elem_text(t_param *p, int y, char *text, int val)
{
	char *tmp;

	mlx_string_put(p->mlx_p, p->win_p, 6, y, 0xc0c0c0, text);
	tmp = ft_itoa(val);
	mlx_string_put(p->mlx_p, p->win_p, 6, y + 20, 0, tmp);
	free(tmp);
}

void	draw_view(t_param *p)
{
	mlx_string_put(p->mlx_p, p->win_p, 6, 218, 0xc0c0c0, "view:");
	if (p->view == 0)
		mlx_string_put(p->mlx_p, p->win_p, 6, 238, 0, "user");
	else if (p->view == 1)
		mlx_string_put(p->mlx_p, p->win_p, 6, 238, 0, "top");
	else if (p->view == 2)
		mlx_string_put(p->mlx_p, p->win_p, 6, 238, 0, "down");
	else if (p->view == 3)
		mlx_string_put(p->mlx_p, p->win_p, 6, 238, 0, "left");
	else if (p->view == 4)
		mlx_string_put(p->mlx_p, p->win_p, 6, 238, 0, "right");
	else if (p->view == 5)
		mlx_string_put(p->mlx_p, p->win_p, 6, 238, 0, "front");
	else if (p->view == 6)
		mlx_string_put(p->mlx_p, p->win_p, 6, 238, 0, "back");
}

void	draw_text_menu(t_param *p)
{
	draw_elem_text(p, 0, "scale:", (int)(p->s * 1000.0));
	draw_elem_text(p, 44, "rot z:", p->c);
	draw_elem_text(p, 86, "rot x:", p->a);
	draw_elem_text(p, 130, "amp (%):", (int)(100 + p->amp));
	mlx_string_put(p->mlx_p, p->win_p, 6, 174, 0xc0c0c0, "projection:");
	if (p->proj == 1)
		mlx_string_put(p->mlx_p, p->win_p, 6, 192, 0, "parallel");
	else if (p->proj == 2)
		mlx_string_put(p->mlx_p, p->win_p, 6, 192, 0, "perspective");
	draw_view(p);
	mlx_string_put(p->mlx_p, p->win_p, 6, 267, 0xc0c0c0, "background color:");
	mlx_string_put(p->mlx_p, p->win_p, 6, 427, 0xc0c0c0, "top color:");
	mlx_string_put(p->mlx_p, p->win_p, 6, 587, 0xc0c0c0, "middle color:");
	mlx_string_put(p->mlx_p, p->win_p, 6, 747, 0xc0c0c0, "down color:");
	draw_info(p);
}

void	draw_info(t_param *p)
{
	mlx_string_put(p->mlx_p, p->win_p, 206, p->img_h - 150, 0xffffff - p->bgc,
	"|   use mouse with button:    |      use keyboard:          |");
	mlx_string_put(p->mlx_p, p->win_p, 206, p->img_h - 130, 0xffffff - p->bgc,
	"|_____________________________|_____________________________|");
	mlx_string_put(p->mlx_p, p->win_p, 206, p->img_h - 110, 0xffffff - p->bgc,
	"| -left to rotate             | -A/Z to amplitude           |");
	mlx_string_put(p->mlx_p, p->win_p, 206, p->img_h - 90, 0xffffff - p->bgc,
	"| -middle to move             | -1 to parallel projection   |");
	mlx_string_put(p->mlx_p, p->win_p, 206, p->img_h - 70, 0xffffff - p->bgc,
	"| -scroll to scale            | -2 to perspective           |");
	mlx_string_put(p->mlx_p, p->win_p, 206, p->img_h - 50, 0xffffff - p->bgc,
	"| -click LMB color to chahge  | -SPACE to change view       |");
	mlx_string_put(p->mlx_p, p->win_p, 206, p->img_h - 30, 0xffffff - p->bgc,
	"| -right click reset rotation | -ESC to exit                |");
}

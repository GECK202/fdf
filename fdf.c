/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:26:18 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/22 23:50:37 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	mult_matrix(t_param *p)
{
	int i;

	i = 0;
	while (i < p->len_map.x * p->len_map.y)
	{
		mult_vm(&(((p->points)[i]).transf), (((p->points)[i]).pos), p->mrs);
		mult_vm(&(((p->points)[i]).transf), (((p->points)[i]).transf), p->mrz);
		mult_vm(&(((p->points)[i]).transf), (((p->points)[i]).transf), p->mrx);
		if (p->proj == 1)
			projection_parall(&((p->points)[i]), p);
		else if (p->proj == 2)
			projection_persp(&((p->points)[i]), p);
		++i;
	}
}

int			close_win(t_param *p)
{
	mlx_destroy_window(p->mlx_p, p->win_p);
	free(p->points);
	free(p);
	exit(0);
}

int			not_event(t_param *p)
{
	int		i;
	int		j;
	t_point	p0;

	clear_image(p);
	mult_matrix(p);
	j = 0;
	while (j < p->len_map.y)
	{
		i = 0;
		while (i < p->len_map.x)
		{
			p0 = (p->points)[j * p->len_map.x + i];
			if (j < p->len_map.y - 1)
				draw_line(p0, (p->points)[(j + 1) * p->len_map.x + i], p);
			if (i < p->len_map.x - 1)
				draw_line(p0, (p->points)[j * p->len_map.x + i + 1], p);
			++i;
		}
		++j;
	}
	draw_menu(p);
	mlx_put_image_to_window(p->mlx_p, p->win_p, p->img_p, 0, 0);
	draw_text_menu(p);
	return (0);
}

int			main(int ac, char **av)
{
	t_param	*param;

	if (ac == 2)
	{
		param = (t_param *)malloc(sizeof(t_param));
		if (init_param(param, av[1]))
		{
			clear_image(param);
			mlx_key_hook(param->win_p, key_event, (void *)param);
			mlx_mouse_hook(param->win_p, mouse_down_event, (void *)param);
			mlx_loop_hook(param->mlx_p, not_event, (void *)param);
			mlx_hook(param->win_p, 6, 0, mouse_move_event, (void *)param);
			mlx_hook(param->win_p, 5, 0, mouse_up_event, (void *)param);
			mlx_hook(param->win_p, 17, 0, close_win, (void *)param);
			mlx_hook(param->win_p, 2, 0, key_down, (void *)param);
			mlx_loop(param->mlx_p);
			return (0);
		}
	}
	write(1, "Usage : ./fdf <filename> [ case_size z_size ]\n", 46);
	return (0);
}

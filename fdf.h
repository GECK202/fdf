/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 21:53:17 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/23 20:49:59 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "mat3d.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_point
{
	t_v4			pos;
	t_v4			transf;
	int				color;
	t_v2			pos2d;
}					t_point;

typedef struct		s_param
{
	void			*mlx_p;
	void			*win_p;
	void			*img_p;
	unsigned int	*img_data;
	int				w;
	int				h;
	int				img_w;
	int				img_h;
	t_v2			img_d;
	int				s_line;
	int				bpp;
	int				endian;
	int				bgc;
	int				def_col_min;
	int				def_col_mid;
	int				def_col_max;
	t_v2			len_map;
	t_point			*points;
	t_m4			mrs;
	t_m4			mrz;
	t_m4			mrx;
	t_m4			mrpc;
	int				a;
	int				c;
	double			s;
	int				amp;
	int				press1;
	int				press3;
	t_v2			pad;
	double			an;
	double			cn;
	int				inf;
	int				proj;
	int				view;
}					t_param;

int					mouse_move_event(int x, int y, t_param *p);
int					mouse_down_event(int button, int x, int y, t_param *p);
int					mouse_up_event(int button, int x, int y, t_param *p);
int					key_event(int key, t_param	*p);
int					key_down(int key, t_param *p);
int					close_win(t_param	*p);
void				projection_parall(t_point *pnt, t_param *p);
void				projection_persp(t_point *pnt, t_param *p);
void				clear_image(t_param *p);
void				draw_line(t_point p0, t_point p1, t_param *p);
int					init_points(t_param *p, char *file);
int					init_param(t_param *p, char *file);
int					set_scale(t_param *p, int check_c);
int					read_len_map(t_param *p, char *file);
int					read_z_color(t_param *p, char *file);
int					set_matrix(t_param *p);
void				reset_pos(t_param *p);
void				set_view(t_param *p);
void				clear_block(unsigned int *data, t_v2 start, t_v2 end,
					t_v2 tmp);
void				draw_panel(t_param *p, int x, int y);
void				draw_button(t_param *p, int x, int y);
void				draw_menu(t_param *p);
void				draw_text_menu(t_param *p);
void				check_mouse(t_param *p, int x, int y);
void				draw_info(t_param *p);
void				draw_grad(t_param *p, int px, int py);
int					red(int color);
int					green(int color);
int					blue(int color);
int					color(int r, int g, int b);

#endif

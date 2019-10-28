/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 19:52:46 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/23 17:50:15 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAT3D_H
# define MAT3D_H

# include <math.h>
# include <stdlib.h>

typedef struct	s_v2
{
	int			x;
	int			y;
}				t_v2;

typedef struct	s_v3
{
	int			x;
	int			y;
	int			z;
}				t_v3;

typedef struct	s_v4
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_v4;

typedef struct	s_m4
{
	t_v4		f0;
	t_v4		f1;
	t_v4		f2;
	t_v4		f3;
}				t_m4;

void			set_m4_s(t_m4 *m, double s, double amp);
void			set_m4_rx(t_m4 *m, double fi);
void			set_m4_rz(t_m4 *m, double fi);
void			set_m4_pc(t_m4 *m);
t_v4			set_v4(double x, double y, double z, double w);
void			mult_vm(t_v4 *d, t_v4 s, t_m4 m);
void			eqal_v2(t_v2 *dst, t_v2 src);
void			abs_delta_v2(t_v2 *d, t_v2 p0, t_v2 p1);
void			sign_v2(t_v2 *s, t_v2 p0, t_v2 p1);

#endif

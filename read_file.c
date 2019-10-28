/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:32:27 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/18 00:05:26 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		close_free(int fd, char **line, int ret)
{
	free(line);
	close(fd);
	return (ret);
}

static int		free_word_line(char **line, char **word)
{
	int i;

	i = 0;
	while (word[i])
		free(word[i++]);
	free(word);
	if (*line)
		free(*line);
	return (i);
}

int				read_len_map(t_param *p, char *file)
{
	int		i;
	char	**line;
	int		fd;
	char	**word;

	if ((fd = open(file, 0x0000)) < 0)
		return (0);
	line = malloc(sizeof(char*));
	p->len_map.x = -1;
	p->len_map.y = 0;
	while (get_next_line(fd, line) > 0)
	{
		word = ft_strsplit(*line, ' ');
		i = free_word_line(line, word);
		if (p->len_map.x == -1)
			p->len_map.x = i;
		if (p->len_map.x != i)
			return (close_free(fd, line, 0));
		++(p->len_map.y);
	}
	return (close_free(fd, line, 1));
}

static double	set_z_color(t_point *pnt, char *word)
{
	char	**num;

	num = ft_strsplit(word, ',');
	pnt->pos.z = ft_atoi(*num);
	free(num[0]);
	if (num[1])
	{
		if (num[1][0] == '0' && num[1][1] == 'x')
			pnt->color = ft_atoi_16(&(num[1][2]));
		free(num[1]);
	}
	free(num);
	return (pnt->pos.z);
}

int				read_z_color(t_param *p, char *file)
{
	t_v2	tmp;
	char	**line;
	int		fd;
	char	**word;

	if ((fd = open(file, 0x0000)) < 0)
		return (0);
	line = malloc(sizeof(char*));
	tmp.y = 0;
	while (get_next_line(fd, line) > 0)
	{
		word = ft_strsplit(*line, ' ');
		tmp.x = 0;
		while (word[tmp.x])
		{
			set_z_color(&((p->points)[tmp.y * p->len_map.x + tmp.x]),
						word[tmp.x]);
			tmp.x++;
		}
		free_word_line(line, word);
		tmp.y++;
	}
	return (close_free(fd, line, 1));
}

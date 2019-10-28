/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:12:02 by vkaron            #+#    #+#             */
/*   Updated: 2019/10/23 18:01:57 by vkaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 10000

size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strdup2(const char *s1);
char	*ft_strndup(char *str, size_t n);
char	*ft_strrdup(char *str, size_t n);
char	*ft_strmcat(char *s1, char *s2);
size_t	ft_strfind(char *str, char sym);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	**ft_strsplit(char const *s, char c);
int		get_next_line(const int fd, char **line);
void	ft_swap(int *n1, int *n2);
int		ft_atoi(const char *str);
int		ft_atoi_16(const char *str);
int		ft_isspace(int c);
char	*ft_itoa(int nbr);
void	ft_pad_left(char *s, char c, unsigned int len);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_clamp(int val, int min, int max);

#endif

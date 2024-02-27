/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:16:57 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/27 16:21:13 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include "./gnl/get_next_line.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_bsq
{
	char	**map;
	int		height;
	int		width;
	char	full;
	char	empty;
	char	obs;
}	t_bsq;

// the first line is "[lines][empty][obstacle][full]\n"

// helpers

t_point		set_point(int y, int x);
char		**ft_split(char const *s, char c);
char		*ft_strdup(const char *s1);
int			ft_new_strlen(char *s);

// map

void		get_height(t_bsq *game, char *s);
void		read_map(t_bsq *game, char *s);
void		ft_print_map(char **game);

// solve

t_point		biggest_square(t_bsq *bsq);
int			get_square(t_bsq *bsq, t_point start);
int			is_square(t_bsq *bsq, t_point start, int size);
void		solution(t_bsq *bsq, t_point start);

//errors

int			error0(char **s);

#endif
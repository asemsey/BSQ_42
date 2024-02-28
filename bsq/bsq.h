/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:16:57 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/28 11:49:10 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "./gnl/get_next_line.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_bsq
{
	char	**map;
	char	**real_map;
	int		height;
	int		width;
	char	full;
	char	empty;
	char	obs;
}	t_bsq;

// helpers

t_point		set_point(int y, int x);
char		**ft_split(char const *s, char c);
void		free_all(char **strs);
char		*ft_strdup(const char *s1);
int			ft_new_strlen(char *s);

int			error0(char **s);
int			error1(char **s);

// map

void		read_map(t_bsq *game, char *s);
void		get_realmap(t_bsq *game);
void		get_height(t_bsq *game, char *s);
void		ft_print_map(char **game);

// solve

int			solve(t_bsq *bsq);
t_point		biggest_square(t_bsq *bsq);
int			get_square(t_bsq *bsq, t_point start);
int			is_square(t_bsq *bsq, t_point start, int size);
void		solution(t_bsq *bsq, t_point start);

#endif
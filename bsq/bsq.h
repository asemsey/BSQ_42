/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:16:57 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/27 15:32:14 by asemsey          ###   ########.fr       */
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
	t_point	size;
	char	full;
	char	empty;
	char	obs;
}	t_bsq;

t_point		set_point(int y, int x);
char		**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
void	get_height(t_bsq *game, char *s);
int ft_new_strlen(char *s);
void	read_map(t_bsq *game, char *s);


#endif
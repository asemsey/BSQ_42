/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:16:57 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/27 15:10:59 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include "./gnl/get_next_line.h"

typedef struct s_bsq
{
    char	**map;
    int		height;
	int		width;
	char	full;
	char	empty;
	char	obs;
}   t_bsq;

char		**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
void	get_height(t_bsq *game, char *s);
int ft_new_strlen(char *s);
void	read_map(t_bsq *game, char *s);


#endif
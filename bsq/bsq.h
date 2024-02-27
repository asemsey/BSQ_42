/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:16:57 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/27 14:30:41 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>

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

size_t		ft_strlen(const char *s);
char		*ft_strjoin(char *s1, const char *s2);
char		**ft_split(char const *s, char c);

#endif
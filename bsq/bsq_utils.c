/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:16:03 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/28 11:54:41 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_new_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	ft_print_map(char **game)
{
	int	i;
	int	j;

	i = 0;
	while (game[i])
	{
		j = 0;
		while (game[i][j])
		{
			write(1, &game[i][j], 1);
			j++;
		}
		i++;
	}
}

t_point	set_point(int y, int x)
{
	t_point	p;

	p.y = y;
	p.x = x;
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	l;
	size_t	i;

	l = ft_strlen(s1);
	i = 0;
	dup = (char *)malloc(sizeof(char) * (l + 1));
	if (!dup)
		return (0);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

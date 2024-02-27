/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:17:39 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/27 15:20:38 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// input: a valid map string array (1 str per line) -> use ft_split!
// the first line is "[lines][empty][obstacle][full]\n"

t_point	solve(t_bsq *bsq)
{
	return (bsq->size);
	// incomplete
}

// check if there are obstacles in the given square
int	is_square(t_bsq *bsq, t_point start, int size)
{
	int	y;
	int	x;

	if (!bsq->map[start.y] || !bsq->map[start.y][start.x]
		|| start.y + (size - 1) >= bsq->height
		|| start.x + (size - 1) >= bsq->width)
		return (0);
	y = 0;
	while (bsq->map[start.y + y] && start.y + y < bsq->height)
	{
		x = 0;
		while (bsq->map[start.y + y][start.x + x] && start.x + x < bsq->width)
			if (bsq->map[start.y + y][start.x + x] != bsq->empty)
				return (0);
		y++;
	}
	return (1);
}

// get the size of the biggest square starting at start
int	get_square(t_bsq *bsq, t_point start)
{
	int		i;
	int		max_size;

	if (!bsq->map[start.y] || !bsq->map[start.y][start.x])
		return (0);
	i = 1;
	if (bsq->height < bsq->width)
		max_size = bsq->height;
	else
		max_size = bsq->width;
	while (i <= max_size)
	{
		if (!is_square(bsq, start, i))
			break ;
		i++;
	}
	return (i - 1);
}

// fill the solution square in the map
void	solution(t_bsq *bsq, t_point start)
{
	int		size;
	int		x;
	int		y;
	char	**map;

	size = get_square(bsq, start);
	if (size <= 0)
		return ;
	map = bsq->map;
	y = 0;
	while (map[start.y + y] && start.y + y < bsq->height && y < size)
	{
		x = 0;
		while (map[start.y + y][start.x + x] && start.x + x < bsq->width
			&& x < size)
			map[start.y + y][start.x + x++] = bsq->full;
		y++;
	}
}

// solver:
// marks biggest gap in each line [full]
// unmarks small gaps in each row [empty]
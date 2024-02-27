/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:17:39 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/27 16:40:21 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	solve(t_bsq *bsq)
{
	t_point	start;

	start = biggest_square(bsq);
	if (start.y < 0 || start.x < 0)
		return (-1);
	solution(bsq, start);
	ft_print_map(bsq->real_map);
	return (0);
}

// returns the first biggest square's start coordinates
t_point	biggest_square(t_bsq *bsq)
{
	t_point	start;
	int		y;
	int		x;
	int		size;

	size = 0;
	y = 0;
	start = set_point(-1, -1);
	while (bsq->real_map[y] && y < bsq->height)
	{
		x = 0;
		while (bsq->real_map[y][x] && x < bsq->width)
		{
			if (get_square(bsq, set_point(y, x)) > size)
			{
				start = set_point(y, x);
				size = get_square(bsq, set_point(y, x));
			}
			x++;
		}
		y++;
	}
	return (start);
}

// check if there are obstacles in the given square
int	is_square(t_bsq *bsq, t_point start, int size)
{
	int	y;
	int	x;

	if (!bsq->real_map[start.y] || !bsq->real_map[start.y][start.x]
		|| start.y + (size - 1) >= bsq->height
		|| start.x + (size - 1) >= bsq->width)
		return (0);
	y = 0;
	while (bsq->real_map[start.y + y] && start.y + y < bsq->height && y < size)
	{
		x = 0;
		while (bsq->real_map[start.y + y][start.x + x] && start.x + x < bsq->width && x < size)
			if (bsq->real_map[start.y + y][start.x + x] != bsq->empty)
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

	if (!bsq->real_map[start.y] || !bsq->real_map[start.y][start.x])
		return (0);
	i = 1;
	if (bsq->height < bsq->width)
		max_size = bsq->height;
	else
		max_size = bsq->width;
	while (i <= max_size)
	{
		if (!is_square(bsq, start, i))
		{
			break ;
		}
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
	map = bsq->real_map;
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

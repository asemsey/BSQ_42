/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:17:39 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/28 10:50:23 by asemsey          ###   ########.fr       */
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
	int		size[2];

	size[0] = 0;
	y = 0;
	start = set_point(-1, -1);
	while (y < bsq->height)
	{
		x = 0;
		while (x < bsq->width)
		{
			size[1] = get_square(bsq, set_point(y, x));
			if (size[1] > size[0])
			{
				start = set_point(y, x);
				size[0] = get_square(bsq, start);
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

	if (start.y >= bsq->height || start.x >= bsq->width
		|| start.y + (size - 1) >= bsq->height || bsq->real_map[start.y][start.x] == bsq->obs
		|| start.x + (size - 1) >= bsq->width)
		return (0);
	y = 0;
	while (start.y + y < bsq->height && y < size)
	{
		x = 0;
		while (start.x + x < bsq->width && x < size)
		{
			if (bsq->real_map[start.y + y][start.x + x] != bsq->empty)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

// get the size of the biggest square starting at start
int	get_square(t_bsq *bsq, t_point start)
{
	int		i;
	int		max_size;

	if (start.y >= bsq->height || start.x >= bsq->width)
		return (0);
	i = 1;
	if (bsq->height < bsq->width)
		max_size = bsq->height;
	else
		max_size = bsq->width;
	while (i <= max_size)
	{
		if (is_square(bsq, start, i) == 0)
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
	map = bsq->real_map;
	y = 0;
	while (start.y + y < bsq->height && y < size)
	{
		x = 0;
		while (start.x + x < bsq->width && x < size)
			map[start.y + y][start.x + x++] = bsq->full;
		y++;
	}
}

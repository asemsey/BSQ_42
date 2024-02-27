/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:08:41 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/27 14:25:14 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// map file should open and close before next map in argv is read
// read each file into same string but always start over

// int	

// void	read_map(t_bsq *map, char *s)
// {
// 	int i = 0;
// 	int fd;
// 	fd = open(s, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		write
// 	}
// }

int	main(int argc, char const *argv[])
{
	int		file;
	char	*map;
	t_bsq	game;
	
	file = 1;
	if (argc < 2)
		// ???
	while (argv[file])
	{
		// open file
		// read it to map
		// check valid map
		// solve(map)
		// close file
		// free map
		file++;
	}
	return (0);
}

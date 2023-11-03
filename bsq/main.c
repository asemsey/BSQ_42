/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:08:41 by asemsey           #+#    #+#             */
/*   Updated: 2023/11/03 15:01:04 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// map file should open and close before next map in argv is read
// read each file into same string but always start over

// int	

int	main(int argc, char const *argv[])
{
	int		file;
	char	*map;

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

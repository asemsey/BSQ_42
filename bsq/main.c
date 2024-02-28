/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:08:41 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/28 11:43:15 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int		i;
	t_bsq	game;

	i = 1;
	if (argc < 2)
	{
		write(2, "No map\n", 7);
		return (1);
	}
	while (argv[i])
	{
		read_map(&game, argv[i++]);
		get_realmap(&game);
		if (error0(game.real_map) == 0 || error1(game.real_map) == 0)
		{
			write (2, "invalid map\n", 12);
			continue ;
		}
		if (solve(&game) == -1)
			exit (1);
		free_all(game.real_map);
		if (i < argc)
			write(1, "\n", 1);
	}
	return (0);
}

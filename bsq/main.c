/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:08:41 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/27 16:24:15 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// map file should open and close before next map in argv is read
// read each file into same string but always start over

// int	

int ft_new_strlen(char *s)
{
	int i = 0;
	while (s && s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

void	get_height(t_bsq *game, char *s)
{
	int i = 0;
	int fd;
	char *line;
	
	fd = open (s, O_RDONLY);
	if (fd < 0)
	{
		write (2, "Error\n", 1);
		exit (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		free (line);
		i++;
	}
	game->height = i;
}

void	read_map(t_bsq *game, char *s)
{
	int i = 0;
	char *line;
	int fd;
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		write (2, "Error\n", 1);
		exit (1);
	}
	get_height(game, s);
	game->map = malloc (sizeof(char *) * (game->height + 1));
	if (!game->map)
		return ;
	while ((line = get_next_line(fd)) != NULL)
	{
		game->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->map[i] = NULL;
}

void	ft_print_map(char **game)
{
	int i = 0;
	int j;
	while (game[i])
	{
		j = 0;
		while(game[i][j])
		{
			write (1, &game[i][j], 1);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	// int		file;
	int i = 1;
	// char	*map;
	t_bsq	game;
	
	while (argv[i])
	{
		read_map(&game, argv[i]);
		i++;
	}
	i = 0;
	if (error0(game.map) == 0)
	{
		write (1, "invalid map\n", 12);
		exit (1);
	}
	ft_print_map(game.map);


	
	// file = 1;
	if (argc < 2)
		// ???

	// while (argv[file])
	// {
	// 	// open file
	// 	// read it to map
	// 	// check valid map
	// 	// solve(map)
	// 	// close file
	// 	// free map
	// 	file++;
	// }
	return (0);
}

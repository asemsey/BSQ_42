/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:08:41 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/28 11:28:39 by fnikzad          ###   ########.fr       */
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
		write (2, "Error\n", 6);
		exit (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		i++;
		free (line);
	}
	game->height = i - 1;
	close(fd);
}

void	read_map(t_bsq *game, char *s)
{
	int i = 0;
	char *line;
	int fd;
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	get_height(game, s);
	game->map = malloc (sizeof(char *) * (game->height + 2));
	if (!game->map)
		return ;
	while ((line = get_next_line(fd)) != NULL)
	{
		game->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->map[i] = NULL;
	game->width = ft_new_strlen(game->map[1]);

	game->full = game->map[0][3];
	game->empty = game->map [0][1];
	game->obs = game->map[0][2];
	close(fd);
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

void ft_free(char **s)
{
	int i = 0;
	while (s && s[i])
	{
		free (s[i]);
		i++;
	}
	free (s);
}

int	main(int argc, char **argv)
{
	int		i = 1;
	t_bsq	game;
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
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		ft_free (game.real_map);
		if (i < argc)
			write(1, "\n", 1);
	}
	return (0);
}

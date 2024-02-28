/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:07:38 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/28 11:48:06 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	get_realmap(t_bsq *game)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	game->real_map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->real_map)
		return ;
	while (game->map[j])
		game->real_map[i++] = ft_strdup(game->map[j++]);
	free_all(game->map);
	game->real_map[i] = NULL;
}

void	read_map(t_bsq *game, char *s)
{
	int		i;
	char	*line;
	int		fd;

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	get_height(game, s);
	game->map = malloc(sizeof(char *) * (game->height + 2));
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

void	get_height(t_bsq *game, char *s)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		i++;
		free(line);
	}
	game->height = i - 1;
	close(fd);
}

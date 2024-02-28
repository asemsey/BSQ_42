/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:07:38 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/28 11:27:49 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void get_realmap(t_bsq *game)
{
    int	i = 0;
	int j = 1;
	game->real_map = malloc(sizeof(char *) * (game->height + 1));
	if (!game->real_map)
		return ;
	while (game->map[j])
	{
		game->real_map[i++] = ft_strdup(game->map[j++]);
	}
	ft_free (game->map);
	game->real_map[i] = NULL;
}
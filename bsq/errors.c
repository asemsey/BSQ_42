/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:11:26 by fnikzad           #+#    #+#             */
/*   Updated: 2024/02/28 11:55:47 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	error0(char **s)
{
	int		i;
	size_t	j;

	i = 0;
	j = ft_strlen(s[0]);
	while (s[i])
	{
		if (j != ft_strlen(s[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	error1(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] && s[i][j] != '.' && s[i][j] != 'o'
				&& s[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

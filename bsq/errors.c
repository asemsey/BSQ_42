/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:11:26 by fnikzad           #+#    #+#             */
/*   Updated: 2024/02/27 16:53:44 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	error0(char **s)
{
	int i = 0;
	size_t j = ft_strlen(s[0]);
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
	int i = 0;
	int j;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] != '.' && s[i][j] != 'o' &&s[i][j] != '\n' && s[i][j] != '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
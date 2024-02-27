/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:16:03 by asemsey           #+#    #+#             */
/*   Updated: 2024/02/27 14:56:53 by fnikzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"


// char	*ft_strjoin(char *s1, const char *s2)
// {
// 	char	*s;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (!s || (!s1 && !s2))
// 		return (NULL);
// 	while (s1 && s1[i] != '\0')
// 	{
// 		s[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2 && s2[j] != '\0')
// 	{
// 		s[i + j] = s2[j];
// 		j++;
// 	}
// 	s[i + j] = '\0';
// 	if (s1)
// 		free(s1);
// 	return (s);
// }


char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	l;
	size_t	i;

	l = ft_strlen(s1);
	i = 0;
	dup = (char *) malloc (sizeof(char) * (l + 1));
	if (!dup)
		return (0);
	while (s1[i] != 0)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}
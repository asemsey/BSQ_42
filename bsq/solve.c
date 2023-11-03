/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:17:39 by asemsey           #+#    #+#             */
/*   Updated: 2023/11/03 15:01:08 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

// input: a valid map string array (1 str per line) -> use ft_split!
// the first line is "[lines][empty][obstacle][full]\n"

// solver:
// marks biggest gap in each line [full]
// unmarks small gaps in each row [empty]
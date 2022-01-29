/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 03:08:05 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/28 12:32:04 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_vect2f	newvect2f(float x, float y)
{
	t_vect2f	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

t_vect2i	newvect2i(int x, int y)
{
	t_vect2i	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

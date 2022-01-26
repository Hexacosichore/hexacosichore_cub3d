/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 03:08:05 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/25 04:22:33 by kbarbry          ###   ########.fr       */
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

float	dist(t_vect2f pt0, t_vect2f pt1)
{
	return (sqrtf(powf(pt1.x - pt0.x, 2) + powf(pt1.y - pt0.y, 2)));
}

float	radToDeg(float rad)
{
	return (rad * 180 / PI);
}

float	degToRad(float deg)
{
	return (deg * PI / 180);
}
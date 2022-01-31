/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:09:44 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/30 17:07:09 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_cub3d *d, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x > WIN_L - 1 || y > WIN_H - 1)
		return ;
	dst = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	turn_with_mouse(t_cub3d *cub3d)
{
	int	old_x;
	int	x;
	int	y;

	if (!cub3d->started)
	{
		cub3d->started = 1;
		return ;
	}
	old_x = WIN_L / 2;
	cub3d->sensi = 0.02f;
	x = 0;
	y = 0;
	mlx_mouse_get_pos(cub3d->mlx_win, &x, &y);
	if (x > old_x + 2)
	{
		cub3d->is_press.right = 1;
		cub3d->sensi = ((float)x - (float)old_x) / 1000;
	}
	else if (x < old_x - 2)
	{
		cub3d->is_press.left = 1;
		cub3d->sensi = ((float)old_x - (float)x) / 1000;
	}
}

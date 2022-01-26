/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 04:13:08 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/26 23:40:06 by kbarbry          ###   ########.fr       */
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
	cub3d->sensi = 0.04f;
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

void	actualize_player_2(t_cub3d *cub3d)
{
	turn_with_mouse(cub3d);
	if (cub3d->is_press.left)
	{
		if (cub3d->p_angle + cub3d->sensi > 2 * PI)
			cub3d->p_angle -= 2 * PI;
		cub3d->p_angle += cub3d->sensi;
		cub3d->is_press.left = 0;
	}
	if (cub3d->is_press.right)
	{
		if (cub3d->p_angle - cub3d->sensi < 0)
			cub3d->p_angle += 2 * PI;
		cub3d->p_angle -= cub3d->sensi;
		cub3d->is_press.right = 0;
	}
	cub3d->d_angle.x = cos(cub3d->p_angle);
	cub3d->d_angle.y = sin(cub3d->p_angle);
	mlx_mouse_move(cub3d->mlx_win, WIN_L / 2, WIN_H / 2);
}

void	actualize_player(t_cub3d *cub3d)
{
	if (cub3d->is_press.w)
	{
		cub3d->player.x += cub3d->speed * cub3d->d_angle.x;
		cub3d->player.y -= cub3d->speed * cub3d->d_angle.y;
	}
	if (cub3d->is_press.s)
	{
		cub3d->player.x -= cub3d->speed * cub3d->d_angle.x;
		cub3d->player.y += cub3d->speed * cub3d->d_angle.y;
	}
	if (cub3d->is_press.a)
	{
		cub3d->player.x -= cub3d->speed * cub3d->d_angle.y;
		cub3d->player.y -= cub3d->speed * cub3d->d_angle.x;
	}
	if (cub3d->is_press.d)
	{
		cub3d->player.x += cub3d->speed * cub3d->d_angle.y;
		cub3d->player.y += cub3d->speed * cub3d->d_angle.x;
	}
	if (cub3d->is_press.shift)
		cub3d->speed = 0.04f;
	else
		cub3d->speed = 0.03f;
	actualize_player_2(cub3d);
}

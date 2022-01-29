/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 04:13:08 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/29 18:14:27 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	actualize_player_3(t_cub3d *c)
{
	float	olddir;
	float	oldcam;

	turn_with_mouse(c);
	if (c->is_press.left)
	{
		olddir = c->dir.x;
		oldcam = c->cam.x;
		c->dir.x = c->dir.x * cosf(-c->sensi) - c->dir.y * sinf(-c->sensi);
		c->dir.y = olddir * sinf(-c->sensi) + c->dir.y * cosf(-c->sensi);
		c->cam.x = c->cam.x * cosf(-c->sensi) - c->cam.y * sinf(-c->sensi);
		c->cam.y = oldcam * sinf(-c->sensi) + c->cam.y * cosf(-c->sensi);
		c->is_press.left = 0;
	}
	if (c->is_press.right)
	{
		olddir = c->dir.x;
		oldcam = c->cam.x;
		c->dir.x = c->dir.x * cosf(c->sensi) - c->dir.y * sinf(c->sensi);
		c->dir.y = olddir * sinf(c->sensi) + c->dir.y * cosf(c->sensi);
		c->cam.x = c->cam.x * cosf(c->sensi) - c->cam.y * sinf(c->sensi);
		c->cam.y = oldcam * sinf(c->sensi) + c->cam.y * cosf(c->sensi);
		c->is_press.right = 0;
	}
	mlx_mouse_move(c->mlx_win, WIN_L / 2, WIN_H / 2);
}

void	actualize_player_2(t_cub3d *c)
{
	if (c->is_press.a)
	{
		c->player.x -= c->cam.x * c->speed;
		c->player.y -= c->cam.y * c->speed;
	}
	if (c->is_press.d)
	{
		c->player.x += c->cam.x * c->speed;
		c->player.y += c->cam.y * c->speed;
	}
	if (c->is_press.shift)
		c->speed = 0.04f;
	else
		c->speed = 0.02f;
	actualize_player_3(c);
}

void	actualize_player(t_cub3d *c)
{
	if (c->is_press.w)
	{
		if (c->map[(int)c->player.y * c->width_map + (int)(c->player.x
				+ c->dir.x * c->speed * 3)] != 1)
			c->player.x += c->dir.x * c->speed;
		if (c->map[(int)c->player.x + (int)(c->player.y + c->dir.y
				* c->speed * 3) * c->width_map] != 1)
		c->player.y += c->dir.y * c->speed;
	}
	if (c->is_press.s)
	{
		c->player.x -= c->dir.x * c->speed;
		c->player.y -= c->dir.y * c->speed;
	}
	actualize_player_2(c);
}

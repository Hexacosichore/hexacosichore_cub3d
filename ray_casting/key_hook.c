/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 01:16:49 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/31 18:33:58 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_key_press(int keycode, t_cub3d *cub3d)
{
	if (keycode == ESC)
		ft_leave(cub3d);
	if (keycode == W)
		cub3d->is_press.w = 1;
	if (keycode == S)
		cub3d->is_press.s = 1;
	if (keycode == A)
		cub3d->is_press.a = 1;
	if (keycode == D)
		cub3d->is_press.d = 1;
	if (keycode == SHIFT)
		cub3d->is_press.shift = 1;
	if (keycode == LEFT_ARROW)
		cub3d->is_press.left = 1;
	if (keycode == RIGHT_ARROW)
		cub3d->is_press.right = 1;
	if (keycode == DOWN_ARROW)
		cub3d->is_press.down = 1;
	if (keycode == UP_ARROW)
		cub3d->is_press.up = 1;
	if (keycode == TAB)
		cub3d->is_press.tab = 1;
	return (0);
}

int	ft_key_release(int keycode, t_cub3d *cub3d)
{
	if (keycode == W)
		cub3d->is_press.w = 0;
	if (keycode == S)
		cub3d->is_press.s = 0;
	if (keycode == A)
		cub3d->is_press.a = 0;
	if (keycode == D)
		cub3d->is_press.d = 0;
	if (keycode == SHIFT)
		cub3d->is_press.shift = 0;
	if (keycode == LEFT_ARROW)
		cub3d->is_press.left = 0;
	if (keycode == RIGHT_ARROW)
		cub3d->is_press.right = 0;
	if (keycode == DOWN_ARROW)
		cub3d->is_press.down = 0;
	if (keycode == UP_ARROW)
		cub3d->is_press.up = 0;
	if (keycode == TAB)
		cub3d->is_press.tab = 0;
	return (0);
}

int	ft_exit(t_cub3d *cub3d)
{
	mlx_destroy_image(cub3d->mlx, cub3d->mlx_img);
	mlx_destroy_window(cub3d->mlx, cub3d->mlx_win);
	ft_leave(cub3d);
	return (0);
}

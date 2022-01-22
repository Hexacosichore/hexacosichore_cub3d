/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 06:04:40 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/22 06:30:20 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_ray_casting(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	cub3d->mlx_win = mlx_new_window(ptr, WIN_L, WIN_H, "Cub3D");
	cub3d->mlx_
	mlx_loop(ptr);
}

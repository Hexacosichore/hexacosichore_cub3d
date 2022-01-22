/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 04:41:34 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/21 06:09:41 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	ft_free_all(t_cub3d *cub3d)
{
	free(cub3d->ntexture);
	free(cub3d->stexture);
	free(cub3d->wtexture);
	free(cub3d->etexture);
	free(cub3d->ftexture);
	free(cub3d->ctexture);
	free(cub3d->map);
}

void	ft_error(char *msg, int mode, t_cub3d *cub3d)
{
	printf("\033[1;31mError.\n\033[0m%s\n", msg);
	if (mode == 1)
		ft_free_all(cub3d);
	exit (1);
}

void	ft_leave(t_cub3d *cub3d)
{
	printf("\033[1;32mEverything leaves properly.\033[0m\n");
	ft_free_all(cub3d);
	exit (0);
}

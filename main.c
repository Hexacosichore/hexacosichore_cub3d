/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:46:35 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/22 06:07:27 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	cub3d;

	if (ac != 2)
		ft_error("Use: ./cub3d file.cub", 0, &cub3d);
	check_extention(av[1], ".cub");
	init_parsing(av[1], &cub3d);
	init_ray_casting(&cub3d);
	int i = 0;
	while (i < cub3d.width_map * cub3d.height_map)
	{
		dprintf(1, "%2d ", cub3d.map[i]);
		if ((i + 1) % cub3d.width_map == 0 && i > 0)
			printf("\n");
		i++;
	}
	ft_leave(&cub3d);
}

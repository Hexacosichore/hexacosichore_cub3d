/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:46:35 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/29 17:03:49 by kbarbry          ###   ########.fr       */
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
	ft_leave(&cub3d);
}

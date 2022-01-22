/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 05:27:56 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/22 06:02:05 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_isvalidid(char *line, t_cub3d *cub3d)
{
	if (!ft_strncmp(line, "NO", 2))
		return ;
	if (!ft_strncmp(line, "SO", 2))
		return ;
	if (!ft_strncmp(line, "WE", 2))
		return ;
	if (!ft_strncmp(line, "EA", 2))
		return ;
	if (!ft_strncmp(line, "F", 1))
		return ;
	if (!ft_strncmp(line, "C", 1))
		return ;
	ft_error("Wrong synthax in file.cub.", 1, cub3d);
}

void	check_identifier(char *line, t_cub3d *cub3d)
{
	if (ft_strlen(line) < 3)
		ft_error("Wrong synthax in file.cub.", 1, cub3d);
	if (ft_isalpha(line[0]) && ft_isalpha(line[1]))
	{
		if (ft_isalpha(line[2]))
			ft_error("Wrong synthax in file.cub.", 1, cub3d);
		ft_isvalidid(line, cub3d);
	}
	else if (ft_isalpha(line[0]))
		ft_isvalidid(line, cub3d);
	else
		ft_error("Wrong synthax in file.cub.", 1, cub3d);
}

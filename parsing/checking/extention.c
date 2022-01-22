/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extention.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 01:34:33 by kbarbry           #+#    #+#             */
/*   Updated: 2022/01/22 06:02:02 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	check_extention(char *file, char *extention)
{
	int	i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (!file[i] || ft_strncmp(&file[i], extention, 5))
		ft_error("Wrong extention file. Main: file.cub, texture: file.cubtxt",
			0, NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:04:20 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 17:36:48 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	launch_parsing(char **argv, t_data *data)
{
	get_file(data, argv);
	get_textures(data);
	get_colors(data);
	
	color_to_int(data);
	parsing_map(data);

	return (0);
}
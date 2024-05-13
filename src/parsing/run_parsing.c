/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:04:20 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 00:03:16 by npatron          ###   ########.fr       */
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
	// printf("---------------------------------------------\n");
	// printf("MY FILE : \n");
	// print_tab(data->file);
	// printf("---------------------------------------------\n");
	// printf("\n");
	// printf("---------------------------------------------\n");
	// printf("MY PATH TEXTURES : \n\n");
	// printf("NORTH : %s\n", data->north_texture);
	// printf("SOUTH : %s\n", data->south_texture);
	// printf("WEST : %s\n", data->west_texture);
	// printf("EAST : %s\n", data->east_texture);
	
	// printf("MY FLOOR : \n");
	// print_int_tab(data->floor_color);
	// printf("---------------------------------------------\n");
	// printf("\n");
	// printf("MY SKY : \n");
	// print_int_tab(data->sky_color);
	// printf("---------------------------------------------\n");
	// printf("START MAP : %d \n", data->start_line_map);
	return (0);
}
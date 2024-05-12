/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 17:04:20 by npatron           #+#    #+#             */
/*   Updated: 2024/05/12 23:34:59 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	launch_parsing(char **argv, t_data *data)
{
	get_file(data, argv);
	get_textures(data);
	get_colors(data);
	color_to_int(data);
	// printf("---------------------------------------------\n");
	// printf("MY FILE : \n");
	// print_tab(data->file);
	// printf("---------------------------------------------\n");
	// printf("\n");
	// printf("---------------------------------------------\n");
	// printf("MY TAB TEXTURES : \n");
	// print_tab(data->textures);
	// printf("---------------------------------------------\n");
	// printf("MY PATH TEXTURES : \n\n");
	// printf("NORTH : %s\n", data->north_texture);
	// printf("SOUTH : %s\n", data->south_texture);
	// printf("WEST : %s\n", data->west_texture);
	// printf("EAST : %s\n", data->east_texture);

	printf("FLOOR PATH : %s\n", data->floor_path);
	printf("SKY PATH: %s\n", data->sky_path);
	// print_int_tab(data->floor_color);
	// printf("\n");
	// print_int_tab(data->sky_color);
	return (0);
}
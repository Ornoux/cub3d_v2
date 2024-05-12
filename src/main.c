/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:09:51 by npatron           #+#    #+#             */
/*   Updated: 2024/05/12 23:08:26 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_data(t_data *data)
{
	data->file = NULL;
	data->lines_into_file = 0;
	data->map = NULL;
	data->player_direction = 0;
	data->no_texture = 0;
	data->so_texture = 0;
	data->we_texture = 0;
	data->ea_texture = 0;
	data->floor_path = NULL;
	data->sky_path = NULL;
	data->north_texture = NULL;
	data->south_texture = NULL;
	data->east_texture = NULL;
	data->west_texture = NULL;
	data->start_line_map = 0;
	data->last_line_map = 0;
	data->nb_lines_map = 0;
}

void	free_struct(t_data *data)
{
	if (data->file)
	 	free_char_tab(data->file);
	if (data->floor_color)
	 	free(data->floor_color);
	if (data->sky_color)
	 	free(data->sky_color);
	if (data->north_texture)
		free(data->north_texture);
	if (data->south_texture)
		free(data->south_texture);
	if (data->west_texture)
		free(data->west_texture);
	if (data->east_texture)
		free(data->east_texture);
	free(data);
}

int	main(int argc, char **av)
{
	(void)av;
	t_data *data;

	data = malloc(sizeof(t_data));
	if (argc != 2)
	{
		printf("%s\n", ARG);
		return (0);
	}
	init_data(data);
	launch_parsing(av, data);
	free_struct(data);
	return (0);
}
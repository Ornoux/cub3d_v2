/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:09:51 by npatron           #+#    #+#             */
/*   Updated: 2024/05/10 16:38:47 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_data(t_data *data)
{
	data->lines_into_file = 0;
	data->dir = NULL;
	data->map = NULL;
	data->colors = malloc(sizeof(char *) * 3);
	data->textures = malloc(sizeof(char *) * 5);
	data->player_direction = 0;
}

int	main(int argc, char **av)
{
	(void)av;
	t_data *data;

	data = malloc(sizeof(t_data));
	if (argc != 2)
		return (print_error(ARG));
		
	init_data(data);
	if (launch_parsing(av, data) == 1)
	{
		//free_char_tab(data->file);
		free(data);
	}
	print_tab(data->file);
	free_char_tab(data->file);
	free(data);
	return (0);
}
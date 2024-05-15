/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:27:09 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 19:38:42 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	big_pixel_put(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = HEIGHT / 50;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(data, (x * size) + i, (y * size) + j, color);
			j++;
		}
		i++;
	}
}

void	mini_map_2(t_data *data, int pos_x, int pos_y, int x, int y)
{
	while (y < 10)
	{
		if (!data->map[pos_x][pos_y])
			break ;
		if (data->map[pos_x][pos_y] && data->map[pos_x][pos_y] == '0')
			big_pixel_put(data, y, x, create_trgb(0, 0, 0, 0));
		if (data->map[pos_x][pos_y] && data->map[pos_x][pos_y] == '1')
			big_pixel_put(data, y, x, create_trgb(0, 50, 50, 50));
		if (data->map[pos_x][pos_y] && data->map[pos_x][pos_y] == 'P')
			big_pixel_put(data, y, x, create_trgb(0, 255, 0, 0));
		y++;
		pos_y++;
	}
}

void	mini_map(t_data *data)
{
	int	x;
	int	y;
	int	pos_x;
	int	pos_y;

	x = 0;
	pos_x = (int)data->p.pos_x - 5;
	if (pos_x < 0)
		pos_x = 0;
	while (x < 10)
	{
		if (!data->map[pos_x])
			break ;
		pos_y = (int)data->p.pos_y - 5;
		y = 0;
		if (pos_y < 0)
			pos_y = 0;
		mini_map_2(data, pos_x, pos_y, x, y);
		x++;
		pos_x++;
	}
}

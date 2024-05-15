/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:41:37 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 19:39:08 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	set_sky(t_data *data, int x)
{
	int	y;

	y = 0;
	while (y < data->ray.start_draw)
	{
		my_mlx_pixel_put(data, x, y, create_trgb(0, data->sky_color[0], \
		data->sky_color[1], data->sky_color[2]));
		y++;
	}
}

t_image	*get_wall(t_data *data)
{
	if (data->ray.side && data->ray.step_y < 0)
		return (data->n);
	if (data->ray.side && data->ray.step_y > 0)
		return (data->s);
	if (!data->ray.side && data->ray.step_x < 0)
		return (data->w);
	if (!data->ray.side && data->ray.step_x > 0)
		return (data->e);
	return (data->n);
}

void	build_column(t_data	*data, int x)
{
	int		y;
	double	y_texture;
	double	step;
	t_image	*texture;

	texture = get_wall(data);
	set_floor(data, x);
	y_texture = 0;
	step = (double)((double)texture->height / (double)(data->ray.end_draw \
	- data->ray.start_draw));
	if (data->ray.start_draw < 0)
	{
		y_texture = step * data->ray.start_draw * -1;
		data->ray.start_draw = 0;
	}
	y = data->ray.start_draw;
	while (y < data->ray.end_draw)
	{
		if (y >= HEIGHT)
			break ;
		my_mlx_pixel_put(data, x, y, choose_color(texture, data->ray.wall_x \
		* texture->width, y_texture));
		y++;
		y_texture += step;
	}
}

void	build_column_2(t_data *data, int x)
{
	build_column(data, x);
	set_sky(data, x);
}

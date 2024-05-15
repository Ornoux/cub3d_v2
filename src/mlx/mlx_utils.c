/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:59:32 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 21:01:16 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	refresh_map(t_data *data)
{
	if (data->tmp_x != (int)data->p.pos_x)
	{
		data->map[data->tmp_x][data->tmp_y] = '0';
		data->tmp_x = data->p.pos_x;
		data->map[data->tmp_x][data->tmp_y] = 'P';
	}
	if (data->tmp_y != (int)data->p.pos_y)
	{
		data->map[data->tmp_x][data->tmp_y] = '0';
		data->tmp_y = data->p.pos_y;
		data->map[data->tmp_x][data->tmp_y] = 'P';
	}
}

void	key_press_2(t_data *data)
{
	data->p.old_dir = data->p.dirp_x;
	data->p.dirp_x = data->p.dirp_x * cos(ROTATION * data->rota) - \
	data->p.dirp_y * sin(ROTATION * data->rota);
	data->p.dirp_y = data->p.old_dir * sin(ROTATION * data->rota) + \
	data->p.dirp_y * cos(ROTATION * data->rota);
	data->p.old_plane = data->p.plane_x;
	data->p.plane_x = data->p.plane_x * cos(ROTATION * data->rota) - \
	data->p.plane_y * sin(ROTATION * data->rota);
	data->p.plane_y = data->p.old_plane * sin(ROTATION * data->rota) + \
	data->p.plane_y * cos(ROTATION * data->rota);
}

int	key_press(int key, t_data *data)
{
	refresh_map(data);
	moves_forward_backward(data, key);
	moves_sides(data, key);
	if (key == 65363) // DROITE
	{
		data->p.old_dir = data->p.dirp_x;
		data->p.dirp_x = data->p.dirp_x * cos(-ROTATION * data->rota) - \
		data->p.dirp_y * sin(-ROTATION * data->rota);
		data->p.dirp_y = data->p.old_dir * sin(-ROTATION * data->rota) + \
		data->p.dirp_y * cos(-ROTATION * data->rota);
		data->p.old_plane = data->p.plane_x;
		data->p.plane_x = data->p.plane_x * cos(-ROTATION * data->rota) - \
		data->p.plane_y * sin(-ROTATION * data->rota);
		data->p.plane_y = data->p.old_plane * sin(-ROTATION * data->rota) + \
		data->p.plane_y * cos(-ROTATION * data->rota);
	}
	else if (key == 65361)
		key_press_2(data);
	return (0);
}

int	key_release(int key, t_data *data)
{
	(void)data;
	if (key == 65307)
		quit(data);
	if (key == 119)
		data->key[0] = 0;
	if (key == 100)
		data->key[1] = 0;
	if (key == 115)
		data->key[2] = 0;
	if (key == 97)
		data->key[3] = 0;
	return (0);
}

int	run_data(t_data *data)
{
	raycasting(data);
	mini_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img->img, 0, 0);
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->size_line + x * \
	(data->img->bpp / 8));
	*(unsigned int *)dst = color;
}

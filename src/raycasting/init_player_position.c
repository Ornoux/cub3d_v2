/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:39:03 by npatron           #+#    #+#             */
/*   Updated: 2024/05/14 19:39:04 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	init_angleplayer(t_data *data)
{
	if (data->char_player == 'N')
	{
		data->p.dirp_x = -1;
		data->p.dirp_y = 0;
	}
	else if (data->char_player == 'S')
	{
		data->p.dirp_x = 1;
		data->p.dirp_y = 0;
	}
	else if (data->char_player == 'E')
	{
		data->p.dirp_x = 0;
		data->p.dirp_y = 1;
	}
	else if (data->char_player == 'W')
	{
		data->p.dirp_x = 0;
		data->p.dirp_y = -1;
	}
}

void	define_rota(t_data *data)
{
	if (data->char_player == 'N' || data->char_player == 'E')
		data->rota = (PI / 4);
	else if (data->char_player == 'S' || data->char_player == 'W')
		data->rota = -(PI / 4);
	else
		return ;
}

void	define_angle(t_data *data)
{
	if (data->char_player == 'N' || data->char_player == 'S')
	{
		data->p.plane_x = 0;
		data->p.plane_y = 0.66;
	}
	if (data->char_player == 'W' || data->char_player == 'E')
	{
		data->p.plane_x = 0.66;
		data->p.plane_y = 0;
	}
}

void	init_raycast(t_data *data) // OK
{
	init_angleplayer(data);
	define_rota(data);
	define_angle(data);
	data->p.pos_x = data->posi_x + 0.5;
	data->p.pos_y = data->posi_y + 0.5;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:53:45 by npatron           #+#    #+#             */
/*   Updated: 2024/05/09 19:29:12 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

int	lines_into_files(char *argv)
{
	int		fd;
	int		lines;
	char	*s;

	fd = open(argv, O_RDONLY);
	lines = 0;
	s = get_next_line(fd);
	free(s);
	while (s)
	{
		s = get_next_line(fd);
		free(s);
		lines++;
	}
	close(fd);
	return (lines);
}

int	get_file(char **argv)
{
	int fd;
	int	lines;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (print_error(FD));
	lines = lines_into_files(argv[1]);
	if (lines == 0)
		return (print_error(EMPTY_FILE));
	close(fd);
	return (0);
	
}
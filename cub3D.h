/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npatron <npatron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:09:49 by npatron           #+#    #+#             */
/*   Updated: 2024/05/10 16:34:52 by npatron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>


# define NO 1
# define SO 2
# define WE 3
# define EA 4

# define ARG "Error.\ncub3D needs to be launched with a '*.cub'"
# define FD "Error.\nFile cannot be open"
# define EMPTY_FILE "Error.\nFile is empty"
# define BAD_EXTENSION "Error.\nBad extension, please, run cub3D with a '*.cub'"
# define BAD_TEXTURES "Error.\nBad textures, please, do something..."
# define BAD_COLORS "Error.\nBad colors, please, do something..."
# define BAD_RANGE "Error.\nColors are RGB[0 - 255] for each";

typedef struct s_data
{
	char	player_direction;
	
	char	**file;
	char	**map;
	char	**textures;
	char	**colors;
	
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;

	char	*floor_color;
	char	*sky_color;

	
	
	int		*dir;
	int		lines_into_file;
		
}			t_data;

// PARSING





// GET_NEXT_LINE PART

char	*get_next_line(int fd);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *s);


// UTILS PART

int		print_error(char *s);
int		get_file(t_data *data, char **argv);
int		lines_into_files(char *argv);
void	free_char_tab(char **tab);
void	print_tab(char **tab);
int		launch_parsing(char **argv, t_data *data);


#endif
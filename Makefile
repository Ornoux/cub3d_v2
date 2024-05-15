# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npatron <npatron@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 18:09:47 by npatron           #+#    #+#              #
#    Updated: 2024/05/14 19:59:59 by npatron          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SOURCES = src/main.c \
			src/parsing/get_file.c \
			src/parsing/get_map.c \
			src/parsing/utils_get_map.c \
			src/parsing/utils_get_map_2.c \
			src/parsing/run_parsing.c \
			src/parsing/get_textures.c \
			src/utils/utils.c \
			src/utils/ft_atoi.c \
			src/utils/ft_split.c \
			src/utils/get_next_line/get_next_line.c \
			src/utils/get_next_line/get_next_line_utils.c \
			src/parsing/get_colors.c \
			src/parsing/colors_to_int.c \
			src/raycasting/raycasting.c \
			src/raycasting/raycasting_3.c \
			src/raycasting/raycasting_2.c \
			src/mlx/create_img.c \
			src/mlx/init_mlx.c \
			src/mlx/mlx_utils.c \
			src/mlx/moves.c \
			src/mini_map/mini_map.c \
			src/raycasting/init_player_position.c \
		 	
OBJECTS  = ${SOURCES:.c=.o}

MLX_PATH = ./minilibx
MLX      = $(MLX_PATH)/libmlx.a

CFLAGS     = -Wall -Wextra -Werror -g -O3
LDFLAGS    = -L ${MLX_PATH} -lm -lbsd -lX11 -lXext -lmlx 


.c.o:
	clang $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): ${MLX} ${OBJECTS}
	clang $(CFLAGS) ${OBJECTS} $(LDFLAGS) -o $(NAME) ./minilibx/libmlx.a

all: $(NAME)


$(MLX):
	make -C $(MLX_PATH) all

clean:
	make -C $(MLX_PATH) clean
	rm -f ${OBJECTS}

fclean: clean
	rm -f $(NAME)

re: fclean all

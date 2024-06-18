# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 17:01:19 by mafourni          #+#    #+#              #
#    Updated: 2024/06/18 14:51:43 by mafourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f
# SRC = EXEMPLE.c

# # BONUS
# SRC_BONUS = Bonus/exec/image_player.c Bonus/exec/text_and_resume.c Bonus/utils/free.c Bonus/utils/innit.c Bonus/parsing/flood_fill.c Bonus/exec/sound_and_change_image.c.c Bonus/exec/direction_key.c Bonus/exec/key_press.c Bonus/parsing/check_arg.c Bonus/parsing/check_fd/full_map.c Bonus/exec/main.c Bonus/parsing/check_fd/check_place.c Bonus/exec/image.c
# OBJ_BONUS = $(SRC:.c=.o)

# LIBFT_DIR_BONUS = Bonus/libft
# LIBFT_LIB_BONUS = $(LIBFT_DIR_BONUS)/libft.a

# MLX42_DIR_BONUS = Bonus/MLX42
# MLX42_LIB_BONUS = $(MLX42_DIR)/build/libmlx42.a

# HEADERS_MLX42_BONUS = $(MLX42_DIR_BONUS)/include/MLX42
# HEADERS_GLFW_BONUS = /Users/mafourni/homebrew/opt/glfw/lib
# HEADERS_LIB_BONUS = $(LIBFT_DIR_BONUS)

#PAS BONUS
SRC = exec/image_player.c exec/text_and_resume.c utils/free.c utils/innit.c parsing/flood_fill.c exec/sound_and_change_image.c.c exec/direction_key.c exec/key_press.c parsing/check_arg.c parsing/check_fd/full_map.c exec/main.c parsing/check_fd/check_place.c exec/image.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a

HEADERS_MLX42 = $(MLX42_DIR)/include/MLX42
HEADERS_GLFW = /Users/mafourni/homebrew/opt/glfw/lib
HEADERS_LIB = $(LIBFT_DIR)


# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 to compil

# bonus : $(LIBFT_LIB_BONUS) $(MLX42_LIB_BONUS) $(NAME_BONUS)

all : $(LIBFT_LIB) $(MLX42_LIB) $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

# $(LIBFT_LIB_BONUS):
# 	@make -C $(LIBFT_DIR_BONUS)

%.o: %.c
	gcc $(CFLAGS) -I. -I$(HEADERS_MLX42) -I$(HEADERS_GLFW) -I$(HEADERS_LIB) -c $< -o $@

# %.o: %.c
# 	gcc $(CFLAGS) -I. -I$(HEADERS_MLX42_BONUS) -I$(HEADERS_GLFW) -I$(HEADERS_LIB_BONUS) -c $< -o $@ 

$(NAME): $(OBJ)
	 	gcc  $(CFLAGS) $(OBJ) -I. -I$(HEADERS_MLX42) -L$(HEADERS_GLFW) -I$(HEADERS_LIB) -L$(LIBFT_DIR) -lft -L$(MLX42_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit -o $@

# $(NAME_BONUS): $(OBJ_BONUS)
# 	 	gcc  $(CFLAGS) $(OBJ_BONUS) -I. -I$(HEADERS_MLX42_BONUS) -L$(HEADERS_GLFW) -I$(HEADERS_LIB_BONUS) -L$(LIBFT_DIR_BONUS) -lft -L$(MLX42_DIR_BONUS)/build -lmlx42 -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit -o $@

clean:
	$(RM) $(OBJ)
	# $(RM) $(OBJ_BONUS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	# $(RM) $(NAME_BONUS)
	@make -C $(LIBFT_DIR) fclean 

re: fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mafourni <mafourni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/05 17:01:19 by mafourni          #+#    #+#              #
#    Updated: 2024/04/14 17:15:48 by mafourni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
RM = rm -f
SRC = pars/check_arg/check_arg.c pars/check_fd/full_map.c exec/main.c sidequest.c
		pars/check_fd/
OBJ = $(SRC:.c=.o)

#LIB
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

MLX42_DIR = MLX42
MLX42_LIB = $(MLX42_DIR)/build/libmlx42.a

#HEADERS
HEADERS_MLX42 = $(MLX42_DIR)/include/MLX42
HEADERS_GLFW = /Users/mafourni/homebrew/opt/glfw/lib
HEADERS_LIB = $(LIBFT_DIR)


# libmlx:
# 	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4 to compil

all : $(LIBFT_LIB) $(MLX42_LIB) $(NAME)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

%.o: %.c
	gcc $(CFLAGS) -I. -I$(HEADERS_MLX42) -I$(HEADERS_GLFW) -I$(HEADERS_LIB) -c $< -o $@ 

$(NAME): $(OBJ)
	 	gcc  $(CFLAGS) $(OBJ) -I. -I$(HEADERS_MLX42) -L$(HEADERS_GLFW) -I$(HEADERS_LIB) -L$(LIBFT_DIR) -lft -L$(MLX42_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm -framework Cocoa -framework OpenGL -framework IOKit -o $@

clean:
	$(RM) $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean 

re: fclean all
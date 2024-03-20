# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eerazo-c <eerazo-c@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 16:36:16 by eerazo-c          #+#    #+#              #
#    Updated: 2024/03/20 13:35:07 by eerazo-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
HEADER = Inc/fractol.h
CFLAGS = -Wall -Wextra -Werror -Imlx
MINIFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX = ./mlx/libmlx.a
LIBFT = ./Inc/libft/libft.a
LIB_PRINTF = ./Inc/printf/libftprintf.a

SOURCES = src/main.c src/fractal_initit.c src/fractol.c src/math_util.c
CC = cc

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJECTS) $(MLX) $(LIBFT) $(LIB_PRINTF)  
	$(CC) $(CFLAGS) $^ -o $(NAME) $(MINIFLAGS)

$(MLX):
	make -C mlx

$(LIBFT):
	make -C Inc/libft

$(LIB_PRINTF):
	make -C Inc/printf

clean:
	rm -rf $(OBJECTS)
	make clean -C mlx
	make clean -C Inc/libft
	make clean -C Inc/printf
fclean: clean
	rm -f $(NAME)
	make clean -C mlx
	make fclean -C Inc/libft
	make fclean -C Inc/printf
re: fclean all

.PHONY: all clean fclean re lib

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpfeffer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/06 10:05:14 by jpfeffer          #+#    #+#              #
#    Updated: 2017/04/06 10:05:15 by jpfeffer         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FDF = fdf

C_FILES = validation.c generate_map.c draw.c window.c fdf.c

LIBFT		=	./libft/libft.a
PRINTF		=	./libraries/ft_printf/libftprintf.a
MLX			=	./minilibx_macos/libmlx.a
LIBLINK		=	-L ./libraries -lfdf
LIBRARY		=	./libraries/libfdf.a

SRCS = $(C_FILES)

C_FLAGS = -Wall -Werror -Wextra

FRAMEWORK = -framework OpenGL -framework AppKit

.PHONY: all library libft printf mlx test clean cleanmlx fclean re

all: library $(FDF)

library: libft printf mlx $(LIBRARY)

$(LIBRARY):
	@libtool -static -o ./libraries/libfdf.a ./libft/libft.a \
	./libraries/ft_printf/libftprintf.a ./minilibx_macos/libmlx.a

libft: $(LIBFT)

$(LIBFT):
	@make -C ./libft

printf: $(PRINTF)

$(PRINTF):
	@make -C ./libraries/ft_printf

mlx: $(MLX)

$(MLX):
	@make -C ./minilibx_macos

$(FDF):
	@gcc $(C_FLAGS) $(LIBLINK) $(FRAMEWORK) $(SRCS) -o fdf

test: fclean library
	@gcc $(SRCS) $(LIBLINK) $(FRAMEWORK) -o fdf

ftest: fclean library
	@gcc $(SRCS) $(LIBLINK) $(FRAMEWORK) -fsanitize=address main.c -o fdf

clean:
	@make clean -C ./libft
	@make clean -C ./libraries/ft_printf
	@make clean -C ./minilibx_macos

cleanmlx:
		@make clean -C ./minilibx_macos
fclean: clean
	@rm -f $(PUSH_SWAP) $(CHECKER) $(LIBRARY) a.out test fdf
	@make fclean -C ./libft
	@make fclean -C ./libraries/ft_printf

re: fclean all
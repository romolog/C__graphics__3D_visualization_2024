# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 13:27:57 by rponomar          #+#    #+#              #
#    Updated: 2024/11/07 17:15:22 by rponomar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS_WWW = -Wextra -Wall
FLAGS_OPTIMIZE = -O3
FLAGS_LIBMLX = -L/usr/lib -lXext -lX11 -lm -lz

LIB_MLX	= ./libs/mlx42_paris/libmlx_Linux.a
LIB_LIBFT = ./libs/libft/libft.a

DIR_LIBFT = ./libs/libft
DIR_MLX = ./libs/mlx42_paris

LIBS = $(LIB_MLX) $(FLAGS_LIBMLX) $(LIB_LIBFT)

HEADERS	= -I./include/ -I./libs/mlx42_paris/ -I./libs/libft/

SRCS = $(shell find ./src -iname "*.c")

OBJS := ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS_WWW) $(FLAGS_OPTIMIZE) -c $< $(HEADERS) -o $@

$(LIB_LIBFT): 
	$(MAKE) -C $(DIR_LIBFT)


$(DIR_MLX):
	wget https://github.com/42Paris/minilibx-linux/archive/refs/heads/master.zip
	unzip master.zip -d libs
	rm -f master.zip
	mv ./libs/minilibx-linux-master ./libs/mlx42_paris

$(LIB_MLX): $(DIR_MLX)
	$(MAKE) -C $(DIR_MLX)

$(NAME): $(LIB_MLX) $(OBJS) $(LIB_LIBFT) Makefile
	$(CC) $(FLAGS_WWW) $(FLAGS_OPTIMIZE) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(DIR_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(DIR_LIBFT) fclean
	rm -rf $(DIR_MLX)

re: fclean all

.PHONY: all clean fclean re

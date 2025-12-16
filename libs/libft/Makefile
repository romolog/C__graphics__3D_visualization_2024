# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rponomar <rponomar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/25 15:02:51 by rponomar          #+#    #+#              #
#    Updated: 2024/10/10 17:05:41 by rponomar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_FILES =\
		ft_isalpha.c		ft_toupper.c	\
		ft_isdigit.c		ft_tolower.c	\
		ft_isalnum.c		ft_strchr.c		\
		ft_isascii.c		ft_strrchr.c	\
		ft_isprint.c		ft_strncmp.c	\
		ft_strlen.c			ft_memchr.c		\
		ft_memset.c			ft_memcmp.c		\
		ft_bzero.c			ft_strnstr.c	\
		ft_memcpy.c			ft_atoi.c		\
		ft_memmove.c		ft_printf.c		\
		ft_strlcpy.c		ft_printf_char.c\
		ft_strlcat.c		ft_printf_f.c	\
		ft_calloc.c			ft_printf_idu.c	\
		ft_strdup.c			ft_printf_llu_base.c	\
		ft_substr.c			ft_printf_long_base.c	\
		ft_strjoin.c		ft_printf_ptr.c	\
		ft_strtrim.c		ft_printf_reset_numlen.c\
		ft_split.c			ft_printf_str.c	\
		ft_itoa.c			ft_printf_xd.c	\
		ft_strmapi.c		ft_getline.c	\
		ft_striteri.c		ft_getline_utils.c	\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_lstnew.c	\
		ft_lstadd_front.c	\
		ft_lstsize.c	\
		ft_lstlast.c	\
		ft_lstadd_back.c	\
		ft_lstdelone.c	\
		ft_lstclear.c	\
		ft_lstiter.c	\
		ft_lstmap.c
		
SRC_PATH = ./
OBJ_PATH = ./
INCLD_PATH = ./

SRCS := $(addprefix $(SRC_PATH), $(C_FILES))
OBJS_T := $(addprefix $(OBJ_PATH), $(C_FILES))
OBJS = $(OBJS_T:.c=.o)

CC = cc
CC_WWW_FLAGS = -Wall -Wextra -Werror
CC_FLAGS = -g
INCLD_FLAGS = -I$(INCLD_PATH)

MAKE_LIB = ar rcs

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CC_WWW_FLAGS) $(CC_FLAGS) -c $< $(INCLD_FLAGS) -o $@

$(NAME): $(OBJS) Makefile
	$(MAKE_LIB) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
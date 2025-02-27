# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 08:13:50 by vicalons          #+#    #+#              #
#    Updated: 2025/02/27 11:16:33 by vicalons         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler
NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar -rcs
MAKE = make -sC
MKDIR = mkdir -p

# libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LINKER = -lft -L $(LIBFT_DIR)

# Includes
INCLUDES_DIR = includes
INCLUDES_FLAG = -I$(INCLUDES_DIR) \
			-I$(LIBFT_DIR) \

INCLUDES = $(wildcard $(INCLUDES_DIR)/*.h) \
	   	$(LIBFT_DIR)/libft.h

# Sources
SRCS_DIR = srcs/
SRC_FILES = main.c \
	    ft_atof.c \
	    ft_options.c \
	    ft_graph.c \
	    ft_initfractal.c \
	    ft_error.c \
	    ft_draw.c \
	    ft_scale.c \
	    ft_fractal.c \
	    ft_keyhook.c \
	    ft_close.c \
	    ft_mousehook.c

SRCS = $(addprefix $(SRCS_DIR), $(SRC_FILES))

# Objects
OBJS_DIR = objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
LINKER += -lmlx -lm -lz -lXext -lX11 -L $(MLX_DIR)
INCLUDES_FLAG += -I$(MLX_DIR)

all: $(LIBFT) $(MLX) $(OBJS_DIR) $(NAME)

$(LIBFT):
	@$(MAKE) $(LIBFT_DIR)

$(MLX) :
	@$(MAKE) $(MLX_DIR)

$(OBJS_DIR):
	@$(MKDIR) $(OBJS_DIR)

$(NAME): $(OBJS) Makefile
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR)

fclean:
	@$(RM) $(NAME)
	@$(MAKE) $(LIBFT_DIR) fclean
	@$(MAKE) $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re

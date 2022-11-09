# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 07:38:28 by clesaffr          #+#    #+#              #
#    Updated: 2022/10/28 20:37:02 by clesaffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	gcc

CFLAGS		=  -g3 -Wall -Werror -Wextra

SRCS		=	parsing.c

INCLUDES	=	-I ./includes -I ./minilibx-linux

LIBFT		=	libft.a

MLX			=	minilibx-linux

PATH_LIBFT	=	./libft/

PATH_MLX	=	./$(MLX)/

PATH_OBJS	=	.objs/

PATH_SRCS	=	srcs/

F_OBJS		=	$(addprefix $(PATH_OBJS), $(OBJS))

F_LIBFT		=	$(addprefix $(PATH_LIBFT), $(LIBFT))

OBJS		=	$(SRCS:.c=.o)

UNAME		:= $(shell uname)

all				: lib $(PATH_OBJS) $(NAME)

lib				: 
					make -C $(PATH_MLX)
					make -C $(PATH_LIBFT)

$(PATH_OBJS)	:	
					mkdir -p $(PATH_OBJS)

$(NAME)			:	$(F_OBJS)
					$(CC) $(CFLAGS) $(F_OBJS) -L $(MLX) $(F_LIBFT) -lmlx -lmlx_Linux -lXext -lX11 -o $(NAME)

$(PATH_OBJS)%.o	:	$(PATH_SRCS)%.c
						$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean			:
					rm -rf $(F_OBJS) $(PATH_OBJS)
					make clean -C $(PATH_LIBFT)

fclean			:	clean
					rm -f $(NAME)
					make fclean -C $(PATH_LIBFT)

re				:	fclean all

.PHONY: clean fclean all re lib

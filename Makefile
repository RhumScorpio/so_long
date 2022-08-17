# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 07:38:28 by clesaffr          #+#    #+#              #
#    Updated: 2022/08/12 00:40:03 by clesaffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SRCS		=	main.c

INCLUDES	=	-I ./includes -I ./minilibx-linux

MLX			=	minilibx-linux

PATH_MLX	=	./$(MLX)/

PATH_OBJS	=	.objs/

PATH_SRCS	=	srcs/

F_OBJS		=	$(addprefix $(PATH_OBJS), $(OBJS))

OBJS		=	$(SRCS:.c=.o)

all				: lib $(PATH_OBJS) $(NAME)

lib				: 
					make -C $(PATH_MLX)

$(PATH_OBJS)	:	
					mkdir -p $(PATH_OBJS)

$(NAME)			:	$(F_OBJS)
					$(CC) $(CFLAGS) $(F_OBJS) -L $(MLX) -lmlx -lmlx_Linux -lXext -lX11 -o $(NAME)

$(PATH_OBJS)%.o	:	$(PATH_SRCS)%.c
						$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean			:
					rm -rf $(F_OBJS) $(PATH_OBJS)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean all

.PHONY: clean fclean all re

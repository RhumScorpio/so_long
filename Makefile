# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clesaffr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 07:38:28 by clesaffr          #+#    #+#              #
#    Updated: 2021/11/05 08:54:36 by clesaffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fract_ol

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

SRCS		=	main.c

INCLUDES	=	-I ./includes

MLX			=	./mlx

PATH_OBJS	=	./.objs/

PATH_SRCS	=	./srcs/

F_OBJS		=	$(addprefix $(PATH_OBJS), $(OBJS))

OBJS		=	$(SRCS:.c=.o)

all				: lib $(PATH_OBJS) $(NAME)

lib				: 
					make -C $(MLX)

$(PATH_OBJS)	:	
					mkdir -p $(PATH_OBJS)

$(NAME)			:	$(F_OBJS)
						$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(PATH_OBJS)%.o	:	$(PATH_SRCS)%.c
						$(CC) $(INCLUDES) -I $(MLX) $(FLAGS) -c $< -o $@

clean			:
					rm -rf $(F_OBJS) $(PATH_OBJS)

fclean			:	clean
					rm -f $(NAME)

re				:	fclean all

.PHONY: clean fclean all re

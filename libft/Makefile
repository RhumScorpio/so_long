NAME	=	libft.a

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

SRCS	=	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strcpy.c\
			ft_strcat.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strnchr.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_size_of_doubletab.c\
			ft_free_doubletab.c\
			ft_toupper.c\
			ft_gnlstrjoin.c\
			ft_strndup.c\
			get_next_line.c

HEADER	= 	libft.h

OBJS	=	$(SRCS:.c=.o)

PATH_OBJS	=	.objs/

F_OBJS		=	$(addprefix $(PATH_OBJS), $(OBJS))

all		: $(PATH_OBJS) $(NAME)

$(NAME)	: $(F_OBJS) $(HEADER)
			ar rc $(NAME) $(F_OBJS)
			ranlib $(NAME)

$(PATH_OBJS) :
				mkdir -p $(PATH_OBJS)

$(PATH_OBJS)%.o		: %.c
						$(CC) $(CFLAGS) -c $< -o $@

clean	:
			rm -rf $(F_OBJS) $(PATH_OBJS)

fclean	: clean

re		: fclean all

.PHONY	: clean fclean all re

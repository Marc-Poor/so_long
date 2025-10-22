SRC     =	main.c			\
			ft_split.c		\
			ft_strlen.c		\
			ft_strdup.c		\
			ft_strcat.c	\
			ft_putnbr.c	\
			ft_putstr.c	\
			ft_realloc_str.c	\
			ft_strlcpy.c	\
			ft_strjoin.c	\
			get_next_line.c	\
			check_map.c	\
			open_window.c	\
			close_window.c	\
			solve_map.c	\
			find_in_str.c	\
			render.c	\
			move.c		\

OBJ		=	$(SRC:.c=.o)

MLX_DIR = minilibx-linux/minilibx-linux

NAME	=	so_long

all:	$(NAME)

$(NAME):	$(OBJ)
			cc $(OBJ) -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm -lz -o $(NAME)

%.o:	%.c
		cc -g -std=gnu17 -Wall -Wextra -Werror -I$(MLX_DIR) -O3 -c $< -o $@


clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re

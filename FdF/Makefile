NAME = fdf

SRCS = gnl/get_next_line.c draw.c fdf.c ft_join_pf.c init.c little_useful_func.c move_map.c parsing.c rot.c rot_size_ect.c validation.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C libft/
	@make -C minilibx_macos/
	@gcc -o $(NAME) $(SRCS) $(FLAGS) libft/libft.a -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

clean:
	@make clean -C libft
	@make clean -C minilibx_macos

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

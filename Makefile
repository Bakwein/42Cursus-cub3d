name=cub3d

# Path: srcs/

SRC= *.c

INCLUDES=./

all: $(name)

$(name):
	@gcc -Wall -Wextra -Werror -D BONUS=1 $(SRC) mlx/libmlx.a -I . -Lmlx -framework OpenGL -framework AppKit -o $(name)
	@echo "Cube3d compiled successfully ! 🎉"	
#silent minilibx compilation
mlx:
	@make --silent -C mlx

clean:
	@rm -rf obj


fclean: clean
	@rm -rf $(name)


re: fclean all
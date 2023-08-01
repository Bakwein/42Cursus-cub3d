name=cub3d
bname=cub3d_bonus
# Path: srcs/

SRC = 	src/bonus_texture_id.c \
		src/clean_exit.c \
		src/cub3d.c \
		src/door.c \
		src/get_next_line_utils.c \
		src/get_next_line.c \
		src/hook.c \
		src/minimap.c \
		src/minimap2.c \
		src/moving.c \
		src/put_column_image.c \
		src/screenshot.c \
		src/security.c \
		src/sprite.c \
		src/store_map.c \
		src/utils_basic.c \
		src/utils_bonus.c \
		src/utils_bonus2.c \
		src/utils_bonus3.c \
		src/utils_bonus4.c \
		src/utils_color.c \
		src/utils_initialize_struct_map.c \
		src/utils_libft.c \
		src/utils_mlx.c \
		src/utils_parsing.c \
		src/utils_raycasting.c \
		src/utils_space.c \
		src/utils_store_map.c \
		src/verification_map.c \
		src/verification_texture.c \
		src/mouse.c \
		src/str_fill.c

INCLUDES=./

obj= $(SRC:.c=.o)

all: $(name)

bonus: $(bname)

$(name): mlx
	@gcc -Wall -Wextra -Werror $(SRC) mlx/libmlx.a -I . -Lmlx -framework OpenGL -framework AppKit -o $(name)
	@echo "cub3d compiled successfully ! 🎉"
$(bname): mlx
	@gcc -Wall -Wextra -Werror -D BONUS=1 $(SRC) mlx/libmlx.a -I . -Lmlx -framework OpenGL -framework AppKit -o $(bname)
	@echo "cub3d_bonus compiled successfully ! 🎉"
#silent minilibx compilation
mlx:
	@make --silent -C mlx

clean:
	@rm -rf object
	@rm -rf object_bonus


fclean: clean
	@rm -rf $(name)
	@rm -rf $(bname)
	@make --silent -C mlx clean

re: fclean all

reb: fclean bonus

.PHONY: all clean fclean re bonus mlx
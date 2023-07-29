name=cub3d

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
		src/mouse.c

INCLUDES=./

all: $(name)

$(name):
	@gcc -Wall -Wextra -Werror -D BONUS=1 $(SRC) mlx/libmlx.a -I . -Lmlx -framework OpenGL -framework AppKit -o $(name)
	@echo "cub3d compiled successfully ! 🎉"	
#silent minilibx compilation
mlx:
	@make --silent -C mlx

clean:
	@rm -rf obj


fclean: clean
	@rm -rf $(name)


re: fclean all
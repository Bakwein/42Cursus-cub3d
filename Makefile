name=cub3d
bname=cub3d_bonus
# Path: srcs/

BONUSSRC = bonus/src/bonus_texture_id.c \
		   bonus/src/clean_exit.c \
		   bonus/src/cub3d.c \
		   bonus/src/door.c \
		   bonus/src/get_next_line_utils.c \
		   bonus/src/get_next_line.c \
		   bonus/src/hook.c \
		   bonus/src/minimap.c \
		   bonus/src/minimap2.c \
		   bonus/src/moving.c \
		   bonus/src/put_column_image.c \
		   bonus/src/screenshot.c \
		   bonus/src/security.c \
		   bonus/src/sprite.c \
		   bonus/src/store_map.c \
		   bonus/src/utils_basic.c \
		   bonus/src/utils_bonus.c \
		   bonus/src/utils_bonus2.c \
		   bonus/src/utils_bonus3.c \
		   bonus/src/utils_bonus4.c \
		   bonus/src/utils_color.c \
		   bonus/src/utils_initialize_struct_map.c \
		   bonus/src/utils_libft.c \
		   bonus/src/utils_mlx.c \
		   bonus/src/utils_parsing.c \
		   bonus/src/utils_raycasting.c \
		   bonus/src/utils_space.c \
		   bonus/src/utils_store_map.c \
		   bonus/src/verification_map.c \
		   bonus/src/verification_texture.c \
		   bonus/src/mouse.c \
		   bonus/src/str_fill.c

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

bobj= $(BONUSSRC:.c=.o)

all: $(obj) $(name)

bonus: mlx $(bobj) $(bname)

$(name):
	@make mlx
	@gcc -Wall -Wextra -Werror $(SRC) mlx/libmlx.a -I . -Lmlx -framework OpenGL -framework AppKit -o $(name)
	@mkdir object
	@mv src/*.o object
	@echo "cub3d compiled successfully ! 🎉"
$(bname):
	@gcc -Wall -Wextra -Werror -D BONUS=1 $(BONUSSRC) mlx/libmlx.a -I . -Lmlx -framework OpenGL -framework AppKit -o $(bname)
	@mkdir object_bonus
	@mv bonus/src/*.o object_bonus
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
name=cub3D
bname=cub3D_bonus
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

BSRC = 	bonus/src/bonus_texture_id.c \
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
INCLUDES=./

BINCLUDES=./bonus/

obj= $(SRC:.c=.o)

bobj= $(BSRC:.c=.o)

RED = \033[0;31m

GREEN = \033[0;32m

BLUE = \033[0;34m

CYAN = \033[0;36m

PURPLE = \033[0;35m

MAGENTA = \033[0;95m

Default = \033[0m


all: $(name)

bonus: $(bname)

.c.o:
	@gcc -Wall -Wextra -Werror -I $(INCLUDES) -c $< -o $(<:.c=.o)

$(name):
	@make mlx
	@mkdir object
	@gcc -Wall -Wextra -Werror $(SRC) mlx/libmlx.a -I $(INCLUDES) -Lmlx -framework OpenGL -framework AppKit -o $(name)
	@mv src/*.o object
	@rm -rf src/*.o
	@rm -rf bonus/src/*.o
	@echo "$(PURPLE)./$(MAGENTA)$(name)$(CYAN) compiled successfully !$(Default) 🎉"
$(bname):
	@make bmlx
	@mkdir object_bonus
	@gcc -Wall -Wextra -Werror -D BONUS=1 $(BSRC) mlx/libmlx.a -I $(BINCLUDES) -Lmlx -framework OpenGL -framework AppKit -o $(bname)
	@mv bonus/src/*.o object_bonus
	@rm -rf src/*.o
	@rm -rf bonus/src/*.o
	@echo "$(PURPLE)./$(MAGENTA)$(name)$(PURPLE)_bonus$(CYAN) compiled successfully !$(Default) 🎉"

mlx: norm $(obj)
	@make --silent -C mlx

bmlx: norm $(bobj)
	@make --silent -C mlx

clean:
	@rm -rf object
	@rm -rf object_bonus
	@echo "$(RED)$(name)$(CYAN) object files deleted !$(Default) 🗑️"


fclean: clean
	@rm -rf $(name)
	@rm -rf $(bname)
	@make --silent -C mlx clean
	@echo "$(RED)$(name)$(CYAN) deleted !$(Default) 🗑️"

norm:
	@norminette $(SRC) $(BSRC) ./cube3d.h bonus/cube3d.h
re: fclean all

reb: fclean bonus

.PHONY: all clean fclean re bonus mlx
NAME		= cub3D
LIBFT		= ./lib/libft/libft.a
MLX_DIR		= ./lib/mlx
LIBRARY		= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

LIBC		= ar rcs
CC			= gcc
RM			= rm -f

FLAGS		= -Wall -Wextra -Werror -Iinc

SRCS		= ./src/main.c \
			./src/exit/exit.c \
			./src/exit/free.c \
			./src/parsing/00_init_game.c \
			./src/parsing/01_parse_game.c \
			./src/parsing/02_parse_file.c \
			./src/parsing/03_parse_graphics.c \
			./src/parsing/04_parse_map.c \
			./src/parsing/05_flood_fill_map.c \
			./src/parsing/06_load_textures.c \
			./src/parsing/parsing_utils.c \
			./src/parsing/parsing_utils2.c \
			./src/hooks/key_hooks.c \
			./src/player/controls_player.c \
			./src/player/init_player.c \
			./src/player/move_player.c \
			./src/player/rotate_player.c \
			./src/raycasting/dda.c \
			./src/raycasting/draw_vertical.c \
			./src/raycasting/init_raycasting.c \
			./src/utils/pixel_put.c
BONUS		= ./src/bonus/minimap_cells.c \
			./src/bonus/minimap_draw.c \
			./src/bonus/minimap.c \
			./src/bonus/mouse_rotate.c

OBJS 		= $(SRCS:.c=.o)
BONUS_OBJ	= $(BONUS:.c=.o)

.c.o:
			@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all :		$(LIBFT) $(NAME)

$(NAME) :	${OBJS} ${LIBFT} 
			@echo "Building cub3D..."
			@${CC} ${OBJS} ${LIBFT} $(FLAGS) $(LIBRARY) -o ${NAME}

bonus:		$(LIBFT) $(OBJS) $(BONUS_OBJ)
			@echo "Building cub3D (with bonus)…"
			@$(CC) $(OBJS) $(BONUS_OBJ) $(LIBFT) $(FLAGS) $(LIBRARY) -o $(NAME)

$(LIBFT) :
			@echo "Building libft..."
			@make -C lib/libft > /dev/null 2>&1

clean:
			@echo "Cleaning..."
			@rm -f $(OBJS) $(BONUS_OBJ)
			@make clean -C lib/libft > /dev/null 2>&1

fclean:		clean
			@echo "Cleaning all..."
			@rm -f $(NAME)
			@make fclean -C lib/libft > /dev/null 2>&1

re:			fclean all

.PHONY : all bonus clean fclean re
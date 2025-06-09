# === Variables de configuration ===
NAME		= cub3D
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc
LIB_DIR		= lib
MLX_DIR		= $(LIB_DIR)/mlx
LIBFT_DIR	= $(LIB_DIR)/libft

MLX			= $(MLX_DIR)/libmlx.a
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

# === Fichiers sources ===
SRC_FILES = \
	main.c \
	exit/exit.c \
	exit/free.c \
	parsing/00_init_game.c \
	parsing/01_parse_game.c \
	parsing/02_parse_file.c \
	parsing/03_parse_graphics.c \
	parsing/04_parse_map.c \
	parsing/05_flood_fill_map.c \
	parsing/06_load_textures.c \
	parsing/parsing_utils.c \
	parsing/parsing_utils2.c \
	hooks/key_hooks.c \
	player/controls_player.c \
	player/init_player.c \
	player/move_player.c \
	player/rotate_player.c \
	raycasting/dda.c \
	raycasting/draw_vertical.c \
	raycasting/init_raycasting.c \
	utils/pixel_put.c \
	bonus/minimap_cells.c \
	bonus/minimap_draw.c \
	bonus/minimap.c \
	bonus/mouse_rotate.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# === Compilation des objets ===
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR) -c $< -o $@

# === Règle principale ===
$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS)
	@echo "\n✅ Compilation terminée : $(NAME)\n"

# === Compilation des libs ===
$(MLX):
	@echo "\n📦 Compilation de la bibliothèque MLX..."
	@make -s -C $(MLX_DIR) > /dev/null 2>&1

$(LIBFT):
	@echo "\n📦 Compilation de la bibliothèque LIBFT..."
	@make -s -C $(LIBFT_DIR) > /dev/null 2>&1

# === Règles standard ===
all: $(NAME)

clean:
	@echo "\n🧹 Suppression des fichiers objets..."
	@$(RM) -r $(OBJ_DIR)
	@make -s -C $(MLX_DIR) clean > /dev/null 2>&1
	@make -s -C $(LIBFT_DIR) clean > /dev/null 2>&1

fclean: clean
	@echo "\n🧹 Suppression complète...\n"
	@$(RM) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re
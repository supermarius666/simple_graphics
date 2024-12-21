# Nome del compilatore
CC = gcc

# Opzioni del compilatore
CFLAGS = -Wall -Wextra -Werror -g

# Directory della libreria
LIB_DIR = libs/minilibx-linux

# Directory degli header
INCLUDE_DIRS = -Iinclude -I$(LIB_DIR) 

# Nome della libreria
LIB = -lmlx_Linux

# File sorgente
SRC = $(wildcard src/*.c) 


LIB_MLX = $(LIB_DIR)/libmlx_Linux.a

# File oggetto
OBJ = $(SRC:.c=.o)

# Nome dell'eseguibile
NAME = graphics

# Regola di default
# $(LIB_MLX)
all:  $(NAME) 

# Regola per creare l'eseguibile
$(NAME): $(OBJ)
	$(CC) $(OBJ) -L$(LIB_DIR) $(LIB) -L/usr/lib $(INCLUDE_DIRS) -lXext -lX11 -lm -lz -o $(NAME) 

# Regola per creare i file oggetto
%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include $(INCLUDE_DIRS) -O3 -c $< -o $@

# $(LIB_MLX):
# 	$(MAKE) -C $(LIB_DIR)

# Regola per pulire i file generati
clean:
	rm -f $(OBJ)
#	$(MAKE) -C $(LIB_DIR) clean

# Regola per pulire tutto
fclean: clean
	rm -f $(NAME)
#	$(MAKE) -C $(LIB_DIR) clean
# Regola per ricostruire tutto
re: fclean all

.PHONY: all clean fclean re
NAME = push_swap
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEADER = includes/push_swap.h

SRC_DIR = srcs
OBJ_DIR = objs

SRCS = push_swap_rules.c\
		push_swap_utils_a.c\
		ps_multi_rules.c\
		main.c\

SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = libft.a
LIBFT_DIR = libft
INCLUDES = -I$(LIBFT_DIR) -Iincludes 

$(NAME): $(OBJS) $(LIBFT)
	cc $(FLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)  # Crée le dossier obj/ s'il n'existe pas
	cc $(FLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(LIBFT_DIR)/$(LIBFT)

re: fclean all

.PHONY: all clean fclean re

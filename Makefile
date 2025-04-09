NAME = push_swap
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

HEADER = includes/push_swap.h

SRC_DIR = srcs
OBJ_DIR = objs

SRCS = push_swap_rules.c\
		ps_fill_stack.c\
		ps_add_indexs.c\
		ps_multi_rules.c\
		ps_check_sorted.c\
		ps_small_sorts.c\
		ps_sort.c\
		ps_costs.c\
		ps_utils.c\
		ps_utils_2.c\
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

tester:
	@git clone https://github.com/LeoFu9487/push_swap_tester.git

visualizer:
	@git clone https://github.com/o-reo/push_swap_visualizer.git
	@mkdir push_swap_visualizer/build
	@cd push_swap_visualizer/build && cmake ..
	@cd push_swap_visualizer/build && make

checker:
	@wget https://cdn.intra.42.fr/document/document/25656/checker_linux
	@chmod 777 checker_linux

test:
	@echo "Enter arguments:"
	@read ARGS; \
	./push_swap $$ARGS | ./checker $$ARGS
    
end:
	@rm -rf checker_linux
	@rm -rf push_swap_tester
	@rm -rf push_swap_visualizer

.PHONY: all clean fclean re tester

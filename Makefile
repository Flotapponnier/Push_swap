CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
INCLUDES = -I./includes
SRC = srcs/main.c \
srcs/valid/valid_parameters/valid_parameters.c \
srcs/valid/valid_parameters/valid_multiple_parameters.c \
srcs/initialisation/init_list.c \
srcs/initialisation/checking_list.c \
srcs/algorithm/action/action_pab.c \
srcs/algorithm/action/action_rab.c \
srcs/algorithm/action/action_rrab.c \
srcs/algorithm/action/action_sab.c \
srcs/algorithm/count_action/count_rab.c \
srcs/algorithm/count_action/count_rrab.c \
srcs/algorithm/tiny_middle/tiny_middle_sort.c \
srcs/algorithm/push_swap/launch_action.c \
srcs/algorithm/push_swap/launch_action_b.c \
srcs/algorithm/push_swap/push_swap.c \
srcs/algorithm/push_swap/push_swap_utils.c \
srcs/algorithm/push_swap/push_swap_utils2.c \
srcs/algorithm/find_algorithm.c \
srcs/utils/utils.c \
srcs/utils/utils2.c \
srcs/error/error.c

OBJ = $(SRC:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C ./libft

clean:
	rm -f $(OBJ)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re

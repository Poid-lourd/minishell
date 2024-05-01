NAME = minishell
CC = gcc
CFLAGS := -Wall -Wextra -Werror
SOURCE = \
	Main/main.c

OBJECTS = $(patsubst %.c,obj_dir/%.o,$(SOURCE))
LIBFT = Libft/libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) -L libft -lft -o $(NAME) -lreadline

$(LIBFT):
	@make -C Libft

obj_dir/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C libft
	@rm -f $(OBJECTS)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@rm -rf obj_dir

re: fclean all

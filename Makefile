NAME = minishell

CC = gcc
READLINE_PATH = /Users/pcardin/.local/opt/readline
CFLAGS = -I$(READLINE_PATH)/include -Wall -Wextra -Werror
LDFLAGS = -L$(READLINE_PATH)/lib -lreadline

SOURCE = \
	Main/main.c \
	Parsing/parsing.c \
	Execution/exec.c \
	Utils/utils.c Utils/parsing_utils.c Utils/exec_utils.c

OBJECTS = $(patsubst %.c,obj_dir/%.o,$(SOURCE))
LIBFT = Libft/libft.a

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -L libft -lft -o $(NAME) -lreadline

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

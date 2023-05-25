NAME		=	philo

BIN_DIR		=	bin/
SRCS_DIR	=	src/

SRCS		=	philo.c \
				error.c \
				ft_isint.c \
				utils.c \
				ft_atoi.c \
				fork.c \
				launch.c

OBJS		=	$(addprefix ${BIN_DIR}, ${SRCS:.c=.o})

${BIN_DIR}%.o: ${SRCS_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) $(NAME)
	@echo "philo compiled"

$(NAME): $(OBJS)
	@echo "philo compiling"
	@$(CC) -fsanitize=thread $(OBJS) -o $(NAME)

$(BIN_DIR):
	@mkdir -p bin

clean:
	@rm -fr $(BIN_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
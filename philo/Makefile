NAME		=	philo

BIN_DIR		=	bin/
SRCS_DIR	=	src/

SRCS		=	philo.c \
				error.c \
				ft_isint.c \
				utils.c

OBJS		=	$(addprefix ${BINDIR}, ${SRCS:.c=.o})

${BINDIR}%.o: ${SRCS_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

$(BIN_DIR):
	@mkdir -p bin

clean:
	@rm -fr $(BIN_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
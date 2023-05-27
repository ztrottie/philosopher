NAME		=	philo

BIN_DIR		=	bin/
SRCS_DIR	=	src/

CC			=	gcc
CFLAGS		=	-Wextra -Werror -Wall

SRCS		=	philo.c \
				error.c \
				ft_isint.c \
				utils.c \
				ft_atoi.c \
				fork.c \
				life.c \
				time.c

OBJS		=	$(addprefix ${BIN_DIR}, ${SRCS:.c=.o})

${BIN_DIR}%.o: ${SRCS_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) $(NAME)
	@echo "philo compiled"

$(NAME): $(OBJS)
	@echo "philo compiling"
	@$(CC) $(OBJS) -o $(NAME)

$(BIN_DIR):
	@mkdir -p bin

clean:
	@rm -fr $(BIN_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
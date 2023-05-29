NAME		=	philo_bonus

BIN_DIR		=	bin/
SRCS_DIR	=	src/

CC			=	gcc
CFLAGS		=	-Wextra -Werror -Wall

SRCS		=	main_bonus.c \
				error_bonus.c \
				ft_isint_bonus.c \
				utils_bonus.c

OBJS		=	$(addprefix ${BIN_DIR}, ${SRCS:.c=.o})

${BIN_DIR}%.o: ${SRCS_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) $(NAME)
	@echo "philo_bonus compiled"

$(NAME): $(OBJS)
	@echo "philo_bonus compiling"
	@$(CC) $(OBJS) -o $(NAME)

$(BIN_DIR):
	@mkdir -p bin

clean:
	@rm -fr $(BIN_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
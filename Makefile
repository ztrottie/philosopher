NAME			=	philo

BINDIR			=	bin/
INCDIR			=	include/

PHILO_DIR		=	src/philo/

CC				=	gcc
CFLAGS			=	-Wextra -Wall -Werror -Wunreachable-code -Ofast

PHILO_SRCS		=	main.c

PHILO_OBJS		=	$(addprefix ${BINDIR}, ${PHILO_SRCS:.c=.o})

all:  $(BINDIR) $(NAME)

${BINDIR}%.o: ${PHILO_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(PHILO_OBJS)
	@$(CC) $(PHILO_OBJS) -o $(NAME)

$(BINDIR):
	@mkdir -p bin

clean:
	@rm -fr $(BINDIR)
	@$(MAKE) -C $(LIBFTT) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all, clean, fclean, re
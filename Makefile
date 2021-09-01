NAME = philo

SRCS = main.c\
			init.c\
			utils.c\
			utils2.c

OBJS = $(SRCS:.c=.o)

GCC = clang

FLAGS = -Wall -Wextra -Werror -lpthread

%.o: %.c
	$(GCC) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	clang $(FLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette *.c
	norminette *.h

.PHONY:	all clean fclean re norm

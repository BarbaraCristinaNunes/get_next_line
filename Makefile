NAME = ft_display_file

SRCS = ft_display_file.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

ifdef BUFFER_SIZE
    CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)
else
    CFLAGS += -D BUFFER_SIZE=19
endif

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
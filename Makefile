NAME = get_next_line

SRCS = get_next_line.c \
		get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

ifdef BUFFER_SIZE
    CFLAGS += -D BUFFER_SIZE=$(BUFFER_SIZE)
else
    CFLAGS += -D BUFFER_SIZE=2
endif

all: $(NAME)

$(NAME): $(OBJS) get_next_line.h
	gcc $(CFLAGS) -Iget_next_line.h -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
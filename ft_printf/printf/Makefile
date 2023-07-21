NAME	= libftprintf.a
CC 		= gcc
INC 	= libftprintf.h
CFLAGS 	= -Wall -Wextra -Werror
AR 		= ar -rcs
RM 		= rm -rf

SRCS =	ft_helpers.c \
		ft_printf.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = all clean fclean re
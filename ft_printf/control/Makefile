NAME	= libftprintf.a
CC 		= gcc
INC 	= ft_printf.h
CFLAGS 	= -Wall -Wextra -Werror
AR 		= ar -rcs
RM 		= rm -rf

SRCS =	ft_helpers.c \
		ft_printf.c \
		ft_hexa.c

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
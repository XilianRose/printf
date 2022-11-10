# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mstegema <mstegema@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 11:28:55 by mstegema      #+#    #+#                  #
#    Updated: 2022/11/10 12:45:17 by mstegema      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c \
	ft_print_hex.c \
	ft_utils.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
HEADER = ft_printf.h
PURPLE = \033[0;35m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(PURPLE)$(NAME)$(NC) has been created"

%.o: %.c $(HEADER)
	@cc -c $(CFLAGS) $< -o $@
	@echo "Compiling: $(PURPLE)$<$(NC)"

clean:
	@rm -f *.o
	@echo "$(PURPLE)object files$(NC) have been removed"

fclean: clean
	@rm -f $(NAME)
	@echo "$(PURPLE)$(NAME)$(NC) has been removed"

re: fclean all

.PHONY: all clean fclean re

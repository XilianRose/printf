# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile.mak                                       :+:    :+:             #
#                                                      +:+                     #
#    By: mstegema <mstegema@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/28 11:28:55 by mstegema      #+#    #+#                  #
#    Updated: 2022/10/28 11:30:21 by mstegema      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS =
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
HEADER = libftprintf.h
PURPLE = \033[0;35m
NC = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "$(PURPLE)object files have been created$(NC)"
	@echo "$(PURPLE)$(NAME) has been created$(NC)"

%.o: %.c $(HEADER)
	@cc -c $(CFLAGS) $< -o $@

clean:
	@rm -f *.o
	@echo "$(PURPLE)object files have been removed$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(PURPLE)$(NAME) has been removed$(NC)"

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	@ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "$(PURPLE)regular & bonus object files have been created$(NC)"
	@echo "$(PURPLE)$(NAME) with bonus has been created$(NC)"

.PHONY: all clean fclean re bonus

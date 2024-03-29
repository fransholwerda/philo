# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fholwerd <fholwerd@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/11/29 15:00:02 by fholwerd      #+#    #+#                  #
#    Updated: 2022/12/23 15:29:10 by fholwerd      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ROOT	= $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
NAME	= philo
SRC		= $(ROOT)src/main.c \
			$(ROOT)src/arbiter.c \
			$(ROOT)src/eat.c \
			$(ROOT)src/philo_thread.c \
			$(ROOT)src/philosopher.c \
			$(ROOT)src/threads.c \
			$(ROOT)src/struct/philo_struct_utility.c \
			$(ROOT)src/struct/info_struct_utility.c \
			$(ROOT)src/utils/freedom.c \
			$(ROOT)src/utils/ft_atoi.c \
			$(ROOT)src/utils/ft_isdigit.c \
			$(ROOT)src/utils/ft_isnum.c \
			$(ROOT)src/utils/ft_strlen.c \
			$(ROOT)src/utils/my_time.c \
			$(ROOT)src/utils/philo_print.c \
			$(ROOT)src/utils/stop.c
OBJ		= $(SRC:.c=.o)
INCLUDE	= -I$(ROOT)include \
			-I$(ROOT)include/utils \
			-I$(ROOT)include/struct_utils
LINKS	= 
CFLAGS	= -Wall -Werror -Wextra #-fsanitize=thread

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(NAME): $(OBJ)
	@echo "Compiling executable."
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) $(LINKS) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all libs clean fclean re
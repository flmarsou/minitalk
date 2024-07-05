# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flmarsou <flmarsou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 13:34:42 by flmarsou          #+#    #+#              #
#    Updated: 2024/07/05 09:41:09 by flmarsou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Files
SRC_SERVER =	./src/server.c \

SRC_CLIENT =	./src/client.c \

SRC_UTILS =		./src/utils/ft_putchr.c \
				./src/utils/ft_putstr.c \
				./src/utils/ft_putnbr.c \
				./src/utils/ft_puterr.c \
				./src/utils/ft_atoi.c \
				./src/utils/ft_strlen.c \

OBJ_SERVER =	${SRC_SERVER:.c=.o} ${SRC_UTILS:.c=.o}
OBJ_CLIENT =	${SRC_CLIENT:.c=.o} ${SRC_UTILS:.c=.o}

# Variables
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=address
RM		= rm -f

RESET		= \e[0m

WHITE		= \e[0;1;97m
_WHITE		= \e[1;4;97m
GREEN		= \e[0;1;32m
_GREEN		= \e[1;4;32m

# Makefile
all:		server client

server:		${OBJ_SERVER}
		@${CC} ${CFLAGS} ${OBJ_SERVER} -o server
		@echo "${GREEN}[✓] - ${_GREEN}Server${GREEN} Successfully Compiled!${RESET}"

client:		${OBJ_CLIENT}
		@${CC} ${CFLAGS} ${OBJ_CLIENT} -o client
		@echo "${GREEN}[✓] - ${_GREEN}Client${GREEN} Successfully Compiled!${RESET}"

%.o:		%.c
		@${CC} ${CFLAGS} -c $? -o $@

clean:
		@${RM} ${OBJ_SERVER} ${OBJ_CLIENT}
		@echo "${WHITE}[!] - ${_WHITE}Minitalk${WHITE} Successfully Cleaned!${RESET}"

fclean:		clean
		@${RM} server client

re:			fclean all

.PHONY: all server client clean fclean re

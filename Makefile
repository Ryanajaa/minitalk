# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarunota <jarunota@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 17:23:37 by jarunota          #+#    #+#              #
#    Updated: 2024/05/14 17:52:16 by jarunota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Define variables
CC 		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

# Define colors
DEFAULT_COLOR 	= \033[0;39m
RED 			= \033[0;91m
GREEN 			= \033[0;92m
YELLOW 			= \033[0;93m

SERVER = server
CLIENT = client

INCLUDE_DIR = ./include

MAKEFLAGS += --no-print-directory
CFLAGS += -I$(INCLUDE_DIR)
LIBFT	= ./libft/libft.a
SV_SRCS = src/server.c
SV_OBJS = ${SV_SRCS:.c=.o}
CLIENT_SRCS = src/client.c
CLIENT_OBJS = ${CLIENT_SRCS:.c=.o}

# Use .SILENT target to suppress all commands' output by default
.SILENT:

all: ${SERVER} ${CLIENT}

# The command 'make -C FT_PRINTF_DIR' is used to invoke the make utility to build a target in a specified directory 

${LIBFT}:
	@ echo "${YELLOW}Compiling LIBFT ${DEFAULT_COLOR}"
	@ ${MAKE} -C ./libft
	@ echo ""
	@ echo "${GREEN}LIBFT Compiled ${DEFAULT_COLOR}"
	@ echo ""
	
${SERVER}: ${SV_OBJS} ${LIBFT}
	@ echo "${YELLOW}Compiling Server ${DEFAULT_COLOR}"
	@ ${CC} ${CFLAGS} ${SV_OBJS} ${LIBFT} -o server
	@ echo "${GREEN}Server Compiled ${DEFAULT_COLOR}"
	
${CLIENT}: ${CLIENT_OBJS} ${LIBFT}
	@ echo "${YELLOW}Compiling Client ${DEFAULT_COLOR}"
	@ ${CC} ${CFLAGS} ${CLIENT_OBJS} ${LIBFT} -o client
	@ echo "${GREEN}Client Compiled ${DEFAULT_COLOR}"
	@ echo ""
	
# ${SERVER_BONUS}: ${SV_BONUS_OBJS} ${LIBFT}
# 	${CC} ${CFLAGS} ${SV_BONUS_OBJS} ${LIBFT} -o server_bonus
# ${CLIENT_BONUS}: ${CLIENT_BONUS_OBJS} ${LIBFT}
# 	${CC} ${CFLAGS} ${CLIENT_BONUS_OBJS} ${LIBFT} -o client_bonus

clean:
	@ ${MAKE} clean -C ./libft
	@ ${RM} ${SV_OBJS} ${CLIENT_OBJS}
#  ${RM} ${SV_BONUS_OBJS} ${CLIENT_BONUS_OBJS}
	@ echo "${RED}Cleaned ${DEFAULT_COLOR}"

fclean: clean
	@ ${MAKE} fclean -C ./libft
	@ ${RM} ${SERVER} ${CLIENT}
# ${RM} ${SERVER_BONUS} ${CLIENT_BONUS}

re: fclean all

# bonus: ${SERVER_BONUS} ${CLIENT_BONUS}

.PHONY: re fclean clean all
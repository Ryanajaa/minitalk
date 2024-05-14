# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jarunota <jarunota@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/31 13:34:04 by jarunota          #+#    #+#              #
#    Updated: 2024/05/14 18:18:27 by jarunota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#Define variables
CC 		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f
INCLUDE_DIR	= ./include
OBJS_DIR = ./obj
LIBFT_DIR = ./src/libft
GNL_DIR = ./src/get_next_line
PRINTF_DIR = ./src/ft_printf

# Define colors
DEFAULT_COLOR 	= \033[0;39m
RED 			= \033[0;91m
GREEN 			= \033[0;92m
YELLOW 			= \033[0;93m

LIBFT_SRCS =	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_memset.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strlen.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \
				ft_handle_error.c

GNL_SRCS	= 	get_next_line.c \
			  	get_next_line_utils.c

PRINTF_SRCS	=	c_str.c \
				nbr_unbr.c \
				ptr_hex.c \
				ft_printf.c

SRCS		= ${addprefix ${LIBFT_DIR}/, ${LIBFT_SRCS}} \
			  ${addprefix ${PRINTF_DIR}/, ${PRINTF_SRCS}} \
			  # ${addprefix ${GNL_DIR}/, ${GNL_SRCS}} 

# OBJS
OBJ			= ${SRCS:%.c=%.o}
OBJS		= ${addprefix ${OBJS_DIR}/, ${OBJ}}

IFLAGS		= ${addprefix -I, ${INCLUDE_DIR}}

# Build rules

${NAME}	: ${OBJS}
	@ ${AR} ${NAME} ${OBJS}
#	@ echo ""
#	@ echo "${GREEN}Updated libft.a${DEFAULT_COLOR}"
#	@ echo "${GREEN}Compiled libft.a successfully!${DEFAULT_COLOR}"
#	@ echo ""

${OBJS_DIR}/%.o	:%.c
	@mkdir -p ${OBJS_DIR}/${dir $<}
# 	@ echo "${YELLOW}Compiling: $<${DEFAULT_COLOR}"
	@ echo -n "${YELLOW}.${DEFAULT_COLOR}"
	@ ${CC} ${CFLAGS} ${IFLAGS} -c $< -o $@
#	@ echo "${GREEN}Created object files successfully${DEFAULT_COLOR}"

all	: ${NAME}

clean :
#	@ echo ""
	@ ${RM} -rf ${OBJS_DIR}
#	@ echo "${RED}Removed object files${DEFAULT_COLOR}"
	
fclean : clean
	@ ${RM} ${NAME}
#	@ echo "${RED}Removed 'libft.a' successfully${DEFAULT_COLOR}"
#	@ echo ""

re	: fclean all

.PYONY : all clean fclean re

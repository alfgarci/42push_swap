# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfgarci <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 18:06:47 by alfgarci          #+#    #+#              #
#    Updated: 2022/12/15 17:08:54 by alfgarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=\033[1;31m
GREEN	=\033[1;32m
YELLOW	=\033[1;33m
NC		=\033[0m

#---push_swap---------------------------
NAME 	=	push_swap
	#---SRC
SRC_DIR	=	src
SRC 	=	${SRC_DIR}/main.c \
			${SRC_DIR}/get_param.c \
			${SRC_DIR}/check_param.c \
			${SRC_DIR}/stack_utils.c \
			${SRC_DIR}/stack_utils_2.c \
			${SRC_DIR}/array_utils.c \
			${SRC_DIR}/moves.c \
			${SRC_DIR}/normalize_stk.c \
			${SRC_DIR}/push_swap.c
	#---OBJ
OBJ 	=	${SRC:.c=.o}
	#---INC
INC 	=	includes

#---LIBFT-------------------------------
LIBFT_DIR	=	libft
LIBFT_NAME	=	ft
	#---INC
LIBFT_INC	= ${LIBFT_DIR}/includes


CC			=	cc
C_FLAGS		=	-Werror -Wextra -Wall
LIB_FLAGS	=	-L${LIBFT_DIR} -l${LIBFT_NAME}
H_FLAGS		=	-I${INC} -I${LIBFT_INC}
FLAGS		=	${C_FLAGS} ${LIB_FLAGS}

#---RECIPES------------------------------
%.o : %.c
	@${CC} ${C_FLAGS} ${H_FLAGS} -c $< -o $@

all:	${NAME}

${NAME}: ${OBJ}
		@echo "${RED}Compiling Libft...${NC}"
		@make -s -C ${LIBFT_DIR}
		@echo "${RED}Compiling Push-swap...${NC}"
		@${CC} ${FLAGS} ${OBJ} -o ${NAME}
		@echo "${GREEN}${NAME} READY!${NC}"

clean:
		@make clean -s -C ${LIBFT_DIR}
		@rm -f ${OBJ}
		@echo "${YELLOW}OBJS REMOVED!${NC}"

fclean:		clean
		@make fclean -s -C ${LIBFT_DIR}
		@rm -f ${NAME}
		@echo "${YELLOW}${NAME} REMOVED!${NC}"

re:		fclean all

n:
	@norminette src/ libft/

.PHONY:	all clean fclean re

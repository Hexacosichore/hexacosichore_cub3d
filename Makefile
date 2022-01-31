# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 01:07:22 by kbarbry           #+#    #+#              #
#    Updated: 2022/01/30 12:29:09 by kbarbry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BBLU 		=	\033[1;34m
BGREEN		=	\033[1;32m
BRED		=	\033[1;31m
BLU 		=	\033[0;34m
GRN 		=	\033[0;32m
RED 		=	\033[0;31m
RST 		=	\033[0m

SRC_ENTRY	=	main.c
SRC_CHECK	=	extention.c \
				identifier.c \
				map.c \
				closed_map.c
SRC_EXIT	=	exit_cub3d.c
SRC_PARSING	=	parsing.c \
				init_cub3d.c \
				init_map.c
SRC_CAST	=	start.c \
				drawing.c \
				actualize.c \
				key_hook.c \
				ray_utils.c \
				maths_utils.c \
				minilib_utils.c

OBJ			=	${SRC_ENTRY:.c=.o} \
				${addprefix parsing/checking/,	${SRC_CHECK:.c=.o}} \
				${addprefix exit/,				${SRC_EXIT:.c=.o}} \
				${addprefix parsing/,			${SRC_PARSING:.c=.o}} \
				${addprefix ray_casting/,		${SRC_CAST:.c=.o}}

CC			=	gcc
FLAGS		=	-Iinclude -O3 -Wall -Werror -Wextra
FLAGS_MLX	=	-L minilibx -lmlx -framework OpenGL -framework Appkit
FLAGS_LIB	=	-lreadline -lncurses
FLAGS_LIBFT	=	-Llibft -lft
HEADER		=	cub3d.h
NAME		=	cub3d

all: ${NAME}

print_header:
	@echo "\033[1;34m\033[20G _____       _      ___________ "
	@echo "\033[1;34m\033[20G/  __ \     | |    |____ |  _  \\"
	@echo "\033[1;34m\033[20G| /  \/_   _| |__      / / | | |"
	@echo "\033[1;34m\033[20G| |   | | | | '_ \     \ \ | | |"
	@echo "\033[1;34m\033[20G| \__/\ |_| | |_) |.___/ / |/ / "
	@echo "\033[1;34m\033[20G \____/\__,_|_.__/ \____/|___/\n${RST}"

%.o:%.c ${HEADER}
	@${CC} ${FLAGS} -c $< -o $@
	@echo "${BBLU}[${NAME} OBJ] :${RST} $@ ${BGREEN}\033[70G[✔]${RST}"

${NAME}: print_header ${OBJ}
	@${MAKE} -C ./libft --no-print-directory
	@${CC} ${FLAGS} -o ${NAME} ${OBJ} ${FLAGS_LIB} ${FLAGS_LIBFT} ${FLAGS_MLX}
	@echo "${BGREEN}[${NAME} END] :${RST}${RST} ./${NAME} ${BGREEN}\033[70G[✔]${RST}"

clean:
	@${MAKE} -C ./libft clean --no-print-directory
	@rm -f ${OBJ}
	@echo "${RED}[CLEAN]  :${RST} Deleting objects...${BGREEN}\033[70G[✔]${RST}"

fclean:
	@${MAKE} -C ./libft fclean --no-print-directory
	@rm -f ${NAME}
	@rm -f ${OBJ}
	@echo "${RED}[${NAME} CLEAN]  :${RST} Deleting objects...${BGREEN}\033[70G[✔]${RST}"
	@echo "${RED}[${NAME} FCLEAN] :${RST} Deleting executable...${BGREEN}\033[70G[✔]${RST}"

test: ${NAME}
	./${NAME}

valgrind: ${NAME}
	valgrind --leak-check=full --track-origins=yes  ./${NAME}

re:	fclean all

.PHONY: clean fclean all re
SRC		= free_map.c group_imgs.c player_move.c check_map1.c free_textures.c \
		  render_borders.c check_map2.c		ft_init_vars.c	 render_frame.c \
		  count_objects.c ft_load_resources.c	map_path.c	   render_map.c \
		  display_stats.c game_end.c so_long.c  entity_move.c  game_utils.c \
		  free_imgs.c	  group_animgs.c		my_mlx_utils.c

SRCS		= ${addprefix ${PRE}, ${SRC}}

DIR_OBJS	= objs/

PRE			= srcs/

LIBFT_PATH	= ${PRE}libft
LIBFT		= ${LIBFT_PATH}/libft.a

OBJ			= ${SRC:.c=.o}
OBJS		= ${SRCS:.c=.o}
PRE_OBJS	= $(addprefix ${DIR_OBJS}, ${OBJ})

NAME		= so_long

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

MLXFLAGS	= -Lmlx_linux -lmlx -lXext -lX11

.c.o:
			@${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${LIBFT} ${OBJS} dup_obj ${PRE_OBJS} loading
			@${GCC} ${CFLAGS} -o ${NAME} ${PRE_OBJS} ${LIBFT} ${MLXFLAGS}
			@echo -ne 'GAME READY                          \r'
			@echo -ne '\n'

${LIBFT}:
			@make -s -C ${LIBFT_PATH} all

dup_obj:
			@mkdir -p ${DIR_OBJS}
			@mv ${OBJS} ${DIR_OBJS}

loading:
			@echo -ne 'LOADING\033[0;5m...\r'
			@sleep 1
			@echo -ne '\033[0;32m⦗❚❚❚❚❚❚                   ⦘(25%)\r'
			@sleep 0.2
			@echo -ne '⦗❚❚❚❚❚❚❚❚❚❚❚❚❚            ⦘(50%)\r'
			@sleep 0.2
			@echo -ne '⦗❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚     ⦘(75%)\r'
			@sleep 0.2
			@echo -ne '⦗❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚❚⦘(100%)\033[0m\r'
			@sleep 0.2

test:		${NAME}
			@echo -ne '\n\033[0;34mSTARTING TEST\n-------------\n\033[0m'
			@./${NAME}
			@echo -ne '\n\033[0;34m-------------\nENDING TEST\n\033[0m'
			@make -s fclean

all:		${NAME}

clean:
			@make -s -C ${LIBFT_PATH} clean
			@rm -rf ${DIR_OBJS}
			@echo -ne 'REMOVED OBJS\n'

fclean:		clean
			@make -s -C ${LIBFT_PATH} fclean
			@rm -f ${NAME}
			@echo -ne 'GAME UNINSTALLED\n'

re:			fclean all

.PHONY:		all clean fclean re test
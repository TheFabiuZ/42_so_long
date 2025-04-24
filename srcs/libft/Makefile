GNL_SRC		= get_next_line.c get_next_line_utils.c

DIR_OBJS	= objs/

PRINTF_PATH	= ft_printf
PRINTF		= ${PRINTF_PATH}/libftprintf.a

OBJS		= ${GNL_SRC:.c=.o}
PRE_OBJS	= $(addprefix ${DIR_OBJS}, ${OBJS})

NAME		= libft.a

GCC			= gcc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar

${DIR_OBJS}%.o:	%.c get_next_line.h
			@mkdir -p ${DIR_OBJS}
			@${GCC} ${CFLAGS} -c $< -o $@

${NAME}:	${PRINTF} ${PRE_OBJS}
			@cp ${PRINTF} ${NAME}
			@${AR} -crs ${NAME} ${PRE_OBJS}
			@echo -ne 'libft CREATED                    \r'
			@echo -ne '\n'

${PRINTF}:
			@make -s -C ${PRINTF_PATH} all

all:		${NAME}

bonus:
			@make -s -C ${PRINTF_PATH} bonus

clean:
			@make -s -C ${PRINTF_PATH} clean
			@rm -rf ${DIR_OBJS}
			@echo -ne 'REMOVED OBJS\n'

fclean:		clean
			@make -s -C ${PRINTF_PATH} fclean
			@rm -f ${NAME}
			@echo -ne 'REMOVED libft.a\n'

re:			fclean all

.PHONY:		all clean fclean re bonus
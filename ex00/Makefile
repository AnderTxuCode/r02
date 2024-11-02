SCRS	= src/main.c src/converter.c src/converting.c src/functionsutils.c src/readfile.c src/readingfile.c src/readlines.c src/readdict.c

OBJS	= ${SCRS:.c=.o}

NAME	= rush-02

.c.o:	${CC} -c $< -o ${<:.c=.o}

CC		= cc -Wall -Wextra -Werror -Iutils

all:		${OBJS}
			${CC} -o ${NAME} ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

.PHONY:		all clean fclean

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpascrea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/26 09:56:41 by lpascrea          #+#    #+#              #
#    Updated: 2020/09/27 21:30:02 by lpascrea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c fct.c struct.c check_dict.c numbers.c

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

CC		= gcc
RM		= rm -f

CFLAGES	= -Wall -Wextra -Werror

.c.o:	
			${CC} ${CFLAGES} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

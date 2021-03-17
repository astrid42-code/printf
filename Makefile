# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/15 14:12:00 by asgaulti          #+#    #+#              #
#    Updated: 2021/03/15 21:54:06 by astridgault      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_struct.c ft_fill_struct_prec.c ft_utils.c ft_utils2.c\
			ft_parser.c ft_treat_c.c ft_treat_str.c ft_treat_i.c \
			ft_annexe_i.c  ft_annexe_i2.c

OBJS	=	${SRCS:.c=.o}

CC		=	clang
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra -c

.c.o:
			${CC} ${CFLAGS} -g $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re

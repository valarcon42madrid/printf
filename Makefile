# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: valarcon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 18:39:24 by valarcon          #+#    #+#              #
#    Updated: 2022/03/01 19:23:40 by valarcon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_atoi.c  ft_hexalen.c    ft_printer_c.c  ft_printer_d.c  ft_printer_p.c  ft_printer_s.c  ft_printer_u.c  ft_printer_x.c  ft_putnbr_base.c    ft_strlen.c ft_numlen.c ft_printf.c ft_itoa.c   ft_flagdet.c
OBJS	= ${SRCS:.c=.o}
SRCSB	= ft_atoi.c  ft_hexalen.c    ft_printer_c_bonus.c  ft_printer_d_bonus.c  ft_printer_p_bonus.c  ft_printer_s_bonus.c  ft_printer_u_bonus.c  ft_printer_x_bonus.c  ft_putnbr_base.c    ft_strlen.c ft_numlen.c ft_printf_bonus.c ft_itoa.c   ft_flagdet.c
OBJB	= ${SRCSB:.c=.o}
NAME	= libftprintf.a
NAMEB	= libftprintf.a
BONUS	= .
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rc
.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all:		${NAME}

bonus:		${BONUS}

${BONUS}:	 ${OBJB}
				${AR} ${NAMEB} ${OBJB}
				
${NAME}:	${OBJS}
				${AR} ${NAME} ${OBJS}
				
clean:
			${RM} ${OBJS} ${OBJB}
fclean:		clean
				${RM} ${NAME} ${NAMEB}
re:			fclean all
.PHONY:		all	clean	fclean	re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seukim </var/mail/seukim>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/05 21:30:30 by seukim            #+#    #+#              #
#    Updated: 2020/05/08 17:29:11 by seukim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	=	ft_printf.c \
			ft_specifier_bighex.c \
			ft_specifier_char.c \
			ft_specifier_hex.c \
			ft_specifier_number.c \
			ft_specifier_persentage.c \
			ft_specifier_pointer.c \
			ft_specifier_string.c \
			ft_specifier_unint.c \
			ft_flag_parse.c \
			ft_flag_parse_sub.c \
			ft_flag_utility.c \
			ft_flag_strjoin.c
CC		= gcc
OBJS	= $(SRCS:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= .

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME): ${OBJS}
	${LIBC} $(NAME) $(OBJS)

all : $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all clean fclean re .c.o

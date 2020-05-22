# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpizarro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/29 13:43:23 by jpizarro          #+#    #+#              #
#    Updated: 2020/02/11 13:18:29 by jpizarro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(shell find . -name "ft*.c" ! -name "ft_lst*.c")

SRC_B = $(shell find . -name "ft_lst*.c")

OBJ	= $(SRC:.c=.o)

OBJ_B	= $(SRC_B:.c=.o)

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
			ar rc  $(NAME) $(OBJ)
			ranlib $(NAME)

bonus:		$(OBJ) $(OBJ_B)
			ar rc $(NAME) $(OBJ) $(OBJ_B)
			ranlib $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJ) $(OBJ_B)

fclean:		clean
			$(RM) $(NAME)

re:			fclean bonus

.PHONY: bonus all clean fclean re

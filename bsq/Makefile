# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 14:02:11 by asemsey           #+#    #+#              #
#    Updated: 2023/11/03 14:57:26 by fnikzad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c get_map.c solve.c bsq_utils.c ft_split.c 
EXE = bsq
CFLAGS = -Wall -Wextra -Werror

all: $(SRCS)
	cc $(CFLAGS) $(SRCS) -o $(EXE)

fclean: clean

clean:
	rm -f $(EXE)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 14:02:11 by asemsey           #+#    #+#              #
#    Updated: 2024/02/28 11:46:07 by asemsey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c get_map.c solve.c bsq_utils.c ft_split.c errors.c
EXE = bsq
CFLAGS = -Wall -Wextra -Werror
GNL_PATH = ./gnl
GNL = $(GNL_PATH)/get_next_line.a

all: $(EXE)

$(EXE): $(GNL) $(SRCS) 
	cc $(CFLAGS) $(GNL) $(SRCS) -o $(EXE)

$(GNL): 
	make all -C $(GNL_PATH) 

clean:
	make fclean -C $(GNL_PATH) 
	rm -f $(EXE)

fclean: clean

re: fclean all

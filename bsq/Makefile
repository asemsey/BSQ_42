# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnikzad <fnikzad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 14:02:11 by asemsey           #+#    #+#              #
#    Updated: 2024/02/27 15:26:32 by fnikzad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c get_map.c solve.c bsq_utils.c ft_split.c errors.c
EXE = bsq
CFLAGS = -Wall -Wextra -Werror
GNL_PATH = ./gnl
GNL = $(GNL_PATH)/get_next_line.a

all: $(EXE)

fclean: clean

$(GNL): 
	make all -C $(GNL_PATH) 

$(EXE): $(GNL) $(SRCS) 
	cc $(CFLAGS) $(GNL) $(SRCS) -o $(EXE)

clean:
	make fclean -C $(GNL_PATH) 
	rm -f $(EXE)

re: fclean all

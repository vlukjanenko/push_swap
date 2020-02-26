# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majosue <majosue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 10:14:46 by majosue           #+#    #+#              #
#    Updated: 2020/02/26 11:59:37 by majosue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  push_swap
NAME2 = checker
HEADER =  push_swap.h
INCLUDES = -I libft/ 
LIBFT = libft/libft.a
COMPILERC = gcc
FLAGS = -g -Wall -Wextra -Werror
SOURCES  = push_swap.c ft_read2a.c ft_cleaners.c ft_read2c.c ft_do_sort.c\
ft_ra_rrb.c ft_sa_pb.c ft_qsort.c ft_3_sort.c ft_1st_pass.c ft_2nd_pass.c
SOURCES2 = checker.c ft_read2a.c ft_cleaners.c ft_read2c.c ft_do_sort.c\
ft_ra_rrb.c ft_sa_pb.c
OBJECTS = $(SOURCES:.c=.o)
OBJECTS2 = $(SOURCES2:.c=.o)

.PHONY: clean fclean re

all: $(NAME) $(NAME2)

$(NAME): $(OBJECTS) $(LIBFT)
	$(COMPILERC) -o $(NAME) $(OBJECTS) $(INCLUDES) -L libft/ -lft

$(NAME2): $(OBJECTS2) $(LIBFT)
	$(COMPILERC) -o $(NAME2) $(OBJECTS2) $(INCLUDES) -L libft/ -lft
	
$(LIBFT): libft/*.c libft/*.h	
	@make -C libft/

%.o: %.c $(HEADER)
	$(COMPILERC) $(FLAGS) $(INCLUDES) -o $@ -c $< 

clean:
	@rm -f $(OBJECTS)
	@rm -f $(OBJECTS2)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@make -C libft/ fclean

re: fclean all
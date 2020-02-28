# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majosue <majosue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/13 10:14:46 by majosue           #+#    #+#              #
#    Updated: 2020/02/28 17:39:55 by majosue          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  push_swap
NAME2 = checker
HEADER =  push_swap.h
INCLUDES = -I libft/ 
LIBFT = libft/libft.a
COMPILERC = gcc
FLAGS = -Wall -Wextra -Werror
SOURCES  = push_swap.c  ft_3_sort.c ft_1st_pass.c ft_2nd_pass.c 
SOURCES2 = checker.c  ft_read2c.c ft_do_sort.c ft_show_my_precious.c ft_draw_line.c ft_draw.c
SOURCES_COMMON = ft_read2a.c ft_cleaners.c ft_ra_rrb.c ft_sa_pb.c ft_qsort.c ft_fill_index.c ft_fill_color.c
OBJECTS = $(SOURCES:.c=.o)
OBJECTS2 = $(SOURCES2:.c=.o)
OBJECTS_COMMON = $(SOURCES_COMMON:.c=.o)
MINILIBX = minilibx_macos/libmlx.a

.PHONY: clean fclean re

all: $(NAME) $(NAME2) $(NAME3)

$(NAME): $(OBJECTS) $(OBJECTS_COMMON) $(LIBFT)
	$(COMPILERC) -o $(NAME) $(OBJECTS) $(OBJECTS_COMMON) $(INCLUDES) -L libft/ -lft

$(NAME2): $(OBJECTS2) $(OBJECTS_COMMON) $(LIBFT) $(MINILIBX)
	$(COMPILERC) -o $(NAME2) $(OBJECTS2) $(OBJECTS_COMMON) $(INCLUDES) -I minilibx_macos/ -L libft/ -lft -L minilibx_macos/ -lmlx -framework OpenGL -framework Appkit
	
$(LIBFT): libft/*.c libft/*.h	
	@make -C libft/

$(MINILIBX): minilibx_macos/*.c minilibx_macos/*.h
	@make -C minilibx_macos/

%.o: %.c $(HEADER)
	$(COMPILERC) $(FLAGS) $(INCLUDES) -o $@ -c $< 

clean:
	@rm -f $(OBJECTS)
	@rm -f $(OBJECTS2)
	@rm -f $(OBJECTS_COMMON)
	@make -C minilibx_macos/ clean
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@make -C minilibx_macos/ clean
	@make -C libft/ fclean

re: fclean all
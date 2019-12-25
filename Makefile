# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belhatho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/30 20:21:59 by belhatho          #+#    #+#              #
#    Updated: 2019/12/21 00:08:38 by belhatho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = ft_keys1.c ft_keys.c ft_reader.c ft_clean.c ft_draw.c ft_initial.c 
SRCS += get_file_info.c main.c ft_paint.c put_colors.c point_colors.c
OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror
LIBRARIES = -lmlx -framework OpenGL -framework AppKit
LIBFT = ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIBRARIES) -L $(LIBFT)

%.o: %.c fdf.h libft/libft.h
	@gcc $(FLAGS) -c $< -o $@

clean:
		@make clean -C libft
		@rm -f $(OBJS)

fclean: clean
	        @make fclean -C libft
			        @rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 10:16:00 by dabae             #+#    #+#              #
#    Updated: 2024/03/15 10:19:31 by dabae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
#BONUS = fdf_bonus

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
GET_NEXT_LINE_DIR = get_next_line
GET_NEXT_LINE = $(wildcard $(GET_NEXT_LINE_DIR)/*.c)
SRC_MAN = main.c
OBJ_MAN = $(SRC_MAN:.c=.o) $(GET_NEXT_LINE:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_MAN)
	$(CC) $(OBJ_MAN) -L./libft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

#$(BONUS) : $(LIBFT) $(OBJ_COMMON) $(OBJ_BONUS)
#	$(CC) $(CFLAGS) -o $@ $^ -L./libft -lft

%.o: %.c
	$(CC) -Imlx_linux -O3 -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft

#bonus: $(BONUS)

clean:
	$(MAKE) clean -C ./libft
	@$(RM) -f $(OBJ_MAN)

fclean: clean
	$(MAKE) fclean -C ./libft 
	@$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
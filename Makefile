# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 10:16:00 by dabae             #+#    #+#              #
#    Updated: 2024/03/27 09:30:30 by dabae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
#BONUS = fdf_bonus

CC = gcc -O0 -g
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
GET_NEXT_LINE_DIR = get_next_line
GET_NEXT_LINE = $(wildcard $(GET_NEXT_LINE_DIR)/*.c)
SRC_MAN = main.c utils/drawing.c utils/parsing.c utils/utils.c utils/rotating.c \
		 utils/control_utils.c utils/setting_controls.c
OBJ_MAN = $(SRC_MAN:.c=.o) $(GET_NEXT_LINE:.c=.o)
MLX = mlx_linux
MLXLIB = $(MLX)/libmlx_Linux.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLXLIB) $(OBJ_MAN)
	$(CC) $(CFLAGS) $(OBJ_MAN) -L./libft -lft -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

#$(BONUS) : $(LIBFT) $(OBJ_COMMON) $(OBJ_BONUS)
#	$(CC) $(CFLAGS) -o $@ $^ -L./libft -lft

%.o: %.c
	$(CC) $(CFLAGS) -Imlx_linux -O0 -c $< -o $@

$(LIBFT):
	$(MAKE) -C ./libft

$(MLXLIB):
	$(MAKE) -C $(MLX)
		
#bonus: $(BONUS)

clean:
	$(MAKE) clean -C ./libft
	@$(RM) -f $(OBJ_MAN)

fclean: clean
	$(MAKE) fclean -C ./libft 
	@$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
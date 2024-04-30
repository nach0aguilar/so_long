# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 19:36:44 by igaguila          #+#    #+#              #
#    Updated: 2024/04/30 12:51:59 by igaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
USER		= tch0u
#USER		= igaguila
CC			= gcc
CFLAGS 		= -Wextra -Wall -Werror -g
MLX42 		= ./MLX42
SRC_DIR 	= src/
OBJ_DIR 	= obj/
SRC_FILES 	= main
SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF 		= .cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX42)
# @$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(MLX42) -lmlx42 -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJF):
	@mkdir -p $(OBJ_DIR)
	
clean:
	@rm -frf $(OBJ_DIR)
	@make clean -C $(MLX42)
	@make all clean -C
	
fclean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@make fclean -C $(MLX42)

re: fclean all

.PHONY: all clean fclean re norm
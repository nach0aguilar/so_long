# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 19:36:44 by igaguila          #+#    #+#              #
#    Updated: 2024/05/01 11:52:17 by igaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

USER		= tch0u
# USER		= igaguila

CC			= gcc
CFLAGS 		= -Wextra -Wall -Werror -g

MLX42 		= ./MLX42
SRC_DIR 	= src/
OBJ_DIR 	= obj/

SRC_FILES 	= main map errors
SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF 		= .cache_exists

LIBFT_DIR = includes/libft
PRINTF_DIR = includes/ft_printf
GNL_DIR = includes/get_next_line

LIBFT = ${LIBFT_DIR}/libft.a
PRINTF = ${PRINTF_DIR}/ft_printf.a
GNL = ${GNL_DIR}/get_next_line.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(MLX42)
	@make -C includes/get_next_line
# @$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -L$(PRINTF) -L$(GNL) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -L$(PRINTF) -L$(GNL) -lft -L$(MLX42) -lmlx42 -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(OBJF):
	@mkdir -p $(OBJ_DIR)
	
clean:
	@make -C ${LIBFT_DIR} clean
	@make -C ${PRINTF_DIR} clean
	@make -C ${GNL_DIR} clean
	@rm -frf $(OBJ_DIR)
	@make clean -C $(MLX42)
	@make all clean -C
	
fclean:
	@make -C ${LIBFT_DIR} fclean
	@make -C ${PRINTF_DIR} fclean
	@make -C ${GNL_DIR} fclean
	@rm -rf $(OBJ_DIR)
	@rm -rf $(NAME)
	@make fclean -C $(MLX42)

re: fclean all

.PHONY: all clean fclean re norm
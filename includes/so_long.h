/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:38:55 by igaguila          #+#    #+#             */
/*   Updated: 2024/05/16 12:27:48 by igaguila         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 5120
# define HEIGHT 2880

typedef struct s_game
{
    mlx_t       *mlx;
	char		**map;
	char		**map_dup;
	int			cols;
	int			rows;
	int			y_pos;
	int			x_pos;
	int			y_mov;
	int			x_mov;
	char		player;
	char		moon;
	char		btc;
	int			player_n;
	int			moon_n;
	int			btc_n;
	int			mov_n;
	int			btc_account;
	int			moon_account;
	int			btc_counter;
	int			mov_counter;
	mlx_image_t	*player_img;
	mlx_image_t	*btc_img;
	mlx_image_t	*moon_img;
	mlx_image_t	*floor_img;
	mlx_image_t	*wall_img;
}				t_game;

// MAP
t_game			*pull_map(char *map);
void			count_objects(t_game *game, char *line);
void			count_and_check(t_game *game);
char			**duplicate_map(t_game *game, char *map);
int				get_rows(char *map);

// CHECK
void 			check_extension(char *map, t_game *game);
void			check_objects(t_game *game);
void 			check_walls(t_game *game);
void 			check_rectangle(t_game *game);

// FREE
void			free_str(char **str);
void			win_game(t_game *game);
void			close_game(t_game *game);

// ERRORS
void			error_free(char *error, t_game *game);

// STRUCT
void			create_struct(t_game *game);

// COUNT
int 			count_rows(char **map);
int 			count_cols(char **map);
void			count_cols_and_rows(t_game *game, char **map);

// GUI
void			load_gui(t_game *game);
void			delete_gui(t_game *game);
void			print_gui(t_game *game, char **map);
void			draw_gui(t_game *game);

// IMAGES
void    		img_player_to_map(t_game *game, char **map, int col, int row);
void    		img_btc_to_map(t_game *game, char **map, int col, int row);
void    		img_moon_to_map(t_game *game, char **map, int col, int row);
void    		img_floor_to_map(t_game *game, char **map, int col, int row);
void    		img_wall_to_map(t_game *game, char **map, int col, int row);

// POSITION
void			get_player_position(t_game *game);

// FLOODFILL
void			flood_fill(t_game *game, int row, int col);

// GAME
int32_t			init_game(t_game *game);

// MOVEMENTS
void			movements(mlx_key_data_t paramkey, t_game *game);

// ACTION
void			action(t_game *game, int x, int y);

#endif
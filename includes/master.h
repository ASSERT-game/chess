/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:41:24 by home              #+#    #+#             */
/*   Updated: 2020/06/17 03:25:04 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

# include <SDL2/SDL.h>
# include <SDL_image.h>

# include "window_config.h"
# include "structs.h"
# include "piece_id.h"

void		SDLU_start(t_display *dest);
void		SDLU_close(t_display *display);

SDL_Rect	*carve_chess_texture();

void		set_new_game(int *game_map);

void		draw_game_state(t_game_state *game_state, t_display *display);
void		draw_hover_tile(t_game_state *game_state, t_display *display);
void		draw_select_tile(t_game_state *game_state, t_display *display);

void		update_game_input(t_game_state *game_state);

void		clear_screen(unsigned char *pixel_array);
void		color_in(unsigned char *pixel_array, int color, int x, int y);

void		process_user_input(t_game_state *game_state);

bool		black_piece(int piece_ID);
bool		white_piece(int piece_ID);
int			screen_to_board(int x, int y);

#endif

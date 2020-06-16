/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:40:46 by home              #+#    #+#             */
/*   Updated: 2020/06/16 03:22:33 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	game_state_initialize(t_game_state *game_state, t_display *display)
{
	game_state->active = true;
	game_state->texture = IMG_LoadTexture(display->renderer, "resources/chess_texture.png");
	bzero(game_state->map, sizeof(game_state->map));

	set_new_game(game_state->map);

	game_state->scr_rect = carve_chess_texture();
}

int	main(void)
{
	t_display		display;
	t_game_state	game_state;

	SDLU_start(&display);
	game_state_initialize(&game_state, &display);
	while (game_state.active == true)
	{
		process_user_input(&game_state);
		// update_game_input(&game_state);

		draw_game_state(&game_state, &display);
		draw_hover_tile(&game_state, &display);
		draw_select_tile(&game_state, &display);

		SDL_RenderPresent(display.renderer);
		SDL_RenderClear(display.renderer);
	}
	SDLU_close(&display);
	return (0);
}

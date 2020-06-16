/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:56:31 by home              #+#    #+#             */
/*   Updated: 2020/06/16 02:39:35 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	process_user_input(t_game_state *game_state)
{
	SDL_Event		e;
	const Uint8		*keystate;


	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
			game_state->active = false;
		else if (e.type == SDL_MOUSEMOTION)
			SDL_GetMouseState(&(game_state->mouse_x), &(game_state->mouse_y));
		// else if (e.type == SDL_MOUSEBUTTONDOWN)
		// {
		// 	if (e.button.button == SDL_BUTTON_LEFT)
		// 		game_state->l_mouse_down = true;
		// 	if (e.button.button == SDL_BUTTON_RIGHT)
		// 		game_state->r_mouse_down = true;
		// }
		// else if (e.type == SDL_MOUSEBUTTONUP)
		// {
		// 	if (e.button.button == SDL_BUTTON_LEFT)
		// 		game_state->l_mouse_down = false;
		// 	if (e.button.button == SDL_BUTTON_RIGHT)
		// 		game_state->r_mouse_down = false;
		// }
	}
	keystate = SDL_GetKeyboardState(NULL);

	// if (game_state->l_mouse_down == true)
	// 	game_state->pixmap[convert_to_pixmap(game_state->mouse_x, game_state->mouse_y, game_state->size)] = 0xAA00CC;
	// if (game_state->r_mouse_down == true)
	// 	game_state->pixmap[convert_to_pixmap(game_state->mouse_x, game_state->mouse_y, game_state->size)] = 0x000000;

	// if (keystate[SDL_SCANCODE_COMMAND] && keystate[SDL_SCANCODE_BACKSPACE])
	// 	clear_image(game_state->pixmap, game_state->size);
}

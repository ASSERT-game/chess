/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:40:46 by home              #+#    #+#             */
/*   Updated: 2020/06/16 00:06:57 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	game_state_initialize(t_game_state *game_state)
{
	game_state->active = true;
}

int	main(void)
{
	t_display		display;
	t_game_state	game_state;

	SDLU_start(&display);
	SDL_Texture *bmp;

	SDL_Rect	rect;

	rect.x = 0;
	rect.y = 0;
	rect.h = 32;
	rect.w = 126;

	bmp = IMG_LoadTexture(display.renderer, "resources/chess_texture.png");

	if (bmp == NULL)
		printf("Error in making the image to a texture!\n");
	else
		printf("image was made!\n");

	// Clear the entire screen to our selected color.

	game_state_initialize(&game_state);

	while (game_state.active == true)
	{
		process_user_input(&game_state);
		// update_game_input(&game_state);

		SDL_RenderClear(display.renderer);
		SDL_RenderCopy(display.renderer, bmp, NULL, &rect);
		SDL_RenderPresent(display.renderer);
		// SDL_UpdateWindowSurface(display.window);
		// clear_screen(display.pixels);
	}
	SDLU_close(&display);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:40:46 by home              #+#    #+#             */
/*   Updated: 2020/06/15 22:52:18 by home             ###   ########.fr       */
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
	game_state_initialize(&game_state);
	while (game_state.active == true)
	{
		process_user_input(&game_state);
		// update_game_input(&game_state);

		SDL_UpdateWindowSurface(display.window);
		clear_screen(display.pixels);
	}
	SDLU_close(&display);
	return (0);
}

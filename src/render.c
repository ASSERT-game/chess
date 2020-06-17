/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 01:17:29 by home              #+#    #+#             */
/*   Updated: 2020/06/16 19:38:29 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	get_loc(int i, int *x, int *y)
{
	*x = i % 8;
	*y = i / 8;

	*y *= 64;
	*x *= 64;
}

void	draw_game_state(t_game_state *game_state, t_display *display)
{
	int			i;
	int			piece_type;
	SDL_Rect	rect;
	SDL_Rect	src_rect;

	i = 0;
	rect.x = 0;
	rect.y = 0;
	rect.h = 64;
	rect.w = 64;
	while (i < 64)
	{
		if (game_state->map[i] != NONE)
		{
			get_loc(i, &(rect.x), &(rect.y));
			piece_type = game_state->map[i];
			src_rect = game_state->scr_rect[piece_type];
			SDL_RenderCopy(display->renderer, game_state->texture, &src_rect, &rect);
			// SDL_RenderCopy(display.renderer, game_state.from, &(src), &rect);
		}
		i++;
	}
}

void	draw_hover_tile(t_game_state *game_state, t_display *display)
{
	SDL_Rect	rect;

	rect.x = (game_state->mouse_x / 64) * 64;
	rect.y = (game_state->mouse_y / 64) * 64;
	rect.h = 64;
	rect.w = 64;
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->scr_rect[HOVER]), &rect);
}

void	draw_select_tile(t_game_state *game_state, t_display *display)
{
	SDL_Rect	rect;

	if (game_state->selected_piece == NULL)
		return ;
	rect.x = (game_state->select_x / 64) * 64;
	rect.y = (game_state->select_y / 64) * 64;
	rect.h = 64;
	rect.w = 64;
	SDL_RenderCopy(display->renderer, game_state->texture, &(game_state->scr_rect[SELECT]), &rect);
}

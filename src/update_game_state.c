/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 03:50:13 by home              #+#    #+#             */
/*   Updated: 2020/06/16 19:49:53 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

bool	move_valid(t_game_state *game_state)
{
	(void)game_state;
	return (true);
}

void	update_game_input(t_game_state *game_state)
{
	if (game_state->selected_piece != NULL && game_state->move_to_x != -1)
	{
		if (move_valid(game_state) == true)
		{
			game_state->map[(game_state->move_to_y / 64) * 8 + game_state->move_to_x / 64] = *(game_state->selected_piece);
			*game_state->selected_piece = 0;
			game_state->turn++;
		}
		game_state->selected_piece = NULL;
		game_state->select_x = -1;
		game_state->move_to_x = -1;
	}
	if (game_state->selected_piece == NULL && game_state->select_x != -1)
	{
		if (game_state->map[(game_state->select_y / 64) * 8 + game_state->select_x / 64] != 0)
			game_state->selected_piece = &(game_state->map[(game_state->select_y / 64) * 8 + game_state->select_x / 64]);
	}
}

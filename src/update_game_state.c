/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_game_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 03:50:13 by home              #+#    #+#             */
/*   Updated: 2020/06/17 03:36:41 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	reset_to_no_selection(t_game_state *game_state)
{
	game_state->selected_piece = NULL;
	game_state->select_x = -1;
	game_state->select_y = -1;

	game_state->move_to_x = -1;
	game_state->move_to_y = -1;
}

bool	valid_selection(t_game_state *game_state)
{
	bool	result;
	int		piece;

	result = false;
	if (game_state->select_x < 0 || game_state->select_y < 0)
		result = false;
	else if (game_state->selected_piece == NULL)
	{
		piece = game_state->map[screen_to_board(game_state->select_x, game_state->select_y)];
		if (game_state->turn % 2 == WHITE_TURN && white_piece(piece) == true)
			result = true;
		if (game_state->turn % 2 == BLACK_TURN && black_piece(piece) == true)
			result = true;
	}
	return (result);
}

bool	move_valid(t_game_state *game_state)
{
	bool	result;
	int		move_to_index;

	result = true;
	if (game_state->move_to_x < 0 || game_state->move_to_y < 0)
		result = false;

	move_to_index = screen_to_board(game_state->move_to_x, game_state->move_to_y);
	if (game_state->turn % 2 == WHITE_TURN && white_piece(game_state->map[move_to_index]) == true)
		result = false;
	if (game_state->turn % 2 == BLACK_TURN && black_piece(game_state->map[move_to_index]) == true)
		result = false;

	return (result);
}

void	update_game_input(t_game_state *game_state)
{
	if (game_state->selected_piece != NULL && game_state->move_to_x != -1)
	{
		if (move_valid(game_state) == true)
		{
			game_state->map[screen_to_board(game_state->move_to_x, game_state->move_to_y)] = *(game_state->selected_piece);
			*game_state->selected_piece = 0;
			game_state->turn++;
		}
		reset_to_no_selection(game_state);
	}

	if (game_state->selected_piece == NULL)
	{
		if (valid_selection(game_state) == true)
			game_state->selected_piece = &(game_state->map[screen_to_board(game_state->select_x, game_state->select_y)]);
		else
			reset_to_no_selection(game_state);
	}
}

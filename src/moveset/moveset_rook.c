/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_rook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 04:59:15 by home              #+#    #+#             */
/*   Updated: 2020/06/17 04:59:45 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	toggle_rook_moveset(t_game_state *game_state)
{
	int		i;
	int		try;

	i = screen_to_board(game_state->select_x, game_state->select_y);
	try = i - 8;
	while (try > 0)
	{
		if (game_state->map[try] == NONE)
			game_state->possible_tiles[try] = 1;
		else
		{
			if (game_state->turn % 2 == WHITE_TURN && white_piece(game_state->map[try]) != true)
				game_state->possible_tiles[try] = 1;
			if (game_state->turn % 2 == BLACK_TURN && black_piece(game_state->map[try]) != true)
				game_state->possible_tiles[try] = 1;
			break ;
		}
		try -= 8; //Going one full row UP
	}
	try = i + 8;
	while (try < 64)
	{
		if (game_state->map[try] == NONE)
			game_state->possible_tiles[try] = 1;
		else
		{
			if (game_state->turn % 2 == WHITE_TURN && white_piece(game_state->map[try]) != true)
				game_state->possible_tiles[try] = 1;
			if (game_state->turn % 2 == BLACK_TURN && black_piece(game_state->map[try]) != true)
				game_state->possible_tiles[try] = 1;
			break ;
		}
		try += 8; //Going one full row DOWN
	}
	try = i - 1;
	while (try % 8 != 7)
	{
		if (game_state->map[try] == NONE)
			game_state->possible_tiles[try] = 1;
		else
		{
			if (game_state->turn % 2 == WHITE_TURN && white_piece(game_state->map[try]) != true)
				game_state->possible_tiles[try] = 1;
			if (game_state->turn % 2 == BLACK_TURN && black_piece(game_state->map[try]) != true)
				game_state->possible_tiles[try] = 1;
			break ;
		}
		try -= 1; //Going one full row LEFT
	}
	try = i + 1;
	while (try % 8 != 0)
	{
		if (game_state->map[try] == NONE)
			game_state->possible_tiles[try] = 1;
		else
		{
			if (game_state->turn % 2 == WHITE_TURN && white_piece(game_state->map[try]) != true)
				game_state->possible_tiles[try] = 1;
			if (game_state->turn % 2 == BLACK_TURN && black_piece(game_state->map[try]) != true)
				game_state->possible_tiles[try] = 1;
			break ;
		}
		try += 1; //Going one full row RIGHT
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 21:49:34 by home              #+#    #+#             */
/*   Updated: 2020/06/17 03:25:04 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

bool	white_piece(int piece_ID)
{
	bool	result;

	result = false;
	if (W_PAWN <= piece_ID && piece_ID <= W_KING)
		result = true;
	return (result);
}

bool	black_piece(int piece_ID)
{
	bool	result;

	result = false;
	if (B_PAWN <= piece_ID && piece_ID <= B_KING)
		result = true;
	return (result);
}

int		screen_to_board(int x, int y)
{
	int	row;
	int	col;

	col = x / 64;
	row = y / 64;

	return (row * 8 + col);
}

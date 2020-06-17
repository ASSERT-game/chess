/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveset_queen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 04:59:15 by home              #+#    #+#             */
/*   Updated: 2020/06/17 06:10:28 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	toggle_queen_moveset(t_game_state *game_state)
{
	toggle_rook_moveset(game_state);
	toggle_bishop_moveset(game_state);
}

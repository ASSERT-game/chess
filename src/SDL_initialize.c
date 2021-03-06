/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:03:40 by home              #+#    #+#             */
/*   Updated: 2020/06/18 22:09:34 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	SDLU_start(t_display *dest)
{
	SDL_Window	*window;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(
				WIN_TITLE,
				WIN_POS_X, WIN_POS_Y,
				WIN_WIDTH, WIN_HEIGHT,
				SDL_WINDOW_SHOWN
	);
	dest->renderer = SDL_CreateRenderer(window, -1, 0);
	dest->window = window;
}

void	SDLU_close(t_display *display)
{
	SDL_DestroyWindow(display->window);
	SDL_Quit();
}

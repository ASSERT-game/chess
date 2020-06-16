/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_initialize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:03:40 by home              #+#    #+#             */
/*   Updated: 2020/06/16 00:21:29 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "master.h"

void	SDLU_start(t_display *dest)
{
	SDL_Window	*window;

	dest->width = WIN_WIDTH;
	dest->height = WIN_HEIGHT;
	dest->size = dest->width * dest->height;

	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(
				WIN_TITLE,
				WIN_POS_X, WIN_POS_Y,
				dest->width, dest->height,
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

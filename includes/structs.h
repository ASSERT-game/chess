/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 22:05:38 by home              #+#    #+#             */
/*   Updated: 2020/06/16 02:07:39 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <SDL2/SDL.h>
# include <stdbool.h>

typedef struct	s_display
{
	int				width;
	int				height;
	int				size;

	SDL_Window		*window;
	SDL_Renderer	*renderer;
}				t_display;

typedef struct	s_game_state
{
	bool		active;

	SDL_Texture	*texture;
	SDL_Rect	*scr_rect;

	int			map[64];

//Maybe make this itself a structure.
	int			mouse_x;
	int			mouse_y;
}				t_game_state;


#endif

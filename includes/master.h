/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 22:41:24 by home              #+#    #+#             */
/*   Updated: 2020/06/16 00:01:57 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MASTER_H
# define MASTER_H

# include <SDL2/SDL.h>
# include <SDL_image.h>

# include "window_config.h"
# include "structs.h"


void	SDLU_start(t_display *dest);
void	SDLU_close(t_display *display);

void	clear_screen(unsigned char *pixel_array);
void	color_in(unsigned char *pixel_array, int color, int x, int y);

void	process_user_input(t_game_state *game_state);

#endif

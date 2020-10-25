# chess

A chess board game made in C using the SDL Library. Used as a project to better know SDL
and get a idea of the scope of making a game. I created all assets for this game using a 3rd Party
pixel editor [aseprite](https://www.aseprite.org/). Texture map can be found [here](https://github.com/ASSERT-game/chess/blob/master/resources/chess_texture.png).

Players take turns, on hover their piece is highlighted in blue, when selected it turns yellow,
players cannot select the opponents piece. Valid squares are shown in green, pieces can only
move onto green squares.

<br>
<img align="top" height="500" src="https://github.com/ASSERT-game/chess/blob/master/resources/gameplay.gif" />
<br>

This however is not a complete chess game, a special move of the pawn called en passant is not implemented, no castling, there is no piece promotion, no check or checkmate either.
You can see the TODO for features not yet implemented. Since this was used mostly as a learning tool I have not yet gone back. However, some of the architecture decisions I made around SDL in this program would continuously be used in future projects. For that reason it was a success to me, see [this](https://github.com/MrColour/SDL_2D_init)

In thinking about making an AI to play chess I made [tic_tac_toe](https://github.com/ASSERT-game/tic_tac_toe). Although
in theory a perfect chess AI could be made using the same technique as used in the [tic_tac_toe](https://github.com/ASSERT-game/tic_tac_toe) game, due to time and space this is not possible.
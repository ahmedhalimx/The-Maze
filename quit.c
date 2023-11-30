#include "aux.h"
#include <SDL2/SDL_render.h>

void quit(game_t *game)
{
	SDL_DestroyWindow(game->gwindow);
	SDL_DestroyRenderer(game->grenderer);
	SDL_DestroyTexture(game->gtexture);
	game->grenderer = NULL;
	game->gwindow = NULL;
	game->gsurface = NULL;
	SDL_Quit();
}

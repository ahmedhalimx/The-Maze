#include "aux.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>

bool load_texture(game_t *game, char *path)
{
	SDL_Surface* img_surface = IMG_Load(path);
	game->gtexture = SDL_CreateTextureFromSurface(game->grenderer, img_surface);
	return (true);
}

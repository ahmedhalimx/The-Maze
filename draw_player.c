#include "aux.h"
#include <SDL2/SDL_render.h>

void draw_player(player_t *player, SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(
		renderer,
		0xFF,
		0x00,
		0x00,
		0xFF
	);
	SDL_RenderFillRect(renderer, &(player->box));
	SDL_RenderDrawRect(renderer, &(player->box));
}

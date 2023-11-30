#include "aux.h"

#define LIMIT 8
#define TILE_SIZE 64

void draw_2d_map(game_t *game, size_t map[])
{
	SDL_Rect tile = { .x = 0, .y = 0, .h = 64, .w = 64 };
	size_t x = 0, y = 0;

	for (y = 0; y < LIMIT; ++y)
	{
		for (x = 0; x < LIMIT; ++x)
		{
			size_t xoffset = x * TILE_SIZE, yoffset = y * TILE_SIZE;
			if (map[(y * LIMIT) + x] == 1)
			{
				SDL_SetRenderDrawColor(
					game->grenderer,
					0xFF,
					0xFF,
					0xFF,
					0xFF
				);
			}
			else
			{
				SDL_SetRenderDrawColor(
					game->grenderer,
					0x00,
					0x00,
					0x00,
					0xFF
				);
			}
			tile.x = xoffset;
			tile.y = yoffset;
			SDL_RenderFillRect(game->grenderer, &tile);
			SDL_RenderDrawRect(game->grenderer, &tile);
		}
	}
}

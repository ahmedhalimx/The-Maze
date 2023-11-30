#include "aux.h"
#include <SDL2/SDL_timer.h>

size_t tileX = 0, tileY = 0;
const size_t TILE_SIZE = 64;
size_t map[] =
	{
		1, 1, 1, 1, 1, 1, 1, 1,
		1, 0, 0, 1, 0, 1, 0, 1,
		1, 0, 0, 1, 0, 1, 0, 1,
		1, 1, 1, 0, 0, 1, 0, 1,
		1, 0, 0, 0, 0, 0, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 1,
		1, 0, 0, 0, 0, 1, 0, 1,
		1, 1, 1, 1, 1, 1, 1, 1,
	};

int main(void)
{
	game_t game;
	SDL_Event e;
	bool game_running = true;

	game.map = map;
	game.last_time = SDL_GetTicks();
	if (!init(&game))
	{
		printf("Init Failed\n");
		return (EXIT_FAILURE);
	}
	while (game_running)
	{
		game.dt = (SDL_GetTicks() - game.last_time) / 1000.0F;
		game.last_time = SDL_GetTicks();
		while(SDL_PollEvent(&e))
		{
			if (analyze_event(&game.player, &e, game.dt) == -1)
				game_running = false;
			printf("player angle: %f\n", game.player.angle);
		}
		display(&game);
	}
	quit(&game);
	return (EXIT_SUCCESS);
}

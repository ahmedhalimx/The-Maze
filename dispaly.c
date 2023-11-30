#include "aux.h"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>

#define WIDTH 20
#define HEIGHT 20

void display(game_t *game)
{
	int twait = FRAME_TARGET_TIME - (SDL_GetTicks() - (int)game->last_time);
	int lineLength = 30;

	game->dt = (SDL_GetTicks() - game->last_time) / 1000.0F;
	game->last_time = SDL_GetTicks();
	if (twait > 0 && twait <= FRAME_TARGET_TIME) 
		SDL_Delay(twait);
	game->player.box.h = game->player.box.w = 20;
	game->player.box.x = game->player.pos.x - 10;
	game->player.box.y = game->player.pos.y - 10;
	
	int x2 = (int)(game->player.pos.x + lineLength * cos(game->player.angle));
	int y2 = (int)(game->player.pos.y + lineLength * sin(game->player.angle));
	
	draw_2d_map(game, game->map);
	draw_player(&game->player, game->grenderer);
	SDL_SetRenderDrawColor(game->grenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawLine(game->grenderer, game->player.pos.x, game->player.pos.y, x2, y2);
	SDL_RenderPresent(game->grenderer);
	SDL_SetRenderDrawColor(game->grenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(game->grenderer);
}

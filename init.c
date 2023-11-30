#include "aux.h"

#define WIDTH 800
#define HEIGHT 600

bool init(game_t *game)
{
	int img_flags = IMG_INIT_PNG | IMG_INIT_JPG;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("Initializing SDL failed, ERRCODE(%s)", SDL_GetError());
		return (false);
	}
	game->gwindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED,
				  SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
	if (!game->gwindow)
	{
		printf("Initializing window falied, ERRCODE(%s)", SDL_GetError());
		return (false);
	}
	game->gsurface = SDL_GetWindowSurface(game->gwindow);
	game->grenderer = SDL_CreateRenderer(game->gwindow, -1, SDL_RENDERER_ACCELERATED);
	if (!game->grenderer)
	{
		printf("Initializing renderer falied, ERRCODE(%s)", SDL_GetError());
		return (false);
	}
	if (!(IMG_Init(img_flags) & img_flags))
	{
		printf("Failed Initializing SDL_Image, ERRCODE(%s)", SDL_GetError());
		return (false);
	}
	game->wall.h = game->wall.w = 64;
	game->wall.x = game->wall.y = 0;
	game->player.pos.x = game->player.pos.y = 3;
	game->player.angle = 0.0;
	game->player.speed = 200.0;
	game->player.angular_speed = 2 * PI;
	game->player.box.x = 0;
	game->player.box.y = 0;
	game->player.box.w = 20;
	game->player.box.h = 20;
	game->dt = game->last_time = 0;
	return (true);
}

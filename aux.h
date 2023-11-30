#ifndef AUX_H
#define AUX_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592
#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

typedef struct vector2f_s {
	float x;
	float y;
}vector2f_t;

typedef struct player_s {
	vector2f_t pos;
	SDL_Rect box;
	float angle;
	float speed;
	float angular_speed;
} player_t;

typedef struct game_s {
	SDL_Window *gwindow;
	SDL_Renderer *grenderer;
	SDL_Surface *gsurface;
	SDL_Texture *gtexture;
	SDL_Rect wall;
	player_t player;
	size_t *map;
	float dt;
	float last_time;
} game_t;

bool init(game_t* game);
int analyze_event(player_t *p, SDL_Event *e, float dt);
void quit(game_t *game);
void display(game_t *game);
bool load_texture(game_t *game, char *path);
void draw_2d_map(game_t *game, size_t map[]);
void draw_player(player_t *player, SDL_Renderer *renderer);

#endif

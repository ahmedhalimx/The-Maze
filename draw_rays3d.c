#include "aux.h"

#define MAP_TILE_SIZE 64

void draw_ray3d(game_t *game)
{
	const int MAX_RAYS = 1;
	int dof;
	float ray_angle, ray_idx, ry, rx;

	ray_angle = game->player.angle;
	for (ray_idx = 0; ray_idx < MAX_RAYS; ++ray_idx)
	{
		dof = 0;
		float v_atan = -1 / tan(ray_angle); 
		if (ray_angle > PI)
		{
			ry = (((int)game->player.pos.x / MAP_TILE_SIZE) * MAP_TILE_SIZE) - 0.0001;
			rx = (game->player.pos.x - ry) * v_atan + game->player.pos.x;
		}
	}
}

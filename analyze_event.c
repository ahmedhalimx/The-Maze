#include "aux.h"

int analyze_event(player_t *p, SDL_Event *e, float dt)
{
	if (e->type == SDL_QUIT)
	{
		return (-1);
	}
	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_UP]) {
		p->pos.x += p->speed * cos(p->angle) * dt;
		p->pos.y += p->speed * sin(p->angle) * dt;
	}

	if (state[SDL_SCANCODE_DOWN]) {
		// Move backward
		p->pos.x -= p->speed * cos(p->angle) * dt;
		p->pos.y -= p->speed * sin(p->angle) * dt;
	}

	// Handle p->pos rotation (right/left)
	if (state[SDL_SCANCODE_RIGHT]) {
		// Turn right
		p->angle += p->angular_speed * dt;
		if (p->angle > 2 * PI)
			p->angle -= 2 * PI;
	}

	if (state[SDL_SCANCODE_LEFT]) {
		p->angle -= p->angular_speed * dt;
		if (p->angle < 0)
			p->angle += 2 * PI;
	}
	return (0);
}

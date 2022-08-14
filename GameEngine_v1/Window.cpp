#include "Window.hpp"

Window::Window() {
	Init();

	window = SDL_CreateWindow("Game Engine", 
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		640, 480, 0);

	if (window == NULL) {
		SDL_Log("Could not create window: %s", SDL_GetError());
	}

	render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	surface = SDL_CreateRGBSurface(0, 640, 480, 64, 0, 0, 0, 0);
	bgTexstur = SDL_CreateTextureFromSurface(render, surface);

	while (true) {
		SDL_RenderClear(render);
		SDL_RenderCopy(render, bgTexstur, NULL, NULL);
		SDL_RenderPresent(render);
	}
};
Window::~Window() {
	SDL_DestroyTexture(bgTexstur);
	SDL_DestroyRenderer(render);
	SDL_DestroyWindow(window);
};

void Window::Init() {
	if (SDL_Init(SDL_INIT_TIMER |
		SDL_INIT_AUDIO |
		SDL_INIT_VIDEO |
		SDL_INIT_JOYSTICK |
		SDL_INIT_EVENTS) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	}
};
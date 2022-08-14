// Открытие окна на весь рабочий стол
// Масштобирование окна

#ifndef __WINDOW__
#define __WINDOW__

#include <SDL.h>

#include <iostream>

class Window {
public: 
	Window();
	~Window();

	void Init();

private:
	SDL_Window *window;
	SDL_Renderer *render;
	SDL_Surface *surface;
	SDL_Texture *bgTexstur;

};

#endif // __WINDOW__

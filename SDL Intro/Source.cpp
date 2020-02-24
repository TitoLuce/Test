#include <stdlib.h>
#include <iostream>
#include "SDL/include/SDL.h"
#pragma comment(lib,"SDL/x86/SDL2.lib")
#pragma comment(lib, "SDL/x86/SDL2main.lib")

int main(int argc, char* argv[])  //Cuantos argumentos hemos recibido en el exe? Array con la lista de argumentos   (Argument count/Argument variables)
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("Ur mom", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 900, 900, SDL_WINDOW_SHOWN);
	}

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
	int x = 0;
	int y = 0;
	while (1)
	{
		screenSurface = SDL_GetWindowSurface(window);
		SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0xF7, 0xFF));
		SDL_Rect rect = { x,y,100,100 };
		SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x3E));
		SDL_UpdateWindowSurface(window);
		x++;
		y++;
	}
	
	
    }
	
	return 0;
}
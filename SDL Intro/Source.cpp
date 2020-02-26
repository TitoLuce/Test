#include <stdio.h>
#include <iostream>
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#pragma comment(lib,"SDL/x86/SDL2.lib")
#pragma comment(lib, "SDL/x86/SDL2main.lib")
#pragma comment(lib,"SDL_Image/x86/SDL2_image.lib")

SDL_Rect rect = { 0,0,100,100 };
SDL_Rect Laser[10] = { rect.x,rect.y,50,25 };
SDL_Renderer 
int laserCount = 0;
SDL_Event event;
bool quit = false;

int main(int argc, char* argv[])  //Cuantos argumentos hemos recibido en el exe? Array con la lista de argumentos   (Argument count/Argument variables)
{
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* image = NULL;

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
		screenSurface = SDL_GetWindowSurface(window);
		SDL_Surface* surf =IMG_Load("NEPU.png");
		SDL_Texture* text=SDL_CreateTextureFromSurface()
		while (!quit)
		{
			while (SDL_PollEvent(&event) != 0)
			{
				if (event.type == SDL_QUIT)
				{
					quit = true;
				}
				else if (event.type == SDL_KEYDOWN)
				{
					switch(event.key.keysym.sym)
					{
					case SDLK_ESCAPE:
						quit = true;
						break;
					case SDLK_UP:
						rect.y--;
						break;
					case SDLK_DOWN:
						rect.y++;
						break;
					case SDLK_LEFT:
						rect.x--;
						break;
					case SDLK_RIGHT:
						rect.x++;
						break;
					case SDLK_SPACE:
						SDL_FillRect(screenSurface, &Laser[laserCount], SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0x00));
						break;
					}
				}
			}
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0xF7, 0xFF));
			//SDL_FillRect(screenSurface, &rect, SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x3E));
			SDL_UpdateWindowSurface(window);

		}
	
    }
	
	
	return 0;
}
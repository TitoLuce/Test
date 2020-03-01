#include <stdio.h>
#include <iostream>
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#pragma comment(lib,"SDL/x86/SDL2.lib")
#pragma comment(lib, "SDL/x86/SDL2main.lib")
#pragma comment(lib,"SDL_Image/x86/SDL2_image.lib")

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Rect rect = { 0,0,100,100 };
SDL_Rect Laser[10] = { rect.x,rect.y,50,25 };
int laserCount = 0;
SDL_Event event;
bool quit = false;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

int main(int argc, char* argv[])  //Cuantos argumentos hemos recibido en el exe? Array con la lista de argumentos   (Argument count/Argument variables)
{
	SDL_Surface* NEPU = SDL_LoadBMP("NEPU.bmp");

	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xBB, 0xFF, 0xFF));
	//NEPU = SDL_LoadBMP("NEPU");


	SDL_BlitSurface(NEPU, NULL, screenSurface, NULL);
	while (NEPU!=NULL)
	{

		 

		SDL_UpdateWindowSurface(window);
	}
	
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
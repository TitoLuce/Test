#include <stdio.h>
#include <iostream>
#include "SDL/include/SDL.h"
#include "SDL_image/include/SDL_image.h"
#pragma comment(lib,"SDL/x86/SDL2.lib")
#pragma comment(lib, "SDL/x86/SDL2main.lib")
#pragma comment(lib,"SDL_Image/x86/SDL2_image.lib")

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 550;

const Uint8* keys = SDL_GetKeyboardState(NULL);
SDL_Event event;

int x = 270;
int y = 190;
int lx = x;
int ly = y;

SDL_Rect rect = { x,y,100,100 };
SDL_Rect laser = { lx,ly,70,35 };

bool quit = false;
bool shot = false;

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

SDL_Surface* NEPU = NULL;
SDL_Surface* da1 = NULL;
SDL_Surface* boomer = NULL;

SDL_Renderer* renderer = NULL;
SDL_Texture* texture = NULL;

SDL_Texture* texture2 = NULL;

SDL_Texture* texture3 = NULL;


int main(int argc, char* argv[])  //Cuantos argumentos hemos recibido en el exe? Array con la lista de argumentos   (Argument count/Argument variables)
{
	
	

	window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	screenSurface = SDL_GetWindowSurface(window);

	NEPU = IMG_Load("NEPU.png");
	da1 = IMG_Load("da1.jpg");
	boomer = IMG_Load("boomer.png");

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	texture = SDL_CreateTextureFromSurface(renderer, NEPU);

	texture2 = SDL_CreateTextureFromSurface(renderer, da1);
	texture3 = SDL_CreateTextureFromSurface(renderer, boomer);

	//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xBB, 0xFF, 0xFF));

	while (!quit)
	{

		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (event.type==SDL_KEYDOWN)
			{
				
				if (keys[SDL_SCANCODE_ESCAPE])
				{
					quit = true;
				}
				if (keys[SDL_SCANCODE_UP])
				{
					rect.y--;
				}
				if (keys[SDL_SCANCODE_DOWN])
				{
					rect.y++;
				}
				if (keys[SDL_SCANCODE_LEFT])
				{
					rect.x--;
				}
				if (keys[SDL_SCANCODE_RIGHT])
				{
					rect.x++;
				}
				if (keys[SDL_SCANCODE_SPACE])
				{
					shot = true;
				}
				
			}
		}


		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderCopy(renderer, texture2, NULL, &rect);

		if (laser.x >= 800)
		{
			shot = false;
		}

		if (shot)
		{
			laser.x++;
			SDL_RenderCopy(renderer, texture3, NULL, &laser);
		}

		if (!shot)
		{
			laser.x = rect.x;
			laser.y = rect.y;
		}
		
		SDL_RenderPresent(renderer);


		//SDL_UpdateWindowSurface(window);
	}

	SDL_DestroyTexture(texture);
	SDL_DestroyTexture(texture2);
	SDL_DestroyTexture(texture3);
	SDL_FreeSurface(NEPU);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
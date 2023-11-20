#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif
#ifndef MAP
#define MAP
#include "map.h"
#endif
#ifndef WINDOWS
#define WINDOWS
#include <Windows.h>
#endif
#ifndef SDL2
#define SDL2
#include "SDL2/SDL.h"
#endif

#ifndef True
#define True 1
#endif
#ifndef False
#define False 0
#endif
#ifndef true
#define true 1
#endif
#ifndef false
#define false 0
#endif

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	int ret = SDL_Init(SDL_INIT_EVERYTHING);
	if (ret != 0) {
		return -1;
	}
	
	SDL_Window* pWin = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	if (pWin == NULL) {
		return -2;
	}
	
	
	int quit = 0;
	SDL_Event evt;
	
	/*
	  测试用
	 */
	read_map("map1.txt");
	
	
	while (!quit) {
		if (SDL_PollEvent(&evt)) {
			if (evt.type == SDL_QUIT) {
				quit = 1;
			}
		}
		else {
			//TODO: 渲染窗口
		}
	}
	
	
	if (pWin) {
		SDL_DestroyWindow(pWin);
	}
	
	SDL_Quit();
	
	return 0;
}


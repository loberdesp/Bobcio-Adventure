#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

const int WIDTH = 800, HEIGHT = 600;

int main(int, char *[])
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window *window = SDL_CreateWindow("Hello SDL WORLD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (NULL == window)
    {
        std::cout << "Could not create window: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Event windowEvent;

    while (true)
    {
        if (SDL_PollEvent(&windowEvent))
        {
            if (SDL_QUIT == windowEvent.type)
            {
                break;
            }
        }
        SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
        SDL_Rect rfloor;
		rfloor.x = 50;
		rfloor.y = 50;
		rfloor.w = 50;
		rfloor.h = 50;
		SDL_RenderFillRect(renderer, &rfloor );
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
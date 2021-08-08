#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main() {

  std::cout << "Hello world!" << std::endl;

  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_JPG);

  SDL_Window *window = SDL_CreateWindow("SDL2Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

  auto *screenSurface = SDL_GetWindowSurface(window);
  auto *img = IMG_Load("resources/portugal-1350643_1920.jpg");

  if (img == NULL)
    return 1;

  SDL_Surface *optimizedImg = SDL_ConvertSurface(img, screenSurface->format, 0);

  if (optimizedImg == NULL)
    return 1;

  SDL_FreeSurface(img);

  SDL_BlitSurface(optimizedImg, NULL, screenSurface, NULL);
  SDL_UpdateWindowSurface(window);
  SDL_Delay(3000);

  SDL_DestroyWindow(window);
  SDL_Quit();
  IMG_Quit();

  return 0;
}

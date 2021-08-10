#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main() {

  std::cout << "Hello world!" << std::endl;

  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_JPG);

  SDL_Window *window = SDL_CreateWindow("SDL2Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 410, 0);

  auto *screenSurface = SDL_GetWindowSurface(window);
  auto *img = IMG_Load("resources/portugal-1350643_1920.jpg");

  if (img == NULL)
    return 1;

  auto *optimizedSurface = SDL_ConvertSurface(img, screenSurface->format, 0);

  if (optimizedSurface == NULL)
    return 1;

  SDL_FreeSurface(img);
  // Apply the image stretched
  SDL_Rect stretchRect;
  stretchRect.x = 0;
  stretchRect.y = 0;
  stretchRect.w = 640;
  stretchRect.h = 410;
  SDL_BlitScaled(optimizedSurface, NULL, screenSurface, &stretchRect);

  // SDL_BlitSurface(optimizedSurface, NULL, screenSurface, NULL);

  SDL_UpdateWindowSurface(window);
  SDL_Delay(3000);

  SDL_DestroyWindow(window);

  IMG_Quit();
  SDL_Quit();

  return 0;
}

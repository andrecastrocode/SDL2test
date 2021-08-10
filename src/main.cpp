#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

void initSDL() {
  SDL_Init(SDL_INIT_VIDEO);
  IMG_Init(IMG_INIT_JPG);
}

void cleanupSDL() {
  IMG_Quit();
  SDL_Quit();
}

void scaleImageToWindow() {
  SDL_Window *window
      = SDL_CreateWindow("scaleImageToWindow", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 410, 0);

  auto *screenSurface = SDL_GetWindowSurface(window);
  auto *img = IMG_Load("resources/portugal-1350643_1920.jpg");

  if (img == NULL) {
    std::cout << "Could not load img" << std::endl;
    SDL_DestroyWindow(window);
    throw 1;
  }

  auto *optimizedSurface = SDL_ConvertSurface(img, screenSurface->format, 0);

  SDL_FreeSurface(img);
  if (optimizedSurface == NULL) {
    std::cout << "Could not load optimizedSurface" << std::endl;
    SDL_DestroyWindow(window);
    throw 2;
  }

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

  SDL_FreeSurface(optimizedSurface);
  SDL_DestroyWindow(window);
}

void loadTextureToWindow() {
  SDL_Window *window
      = SDL_CreateWindow("loadTextureToWindow", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 410, 0);

  auto *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (renderer == NULL) {
    std::cout << "Failed to create renderer" << std::endl;
    SDL_DestroyWindow(window);
    throw 3;
  }

  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

  auto *img = IMG_Load("resources/portugal-1350643_1920.jpg");
  auto *texture = SDL_CreateTextureFromSurface(renderer, img);
  SDL_FreeSurface(img);

  // Clear screen
  SDL_RenderClear(renderer);

  // Render texture to screen
  SDL_RenderCopy(renderer, texture, NULL, NULL);

  // Update screen
  SDL_RenderPresent(renderer);
  SDL_Delay(3000);

  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
}

int main() {

  std::cout << "Hello world!" << std::endl;

  initSDL();
  // scaleImageToWindow();

  loadTextureToWindow();
  cleanupSDL();
  return 0;
}

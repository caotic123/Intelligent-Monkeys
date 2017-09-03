// Interface cronstrution for the IA GRAPHICS
// Of Tiago for the World

#include <windows.h>
#include <iostream>
#include "SDL.h"
#include <SDL2\SDL_image.h>
#include <SDL2\SDL_ttf.h>
#undef main

// Graphics
#define square_space_x 40
#define square_space_y 20

typedef struct {
  int x;
  int y;
} pos;

class interface_ {
 public:
  void init_(int LEN_x___, int LEN_y___) {
    LEN_x = LEN_x___;
    LEN_y = LEN_y___;
    int subSizeX = (LEN_x * square_space_x) / 3;
    int subSizeY = (LEN_y * square_space_y) / 3;
    int subPosX = 100 + (LEN_x * square_space_x) / 4;
    int subPosY = 100 + (LEN_y * square_space_y) / 4;
    __i = 0;
    SDL_Init(SDL_INIT_VIDEO);  // init video
    IMG_Init(IMG_INIT_PNG);
    TTF_Init();

    window = SDL_CreateWindow("MONKEY IA", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, LEN_x * square_space_x,
                              LEN_y * square_space_y, 0);

    renderer = SDL_CreateRenderer(window, -1, 0);
    m_window = SDL_CreateWindow("IA DADOS", subPosX, subPosY, 400, 300, 0);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 153, 204, 50, 0);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);

    screen = SDL_GetWindowSurface(window);
    DestR.x = 1;
    DestR.y = 1;
    DestR.w = LEN_x * square_space_x;
    DestR.h = LEN_y * square_space_y;

    SDL_RenderClear(renderer);
    SDL_RenderClear(m_renderer);

    texture = IMG_LoadTexture(renderer, "resource\\p_.png");
    SDL_RenderCopy(renderer, texture, NULL, &DestR);
    SDL_RenderPresent(renderer);
    SDL_Delay(1000 * 3);
    clean___();
    SDL_RenderPresent(m_renderer);
  }

  void ___print(std::string str) {
    SDL_Color black_ = {255, 255, 255};
    TTF_Font *___font = TTF_OpenFont("resource\\font.ttf", 14);
    if (___font == NULL) {
      printf("Dont't have font\n");
      printf("TTF_OpenFont: %s\n", TTF_GetError());
      system("pause");
      system("exit");
    }
    surfaceMessage = TTF_RenderText_Solid(___font, str.c_str(), black_);
    Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect;  // create a rect

    Message_rect.x = 0;
    Message_rect.y = __i * 20;
    Message_rect.w = surfaceMessage->w;
    Message_rect.h = surfaceMessage->h;
    SDL_RenderCopy(m_renderer, Message, NULL, &Message_rect);
    SDL_RenderPresent(m_renderer);
    __i = __i + 1;
  }

  void ___print__floor(bool i, pos pos_) {
    int c = 0, b = 0, z = 0;
    DestR.x = pos_.x;
    DestR.y = pos_.y;
    DestR.x = pos_.x * square_space_x;
    DestR.y = pos_.y * square_space_y;

    if (i) {
      c = 181;
      b = 60;
      z = 255;
    } else {
      c = 233;
      b = 14;
      z = 255;
    }

    SDL_SetRenderDrawColor(renderer, c, b, z, 255);
    SDL_RenderFillRect(renderer, &DestR);

    SDL_RenderPresent(renderer);
  }

  void close___() {
    SDL_DestroyWindow(window);
    SDL_DestroyWindow(m_window);
  }

  void wait_and_continue() {
    x__ = true;

    for (int i = 0; i <= (LEN_y - 1); i++) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
      SDL_RenderDrawLine(renderer, 0, (i * square_space_y),
                         LEN_x * square_space_x, (i * square_space_y));
    }
    for (int i = 0; i <= (LEN_x - 1); i++) {
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
      SDL_RenderDrawLine(renderer, (i * square_space_x), 0,
                         (i * square_space_x), LEN_y * square_space_y);
    }

    SDL_RenderPresent(renderer);
    while (x__) {
      SDL_WaitEvent(&evt);
      SDL_PollEvent(&evt);
      if (evt.type == SDL_KEYUP || evt.type == SDLK_RIGHT) {
        x__ = false;
      }
    }

    clean___();
  }

  void __image(int p_, pos pos_) {
    int c = 0, b = 0, z = 255;
    char sd[100] = "resource\\";
    DestR.x = pos_.x * square_space_x;
    DestR.y = pos_.y * square_space_y;
    DestR.w = square_space_x;
    DestR.h = square_space_y;

    if (p_ == 0) {
      c = 255;
      b = 255;
      z = 0;
    } else if (p_ == 1) {
      c = 255;
      b = 0;
      z = 0;
    } else if (p_ == 2) {
      c = 35;
      b = 94;
      z = 33;
    }

    SDL_SetRenderDrawColor(renderer, c, b, z, 255);
    SDL_RenderFillRect(renderer, &DestR);

    strncat(sd,
            (p_ == 0) ? "tigre" : (p_ == 1) ? "aguia" : (p_ == 2) ? "cobra"
                                                                  : "monkey",
            6);
    strncat(sd, ".png", 10);

    texture = IMG_LoadTexture(renderer, sd);

    SDL_RenderCopy(renderer, texture, NULL, &DestR);

    SDL_RenderPresent(renderer);
  }

  void clean___() {
    SDL_DestroyTexture(Message);
    SDL_DestroyRenderer(renderer);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 153, 204, 50, 255);

    SDL_RenderClear(renderer);
    screen = SDL_GetWindowSurface(window);

    SDL_RenderPresent(renderer);
    __i = 0;
  }

  void clean_m() {
    SDL_DestroyTexture(Message);
    SDL_DestroyRenderer(m_renderer);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_Surface *screen;
  SDL_Window *window;
  SDL_Window *m_window;
  SDL_Surface *image;
  SDL_Renderer *renderer;
  SDL_Renderer *m_renderer;
  SDL_Texture *texture = NULL;
  SDL_Surface *surfaceMessage;
  SDL_Texture *Message;
  SDL_Event evt;
  SDL_Rect SrcR;
  SDL_Rect DestR;
  int __i;
  bool x__;
  int LEN_x;
  int LEN_y;
};

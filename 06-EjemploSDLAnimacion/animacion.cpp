#include <iostream>
#include <SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int RECTANGLE_WIDTH = 50;
const int RECTANGLE_HEIGHT = 50;
const int NUM_RECTANGLES = 5;
const int VELOCITY = 1;

struct Rectangle {
    int x, y;
};

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Animación Simple en SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Inicializar las posiciones de los rectángulos
    Rectangle rectangles[NUM_RECTANGLES];
    for (int i = 0; i < NUM_RECTANGLES; i++) {
        rectangles[i].x = i * 100;
        rectangles[i].y = SCREEN_HEIGHT / 2 - RECTANGLE_HEIGHT / 2;
    }

    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Borrar el contenido anterior del renderizador
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // Mover los rectángulos hacia la derecha
        for (int i = 0; i < NUM_RECTANGLES; i++) {
            rectangles[i].x += VELOCITY;
            if (rectangles[i].x > SCREEN_WIDTH) {
                rectangles[i].x = -RECTANGLE_WIDTH;
            }

            // Dibujar los rectángulos
            SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
            SDL_Rect rect = {rectangles[i].x, rectangles[i].y, RECTANGLE_WIDTH, RECTANGLE_HEIGHT};
            SDL_RenderFillRect(renderer, &rect);
        }

        // Actualizar la pantalla
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

#include <iostream>
#include <SDL.h>
#include <cmath>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const float ROTATION_SPEED = 0.01f; // Velocidad de rotación en radianes por fotograma

struct Point {
    float x, y;
    Point(float _x, float _y) : x(_x), y(_y) {}
};

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Rotación en torno al Centro en SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

    SDL_Event e;
    bool quit = false;

    Point p1(400.0f, 100.0f);
    Point p2(300.0f, 300.0f);
    Point p3(500.0f, 300.0f);

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Borrar el contenido anterior del renderizador
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // Calcular el centro del triángulo
        float centerX = (p1.x + p2.x + p3.x) / 3.0f;
        float centerY = (p1.y + p2.y + p3.y) / 3.0f;

        // Trasladar el triángulo para que su centro esté en el origen (0, 0)
        p1.x -= centerX;
        p1.y -= centerY;
        p2.x -= centerX;
        p2.y -= centerY;
        p3.x -= centerX;
        p3.y -= centerY;

        // Calcular los puntos rotados
        float cosA = cos(ROTATION_SPEED);
        float sinA = sin(ROTATION_SPEED);

        float x1 = p1.x * cosA - p1.y * sinA;
        float y1 = p1.x * sinA + p1.y * cosA;

        float x2 = p2.x * cosA - p2.y * sinA;
        float y2 = p2.x * sinA + p2.y * cosA;

        float x3 = p3.x * cosA - p3.y * sinA;
        float y3 = p3.x * sinA + p3.y * cosA;

        // Trasladar el triángulo de nuevo a su posición original
        p1.x = x1 + centerX;
        p1.y = y1 + centerY;
        p2.x = x2 + centerX;
        p2.y = y2 + centerY;
        p3.x = x3 + centerX;
        p3.y = y3 + centerY;

        // Dibujar el triángulo rotado
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF); // Rojo
        SDL_RenderDrawLine(renderer, p1.x, p1.y, p2.x, p2.y);
        SDL_RenderDrawLine(renderer, p2.x, p2.y, p3.x, p3.y);
        SDL_RenderDrawLine(renderer, p3.x, p3.y, p1.x, p1.y);

        // Actualizar la pantalla
        SDL_RenderPresent(renderer);

        // Pequeña pausa para controlar la velocidad de la animación
        SDL_Delay(10);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

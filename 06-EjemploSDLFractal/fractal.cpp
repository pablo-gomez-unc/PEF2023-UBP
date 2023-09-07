#include <iostream>
#include <SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int MAX_ITERATIONS = 1000;

// Función para verificar si un punto está dentro del conjunto de Mandelbrot
int mandelbrotSet(double real, double imag) {
    int iterations = 0;
    double zReal = real;
    double zImag = imag;

    while (iterations < MAX_ITERATIONS) {
        double zReal2 = zReal * zReal;
        double zImag2 = zImag * zImag;

        if (zReal2 + zImag2 > 4.0) {
            break; // El punto está fuera del conjunto de Mandelbrot
        }

        zImag = 2.0 * zReal * zImag + imag;
        zReal = zReal2 - zImag2 + real;
        iterations++;
    }

    return iterations;
}

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Fractal de Mandelbrot en SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Dibujar el fractal de Mandelbrot
        for (int x = 0; x < SCREEN_WIDTH; x++) {
            for (int y = 0; y < SCREEN_HEIGHT; y++) {
                double real = (x - SCREEN_WIDTH / 2.0) * 4.0 / SCREEN_WIDTH;
                double imag = (y - SCREEN_HEIGHT / 2.0) * 4.0 / SCREEN_HEIGHT;

                int color = mandelbrotSet(real, imag);

                // Colorear el píxel en función del número de iteraciones
                Uint8 r = color % 256;
                Uint8 g = (color / 256) % 256;
                Uint8 b = (color / (256 * 256)) % 256;

                SDL_SetRenderDrawColor(renderer, r, g, b, 0xFF);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }

        // Actualizar la pantalla
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

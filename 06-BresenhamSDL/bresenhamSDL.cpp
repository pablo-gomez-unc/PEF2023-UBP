// https://www.youtube.com/watch?v=sC3M6C8IpoE

#include <iostream>
#include <SDL.h>
#include <vector>
using namespace std;

const int SCREEN_WIDTH = 400;
const int SCREEN_HEIGHT = 400;

struct Point {
    int x,y ;
    Point (int _x, int _y) : x(_x) , y(_y) {}
};

vector <Point> bresenhamLine (int x0, int y0, int x1, int y1) {
    vector <Point> points;

    int dx = abs(x1-x0);
    int dy = abs(y1-y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int error = dx-dy;

    points.push_back(Point(x0,y0));

    while (x0 != x1 || y0 != y1) {
        int error2 = error * 2;
        if (error2 > -dy) {
            error -= dy;
            x0 += sx;
        }
        if (error2 < dx) {
            error += dx;
            y0 += sy;
        }
        points.push_back(Point(x0,y0));    
    }

    return points;
}

int main(int argc, char* args[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("TP1 : PEF", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
        for (int i = 0; i < 400; i++){
            vector<Point> linePoints = bresenhamLine (0,0,400,i);
            for (int j=0; j < linePoints.size(); j++){
                SDL_RenderDrawPoint(renderer, linePoints[j].x, linePoints[j].y);
            }
            linePoints.clear();
            linePoints.shrink_to_fit();
        }
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

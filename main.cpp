#include <iostream>
#include <cmath>
#include "perlinnoise.h"
#include <SDL2/SDL.h>
#include <stdio.h>
using namespace std;

const int screenWidth = 600;
const int screenHeight = 600;

bool init();
bool loadMedia();
void close();

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* mapSurface = NULL;

bool init() {

    bool success = true;
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
     else
    {
        //Create window
        window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );
        }
    }

    return success;

}

bool loadMedia() {
    bool success = true;
    //build map from array
    return success;
}

void close() {
    SDL_FreeSurface(mapSurface);
    mapSurface = NULL;
    //Destroy window
    SDL_DestroyWindow( window );
    window = NULL;

    //Quit SDL subsystems
    SDL_Quit();

}
// main() is where program execution begins.
int main(int argc, char* args[])
{
    srand(time(NULL));
    int seed = rand() % 256;
    PerlinNoise pn(seed);
    unsigned int kk = 0;
    int maxNumberBlockHeight = screenWidth / 8;
    int maxNumberBlockWidth = screenHeight / 8;

    int a[screenHeight][screenHeight];
    for (int i = 0; i < screenHeight; i++)
    {
        //[i][0]=rand()%2;
        for (int j = 0; j < screenWidth; j++)
        {
            double x  = (double)j/((double)screenWidth);
            double y = (double)i/((double)screenHeight);
            double n = pn.noise(10 * x, 10 * y, 0.4);
            a[i][j] = n;//floor(255 * n);
            cout << a[i][j] << " \n"[j == sizeof(a[i]) / sizeof(a[i][0])-1];
        }
    }

    if(!init()) {
        printf("Failed to Initialize!\n");
    }
    else {
        if(!loadMedia()) {
            printf("Failed to load media!\n");
        }
        else {
            //Draw map
            //Update surface
            SDL_Delay(2000);
        }
    }

    close();
    return 0;
}

//int inc(int num) {
//    num++;
//    if (repeat > 0) num %= repeat;
//
//    return num;
//}

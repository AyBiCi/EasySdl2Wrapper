#include "renderer.h"
#include <SDL2/SDL.h>

SDL_Window * win;
SDL_Renderer * rend;

float posX = 0;
float posY = 0;

int width = 1000;
int height = 1000;

int blockSize = 50;

void Renderer::init(){
	// returns zero on success else non-zero
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("error initializing SDL: %s\n", SDL_GetError());
	}
	win = SDL_CreateWindow("GAME", // creates a window
									SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									width, height, 0);

    if (win == 0) {
		printf("error creating window SDL: %s\n", SDL_GetError());
	}

	// triggers the program that controls
	// your graphics hardware and sets flags
	Uint32 render_flags = SDL_RENDERER_ACCELERATED;

	// creates a renderer to render our images
	rend = SDL_CreateRenderer(win, -1, render_flags);
}

void drawLine(int x1, int y1, int x2, int y2, int colR=255, int colG=0, int colB=0){
    SDL_SetRenderDrawColor( rend, colR, colG, colB, 0xFF );
    SDL_RenderDrawLine(rend, x1, y1, x2, y2);
}

void drawMesh(){

    int gray = 0x22;

    //Horizontal
    int padding = (int) (blockSize * posX) % blockSize;
    for(int start = padding; start <= width; start+=blockSize){
        drawLine(start, 0, start, height, gray,gray,gray);
    }

    //Vertical
    padding = (int) (blockSize * posY) % blockSize;
    for(int start = padding; start <= height; start+=blockSize){
        drawLine(0, start, width, start,gray,gray,gray);
    }
}

void Renderer::line(float x1, float y1, float x2, float y2, int colR, int colG, int colB){
    y1 = -y1;
    y2 = -y2;
    drawLine((int) (blockSize*x1 + posX*blockSize) + width/2, (int) (blockSize*y1 + posY*blockSize) + height/2,
    (int) (blockSize*x2 + posX*blockSize) + width/2, (int) (blockSize*y2 + posY*blockSize) + height/2, colR, colG, colB);
}

void Renderer::clear(){
    SDL_SetRenderDrawColor( rend, 0x00, 0x00, 0x00, 0xFF );
    SDL_RenderClear(rend);
    // drawMesh();
}

void drawPoint(int x, int y){
    int s = 2;
    SDL_Rect fillRect = { x - s, y - s, s*2, s*2};
    SDL_SetRenderDrawColor( rend, 0xFF, 0x00, 0x00, 0xFF );
    SDL_RenderFillRect( rend, &fillRect );
}

int xcount(float x){
    return (int) (blockSize*x + posX*blockSize) + width/2;
}

int ycount(float y){
    y = -y;
    return (int) (blockSize*y + posY*blockSize) + height/2;
}

void Renderer::point(float x, float y){
    y = -y;
    drawPoint((int) (blockSize*x + posX*blockSize) + width/2, (int) (blockSize*y + posY*blockSize) + height/2);
}

int trInter = 5;

void Renderer::triangle(float x1, float y1, float x2, float y2, float x3, float y3){
    
    //count vector to interpolate
    int interCount = trInter;
    int interCountStart = interCount;
    

    float xint = (x3 - x2) / interCount;
    float yint = (y3 - y2) / interCount;

    for(float x = x2, y = y2; interCount-->0; x+=xint, y+=yint){
        line(x1, y1, x, y, (int)(100.0 * (float)(interCount * 1.0 / interCountStart * 1.0)) + 155, 0x00, 0x00);
    }
}

void Renderer::triangleInterpolation(int num){
    trInter = num;
}

void Renderer::present(){
    SDL_RenderPresent(rend);
}

void Renderer::close(){
    // destroy renderer
	SDL_DestroyRenderer(rend);

	// destroy window
	SDL_DestroyWindow(win);
	
	// close SDL
	SDL_Quit();
}

#ifndef RENDERER_H
#define RENDERER_H
#include <string>

namespace Renderer{
    void init();
    void clear();
    void present();
    void line(float x1, float y1, float x2, float y2, int colR=255, int colG=0, int colB=0);
    void point(float x, float y);
    void triangle(float x1, float y1, float x2, float y2, float x3, float y3);
    void triangleInterpolation(int num);
    void close();

}


#endif
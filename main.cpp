#include "renderer.h"
#include <iostream>
#include <math.h>
#include "SDL2/SDL_timer.h"
#include <chrono>
#include <vector>


float arccossin(float x, float y){
    float ac = std::acos(x);

    if(y < 0){
        ac = (2 * M_PI) - ac;
    }

    return ac;
}

struct Point{
    float x;
    float y;
};

Point rotate2D(float x, float y, float angle){
    //Normalize

    //First count vector length by pythagoras
    float c = std::sqrt(x * x + y * y);

    //Normalize
    x /= c;
    y /= c;

    //Count angle
    float originalAngle = arccossin(x, y);

    angle += originalAngle;
    
    //Make angle between 0 and 2*PI
    int z = (int)(angle/2*M_PI);
    angle -= z * (2*M_PI);

    x = cos(angle)* c;
    y = sin(angle)* c;

    return {x, y};
}


class MeshRenderer{
    float * renderData;
    int renderDataSize;
    float * renderDataCopy;

    int * lineRenderData;
    int lineRenderDataSize;

    int * triangleRenderData;
    int triangleRenderDataSize;

public:
    MeshRenderer(float * renderData, int renderDataSize, int * lineRenderData = NULL, int lineRenderDataSize = 0, int * triangleRenderData = NULL, int triangleRenderDataSize = 0){
        this->renderData = renderData;
        this->renderDataSize = renderDataSize;
        renderDataCopy = (float*) malloc(sizeof(float) * renderDataSize);

        this->lineRenderData = lineRenderData;
        this->lineRenderDataSize = lineRenderDataSize;

        this->triangleRenderData = triangleRenderData;
        this->triangleRenderDataSize = triangleRenderDataSize;
    }

    void render(    float rotX, float rotY, float rotZ, 
                    float scaleX = 1.0 , float scaleY = 1.0, float scaleZ = 1.0,
                    float transformX = 0, float transformY = 0, float transformZ = 0){
        for(int i=0;i<renderDataSize;i++){
            renderDataCopy[i] = renderData[i];
        }

        //Rotate x axis
        for(int i=0;i<renderDataSize;i+=3){
            Point rot = rotate2D(renderDataCopy[i+1], renderDataCopy[i+2], rotX);
            renderDataCopy[i+1] = rot.x;
            renderDataCopy[i+2] = rot.y;
        }

        //Rotate y axis
        for(int i=0;i<renderDataSize;i+=3){
            Point rot = rotate2D(renderDataCopy[i+0], renderDataCopy[i+2], rotY);
            renderDataCopy[i+0] = rot.x;
            renderDataCopy[i+2] = rot.y;
        }

        //Rotate z axis
        for(int i=0;i<renderDataSize;i+=3){
            Point rot = rotate2D(renderDataCopy[i+0], renderDataCopy[i+1], rotZ);
            renderDataCopy[i+0] = rot.x;
            renderDataCopy[i+1] = rot.y;
        }

        //Scale
        for(int i=0;i<renderDataSize;i+=3){
            renderDataCopy[i] = renderDataCopy[i] * scaleX;
            renderDataCopy[i+1] = renderDataCopy[i+1] * scaleY;
            renderDataCopy[i+2] = renderDataCopy[i+2] * scaleZ;
        }

        //Transform
        for(int i=0;i<renderDataSize;i+=3){
            renderDataCopy[i] = renderDataCopy[i] + transformX;
            renderDataCopy[i+1] = renderDataCopy[i+1] + transformY;
            renderDataCopy[i+2] = renderDataCopy[i+2] + transformZ;
        }

        //Draw lines
        for(int i=0;i<lineRenderDataSize;i+=2){
            int p1 = lineRenderData[i] * 3;
            int p2 = lineRenderData[i+1] * 3;
            Renderer::line(renderDataCopy[p1],renderDataCopy[p1+1], renderDataCopy[p2], renderDataCopy[p2+1]);
        }

        //Draw points
        for(int i=0;i<renderDataSize;i+=3){
            Renderer::point(renderDataCopy[i],renderDataCopy[i+1]);
        }

        int lineCount = 5;
        //Draw triangles
        for(int i=0; i < triangleRenderDataSize;i+=3){
            int p1 = triangleRenderData[i] * 3;
            int p2 = triangleRenderData[i+1] * 3;
            int p3 = triangleRenderData[i+2] * 3;


            Renderer::triangle( renderDataCopy[p1], renderDataCopy[p1+1],
                                renderDataCopy[p2], renderDataCopy[p2+1],
                                renderDataCopy[p3], renderDataCopy[p3+1]);
        }
    }
};

int main(){
    int frames = 0;

    

    float renderData[] = {
        -2, 2,  2,
        2,  2,  2,
        2,  -2, 2,
        -2, -2, 2,
        
        -2, 2,  -2,
        2,  2,  -2,
        2,  -2, -2,
        -2, -2, -2,
    };

    int lineRenderData[] ={
        0, 1,
        1, 2,
        2, 3,
        3, 0,
        0, 4,
        1, 5,
        2, 6,
        3, 7,
        4, 5,
        5, 6,
        6, 7,
        7, 4
    };


    float renderData2[] = {
        0, 7, -2,
        -4, 2, -2,
        4, 2 , -2,
        -2, -3, -2,
        2, -3, -2,
        -1, 1.6, 0,
        1, 1.6, 0,
    };

    int lineRenderData2[] = {
        0, 1,
        0, 2,
        1, 3,
        2, 4,
        3, 4,
        0, 5,
        0, 6,
        1, 5,
        2, 6,
        5, 3,
        6, 4,
        5, 6
    };

    int triangleRenderData[] ={
        0, 1, 2,
        0, 2, 3,
        0, 4, 1,
        4, 1, 5, 
        1, 2, 5,
        5, 2, 6, 
        2, 3, 6,
        6, 3, 7,
        4, 5, 6,
        4, 6, 7,
        0, 3, 7,
        7, 0, 4
    };

    int triangleRenderData2[] ={
        0, 1, 5,
        0, 5, 6,
        0, 6, 2,
        1, 5, 3,
        6, 2, 4,
        5, 6, 3,
        3, 4, 6,
    };

    Renderer::init();

    MeshRenderer mrend = MeshRenderer(renderData, 24, lineRenderData, 24, triangleRenderData, 10 * 3);
    MeshRenderer mrend2 = MeshRenderer(renderData2, 7*3, lineRenderData2, 12*2, triangleRenderData2, 7 * 3);

    // //create new mesh
    // float renderData3[3 * 30];

    // for(int i=0;i<90;i+=3){
    //     renderData3[i] = (float) (((rand()%600) / 10.0) - 30.0);
    //     renderData3[i+1] = (float) (((rand()%600) / 10.0) - 30.0);
    //     renderData3[i+2] = (float) (((rand()%100) / 10.0) - 5.0);
    // }

    // MeshRenderer mrend3 = MeshRenderer(renderData3, 30*3, NULL, 0);

    std::vector<long> tiers;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    
    long frameCount = 7400;
    int interpolation = 2;
    while(true){ 
        
        Renderer::clear();

        float s = sin(frames * 0.01);
        float tr1 = cos(frames * 0.1);
        float tr2 = sin(frames * 0.1);

        if(frames%(int)(M_PI*2 / 0.01) == 0){
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            tiers.push_back(std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count());
            interpolation *= 2;
            Renderer::triangleInterpolation(interpolation);
            begin = std::chrono::steady_clock::now();
        }


        mrend.render(frames*(M_PI/100),frames*(M_PI/300),frames*(M_PI/100),
            s, s, s,tr2, tr1);
        mrend2.render(frames*(M_PI/200),frames*(M_PI/200),frames*(M_PI/100),
            s, s, s,tr1, tr2);
        
        // mrend3.render(M_PI_2-0.1, 0, 0);
        
        Renderer::present();

        // Renderer::line(0,0,2,2);
        // SDL_Delay(1000/60);
        

        if(frames++ > frameCount) break;
    }

    

    std::cout<<"Framerate by tier:"<<std::endl;
    int i = 1;
    int inter = 2;
    for(long tier : tiers){
        std::cout<<"Tier "<<i<<" (interpolation "<<inter<<") - Framerate: "<<1000000.0 / (tier / (int)(M_PI*2 / 0.01))<<std::endl;
        i++;
        inter *= 2;
    }
    

    Renderer::close();
}

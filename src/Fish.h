#pragma once
#include "ofMain.h"

class Fish {
public:
    ofPoint position;
    float speed;
    ofImage fishImage;  
    Fish(float x, float y, float spd, ofImage& image);
    bool caught;
    void reelIn(ofPoint hook);
    void update();
    void draw();

};


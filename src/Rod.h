#pragma once
#include "ofMain.h"

class Rod {
public:
    float tension;    
    float maxTension;
    ofPoint tip;
    ofPoint hook;
    float lineLength;
    float maxLineLength;
    

    Rod(float x, float y, float maxLen);

    void update(bool isCasting, bool isReeling);
    void draw();
};

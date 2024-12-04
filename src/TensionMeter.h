#pragma once
#include "ofMain.h"
#include "Rod.h"  

class TensionMeter {
public:
    Rod* rod;  
    ofRectangle meterRect;

    TensionMeter(Rod* r); 

    void draw();  
};

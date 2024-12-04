#include "TensionMeter.h"

TensionMeter::TensionMeter(Rod* r) {
    rod = r; 
    meterRect.set(10, 30, 200, 20);
}

void TensionMeter::draw() {
   
    float tension = rod->tension;
    float maxTension = rod->maxTension;

    ofSetColor(200, 200, 200);
    ofDrawRectangle(meterRect);


    float tensionWidth = ofMap(tension, 0, maxTension, 0, meterRect.width);
    ofSetColor(255, 0, 0); 
    ofDrawRectangle(meterRect.x, meterRect.y, tensionWidth, meterRect.height);

  
    ofSetColor(0, 0, 0);
    ofNoFill();
    ofDrawRectangle(meterRect);
}

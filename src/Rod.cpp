#include "Rod.h"

Rod::Rod(float x, float y, float maxLen) {
    tip.set(x, y);
    hook = tip;
    lineLength = 0;
    maxLineLength = maxLen;
    tension = 0.0f;
    maxTension = 5.0f;
}

void Rod::update(bool isCasting, bool isReeling) {
    if (isCasting) {
            lineLength = ofClamp(lineLength + 2, 0, maxLineLength);
    }
    else if (isReeling) {
            lineLength = ofClamp(lineLength - 2, 0, maxLineLength);
            tension += 0.5;
    }
    hook.y = tip.y + lineLength;

    /*if (tension > maxTension) {
        ofLog() << "Line snapped!";
        tension = 0; 
       
    }
    else {
        tension -= 0.1; 
    }*/
}

void Rod::draw() {
    ofSetColor(0, 0, 0);
    ofDrawLine(tip.x, tip.y, hook.x, hook.y);
    ofDrawCircle(hook.x, hook.y, 5); 
}

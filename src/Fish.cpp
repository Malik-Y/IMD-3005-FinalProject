#include "Fish.h"

Fish::Fish(float x, float y, float spd, ofImage& image) {
    position.set(x, y);
    speed = spd;
    fishImage = image;  
    caught = false;
}

void Fish::update() {
    if (!caught) {
        position.x += speed;
    }
    if (position.x > ofGetWidth() || position.x < 100) {
        speed = -speed; 
    }
}

void Fish::draw() {
    fishImage.draw(position.x, position.y); 
}


void Fish::reelIn(ofPoint rodHook) {
    if (caught) {
       
        if (position.y > rodHook.y) {
            position.y -= 5;  
        }
        
    }
}
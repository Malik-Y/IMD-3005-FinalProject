#pragma once
#include "ofMain.h"
#include "Fish.h"
#include "Rod.h"
#include "TensionMeter.h"

class ofApp : public ofBaseApp {
public:

    void setup();
    void update();
    void draw();

    void setupFish();
    void updateFish();
    void checkCatch();


    ofApp();

    Rod rod;
    TensionMeter tensionMeter;
    vector<Fish> fishList;
    int score;
    bool isFishCaught = false;

    ofImage background; 
    ofImage land; 
    vector<ofImage> fishes; 
};

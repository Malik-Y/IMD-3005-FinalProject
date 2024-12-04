#include "ofApp.h"

ofApp::ofApp()
    : rod(400, 100, 600),      
    tensionMeter(&rod)         
{
    score = 0;
}

void ofApp::setup() {

    isFishCaught = false;

    background.load("sky_clouds.png");
    background.resize(500, 500);
    land.load("land.png");




    fishes.push_back(ofImage("fish1.png"));
    fishes.push_back(ofImage("fish2.png"));
    fishes.push_back(ofImage("fish3.png"));

    // Resize fish
    for (auto& fishes : fishes) {
        fishes.resize(100, 100);
    }

    // Setup fish
    setupFish();
}

void ofApp::update() {
    bool isCasting = ofGetKeyPressed(' ');
    bool isReeling = ofGetKeyPressed(OF_KEY_UP);

    // Update rod mechanics
    rod.update(isCasting, isReeling);

    updateFish();
    checkCatch();
   
    

   
}

void ofApp::draw() {
    ofSetColor(100, 100, 100, 255);
    background.draw(0, 0, ofGetWidth(), ofGetHeight());
    land.draw(0, 200, ofGetHeight() / 2, ofGetWidth() / 2);

    // Draw rod and fish
    rod.draw();
    for (auto& fish : fishList) {
        ofSetColor(100, 100, 100, 255);
        fish.draw();
    }

    // Draw tension meter
   // tensionMeter.draw(); // need to fix the functionality

    // Display score
    ofSetColor(0);
    ofDrawBitmapString("Score: " + ofToString(score), 10, 20);
}

void ofApp::setupFish() {
    // Create fish with random positions and speeds
    for (int i = 0; i < 5; i++) {
        int randomFish = ofRandom(0, fishes.size());
        fishList.push_back(Fish(ofRandom(500, ofGetWidth()), ofRandom(400, 600), ofRandom(-1, 1), fishes[randomFish]));
    }
}

void ofApp::updateFish() {
    for (auto it = fishList.begin(); it != fishList.end(); ) {
        if (it->caught) {
            // Reel in the fish by a fixed step, move towards the hook
            it->reelIn(rod.hook);  // 5.0 is the speed for reeling in

            // If the fish has reached the hook, it is reeled in and should be removed from the list
            if (it->caught && it->position.y<=100) {  // The fish has been reeled in and is no longer caught
                it = fishList.erase(it); // Remove the fish from the list
                score += 10; // Increase the score
                ofLog() << "Fish reeled in! Score: " << score;
                
                isFishCaught = false;
            }
            else {
                ++it; // Keep it in the list if it's still being reeled in
            }
        }
        else {
            it->update(); // Update the fish if it's not caught
            ++it;
        }
    }
}
void ofApp::checkCatch() {
   
    if (!isFishCaught) {
        for (auto& fish : fishList) {
            // Check if the fish is not already caught and is within range of the hook
            if (!fish.caught && ofDist(rod.hook.x, rod.hook.y, fish.position.x, fish.position.y) < 50) {
                // Set the fish as caught
                fish.caught = true;
                isFishCaught = true;
                ofLog() << "Fish caught! Start reeling in!";
            }
        }
    }
}




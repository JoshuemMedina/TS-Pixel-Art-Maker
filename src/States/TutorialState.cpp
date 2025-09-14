#include "TutorialState.h"

TutorialState::TutorialState() {
    // Asset Load
    ofBackground(000000);

    background.load("tutorial/Background.png");

    // Button
    returnButton = new Button(ofGetWidth()-margin, 0, margin, margin, "tutorial/Return.png");
}

void TutorialState::update() {}

void TutorialState::draw() {
    ofSetColor(ofColor::white);

    // Draw Assets
    background.draw(0, 0, ofGetWidth(), ofGetHeight());

    // Draw Buttons
    returnButton->draw();
}

void TutorialState::reset() {}

void TutorialState::keyPressed(int key) {}

void TutorialState::keyReleased(int key) {}

void TutorialState::mousePressed(int x, int y, int button) {
    if (returnButton->pressed(x, y)) {
        this->setNextState("App");
        this->setFinished(true);
        if (Settings::settings["playSounds"] == "1") {SoundManager::playSong("buttonClick", false);}
    }
}

// ============================== Custom Functions ==============================

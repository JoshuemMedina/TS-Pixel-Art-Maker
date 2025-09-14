#include "AnimationState.h"

AnimationState::AnimationState() {
    updateSettings();

    // Asset Load
    ofBackground(000000);

    animation.load("Animation.png");
}

void AnimationState::update() {
    if (ofGetFrameNum() > 0) {
        // Animate
        if (ofGetFrameNum() % 3 == 0 && doAnimation) {
            x += frameWidth;
            if (x == 15*frameWidth) {doAnimation = false;}
        }

        // Switch State
        if (ofGetFrameNum() >= 100) {
            this->setNextState("App");
            this->setFinished(true);
        }

        // Play Sounds
        float soundVolume = (stof(Settings::settings["soundVolume"])-(ofGetWidth()/2+150))/500;
        SoundManager::setVolume("bounce", soundVolume);
        SoundManager::setVolume("shine", soundVolume);
        if (Settings::settings["playSounds"] == "1") {
            if (ofGetFrameNum() == 2) {SoundManager::playSong("bounce", false);}
            if (ofGetFrameNum() == 27) {SoundManager::playSong("shine", false);}
        }
    }
}

void AnimationState::draw() {
    ofSetColor(ofColor::white);

    animation.drawSubsection((ofGetWidth()-imageWidth)/2, (ofGetHeight()-imageWidth)/2, imageWidth, imageWidth,
        x, 0, frameWidth, frameWidth);
}

void AnimationState::reset() {}

void AnimationState::keyPressed(int key) {}

void AnimationState::keyReleased(int key) {}

void AnimationState::mousePressed(int x, int y, int button) {}

// ============================== Custom Functions ==============================
void AnimationState::updateSettings() {
    Settings::readSettings();

    if (Settings::settings["playAnimation"] != "1") {
        this->setNextState("App");
        this->setFinished(true);
    }
}
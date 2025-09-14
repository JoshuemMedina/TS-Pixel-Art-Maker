#include "ofApp.h"
#include <iostream>

void ofApp::setup(){
    ofSetWindowPosition((ofGetScreenWidth()-ofGetWidth())/2, (ofGetScreenHeight()-ofGetHeight())/2);
    ofSetWindowTitle("TS Pixel Art Maker");

    SoundManager::loadSongs();

    app = new AppState();
    settings = new SettingsState();
    tutorial = new TutorialState();
    animation = new AnimationState();
    currentState = animation;

    cout<<endl;
    cout<<"||                 Welcome to my TS Pixel Art Maker!                 ||"<<endl;
    cout<<"|| I hope you enjoy! Feel free to contact me if you find any bugs :) ||"<<endl;
    
}

void ofApp::update() {
    currentState->update();
    
    if(currentState->hasFinished()) {
        if(currentState->getNextState() == "App") {currentState = app;}
        else if (currentState->getNextState() == "Settings") {currentState = settings;}
        else if (currentState->getNextState() == "Tutorial") {currentState = tutorial;}
        currentState->reset();
        currentState->setFinished(false);
    }
};

void ofApp::draw() {currentState->draw();}

void ofApp::keyPressed(int key) {currentState->keyPressed(key);}

void ofApp::keyReleased(int key) {currentState->keyReleased(key);}

void ofApp::mousePressed(int x, int y, int button) {currentState->mousePressed(x, y, button);}
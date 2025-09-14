#pragma once
#include "ofMain.h"
#include "AppState.h"
#include "SettingsState.h"
#include "TutorialState.h"
#include "SoundManager.h"
#include "AnimationState.h"
#include <string>
using namespace std;

class ofApp : public ofBaseApp {
    public:
        void setup();
        void update();
        void draw();
        void keyPressed(int key);
		void keyReleased(int key);
        void mousePressed(int mouseX, int mouseY, int button);

        State *currentState;
        AppState *app;
        SettingsState *settings;
        TutorialState *tutorial;
        AnimationState *animation;
};
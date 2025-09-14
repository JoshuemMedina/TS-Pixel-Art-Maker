#include "State.h"

class SettingsState : public State { 
    private:
        // Asset Load
        ofImage background;
        ofImage bar;
        ofImage barActive;
        ofImage selectedTheme;

        // Font
        ofTrueTypeFont fontTitle;
        ofTrueTypeFont fontText;
        int fontTitleSize = 35;
        int fontTextSize = 25;

        // Buttons
        vector<Button*> buttons;

        int musicSliderPos = margin+buttonWidth+barSize+50;
        int soundSliderPos = ofGetWidth()/2+buttonWidth+barSize+50;
        int musicVolume = 100;
        int soundVolume = 100;
        bool canMoveMusicSlider = false;
        bool canMoveSoundSlider = false;
        
        // Sizes
        int margin = 100;
        int separation = 75;
        int buttonWidth = 100;
        int barSize = 500;

        // Settings
        bool saveSettings = true;
        bool showTutorial = true;
        bool playAnimation = true;
        bool playMusic = true;
        bool playSounds = true;


    public:
        SettingsState();
        ~SettingsState();
        
        void update();
        void draw();
        void reset();
        void keyPressed(int key);
		void keyReleased(int key);
        void mousePressed(int x, int y, int button);

        void drawStrings();
        void updateSettings();
        void updateButtons();
};  
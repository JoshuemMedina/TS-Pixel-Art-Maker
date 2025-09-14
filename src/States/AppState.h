#include "State.h"
#include "Colors.h"
#include <cmath>

class AppState : public State { 
    private:
        // Asset Load
        ofImage background;

        ofImage grayBar;
        ofImage grayBarActive;
        ofImage box1;
        ofImage box2;
        ofImage openedFile;
        ofImage openedFileResized;

        float backGroundOffset = 0;

        // Font
        ofTrueTypeFont font;
        int fontSize = 25;

        // Buttons
        int graySliderPos = margin+buttonWidth-25;
        vector<Button*> buttons;

        // Booleans
        bool canMoveGraySlider = false;
        bool isFileOpened = false;

        bool isHexArt = true;
        bool isBigRoom = true;

        bool showErrorFileType = false;
        bool showErrorLoading = false;

        // Sizes
        int size[2] = {0, 0};

        int margin = 100;
        int buttonWidth = 300;
        int resultImageX = margin*2+buttonWidth;
        int resultImageWidth = 120*6;

        // Colors
        Colors colors;
        vector<ofColor> cubeColors;

        int grayPercentage = 100;
        float grayIntensityPercentage;

        vector<vector<string>> colorCounts = {
        {"Black", "0"},
        {"Gray", "0"},
        {"White", "0"},
        {"Coral", "0"},
        {"Red", "0"},
        {"Magenta", "0"},
        {"Pink", "0"},
        {"Purple", "0"},
        {"Blue", "0"},
        {"Light Blue", "0"},
        {"Cyan", "0"},
        {"Turquoise", "0"},
        {"Sea Green", "0"},
        {"Lime Green", "0"},
        {"Gold Yellow", "0"},
        {"Orange", "0"},
        {"Peach", "0"},
        {"Brown", "0"},
        {"Bright Yellow", "0"}
        };

    public:
        AppState();
        ~AppState();
        
        void update();
        void draw();
        void reset();
        void keyPressed(int key);
		void keyReleased(int key);
        void mousePressed(int x, int y, int button);
        void resize(ofImage image, int width, int height);

        void changeFormat();
        void drawAssets();
        void updateSettings();

        ofColor closestCubeColor(ofColor color);
        void drawCubeAmounts();
        void drawCubeColor();

        void drawSquare(int x, int y, int size, ofColor color);
        void drawSquareArt();

        ofColor findHexAverage(int xCorner, int yCorner);
        void drawHex(int x, int y, int size, ofColor color);
        void drawHexArt();
};  
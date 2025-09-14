#pragma once
#include "ofMain.h"

class Button {
    private:
        int xPos;
        int yPos;
        int width;
        int height;
        string image;
    
    public:
        Button(int x, int y, int w, int h, string image);
        ~Button();

        float getXPos() {return xPos;}
        void setXPos(int newXPos) {xPos = newXPos;}
        void setImage(string newImage) {image = newImage;}

        void update();
        void draw();

        bool pressed(int mouseX, int mouseY);
};
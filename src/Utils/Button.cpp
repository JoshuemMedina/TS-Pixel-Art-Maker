#include "Button.h"

Button::Button(int xPos, int yPos, int width, int height, string image) {
    this->xPos = xPos;
    this->yPos = yPos;
    this->width = width;
    this->height = height;
    this->image = image;
}

void Button::update() {};

void Button::draw() {
    ofImage buttonImage;
    buttonImage.load(image);
    buttonImage.draw(xPos, yPos, width, height);
}

bool Button::pressed(int mouseX, int mouseY) {
    if ((mouseX > xPos) && (mouseX < xPos + width) && (mouseY > yPos) && (mouseY < yPos + height)) {
        return true;
    }
    return false;
}
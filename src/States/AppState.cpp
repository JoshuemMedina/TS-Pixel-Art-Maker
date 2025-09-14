#include "AppState.h"

AppState::AppState() {
    updateSettings();

    // Asset Load
    ofBackground(000000);

    background.load(ThemeManager::background);
    grayBar.load(ThemeManager::grayBar);
    grayBarActive.load(ThemeManager::grayBarActive);
    box1.load(ThemeManager::box1);
    box2.load(ThemeManager::box2);
    openedFile.load("");
    openedFileResized.load("");
    font.load("Jersey10-Regular.ttf", fontSize);

    // Buttons
    Button* fileOpen = new Button(margin, margin+200*2+115, buttonWidth, 70, ThemeManager::importFile);
    Button* chooseStyle = new Button(margin, margin+200, buttonWidth, 150, ThemeManager::buttonIsHex);
    Button* chooseSize = new Button(margin, margin, buttonWidth, 150, ThemeManager::buttonIsBig);

    Button* grayIntensity = new Button(graySliderPos, margin+200*2, 50, 50, ThemeManager::graySlider);

    Button* settingsButton = new Button(ofGetWidth()-margin, 0, margin, margin, ThemeManager::settings);

    Button* tutorialButton = new Button(margin, margin+resultImageWidth-75, buttonWidth, 75, "tutorial/TutorialButton.png");

    buttons.push_back(fileOpen);
    buttons.push_back(chooseStyle);
    buttons.push_back(chooseSize);
    buttons.push_back(grayIntensity);
    buttons.push_back(settingsButton);
    buttons.push_back(tutorialButton);
}

void AppState::update() {}

void AppState::draw() {
    drawAssets();

    ofSetColor(ofColor::white);

    // Draw Gray Slider
    if (canMoveGraySlider) {
        if (ofGetMouseX() <= margin) {buttons[3]->setXPos(margin-25);}
        else if (ofGetMouseX() >= margin+buttonWidth) {buttons[3]->setXPos(margin+buttonWidth-25);}
        else {buttons[3]->setXPos(ofGetMouseX()-25);}
    }

    // Draw Buttons
    for (Button* button: buttons) {
        if (button == buttons[5]) {if (isHexArt && Settings::settings["showTutorial"] == "1") {button->draw();}}
        else {button->draw();}
    }

    // Draw Pixelated Image
    for (unsigned int index = 0; index != colorCounts.size(); ++index) {colorCounts[index][1] = "0";}

    if (isHexArt) {drawHexArt();}
    else {drawSquareArt();}
    
    drawCubeAmounts();

    // Draw Pixel Color Text
    if (ofGetMouseX() >= resultImageX && ofGetMouseX() <= resultImageX+resultImageWidth &&
        ofGetMouseY() >= margin && ofGetMouseY() <= margin+resultImageWidth) {
        drawCubeColor();
    }
}

void AppState::reset() {
    // Asset Reset
    ThemeManager::updateImages();

    background.load(ThemeManager::background);
    grayBar.load(ThemeManager::grayBar);
    grayBarActive.load(ThemeManager::grayBarActive);
    box1.load(ThemeManager::box1);
    box2.load(ThemeManager::box2);
    
    buttons[0]->setImage(ThemeManager::importFile);
    buttons[3]->setImage(ThemeManager::graySlider);
    buttons[4]->setImage(ThemeManager::settings);

    // Song Reset
    Settings::readSettings();
    if (ThemeManager::appTheme != ThemeManager::settingsTheme) {
        SoundManager::loadSongs();
        SoundManager::playSong("song", true);
        ThemeManager::appTheme = ThemeManager::settingsTheme;
    }

    if (Settings::settings["playMusic"] == "0") {SoundManager::stopSong("song");}
    else if (ThemeManager::appMusic == 0) {
        SoundManager::loadSongs();
        SoundManager::playSong("song", true);
        ThemeManager::appMusic = 1;
    }
}

void AppState::keyPressed(int key) {}

void AppState::keyReleased(int key) {}

void AppState::mousePressed(int x, int y, int button) {
    // fileOpen
    if (buttons[0]->pressed(x, y)) {
        ofFileDialogResult path = ofSystemLoadDialog("Open an PNG");
        if (path.bSuccess) {
            string extension = ofFilePath::getFileExt(path.getPath());
            if (extension == "png") {
                openedFile.load(path.getPath());
                changeFormat();
                isFileOpened = true;
                showErrorFileType = false;
            } else {
                showErrorFileType = true;
                showErrorLoading = false;
            }
        } else {
            showErrorFileType = false;
            showErrorLoading = true;
        }
    }

    // chooseStyle
    if (buttons[1]->pressed(x, y)) {
        isHexArt = !isHexArt;
        changeFormat();
    }

    // chooseSize
    if (buttons[2]->pressed(x, y)) {
        isBigRoom = !isBigRoom;
        changeFormat();
    }

    // grayIntensity
    if (buttons[3]->pressed(x, y)) {canMoveGraySlider = !canMoveGraySlider;}
    else {canMoveGraySlider = false;}
    Settings::settings["graySliderPos"] = to_string(buttons[3]->getXPos());

    // settingsButton
    if (buttons[4]->pressed(x, y)) {
        Settings::readSettings();

        if(Settings::settings["theme"] == "0") {ThemeManager::appTheme = 0;}
        else if(Settings::settings["theme"] == "1") {ThemeManager::appTheme = 1;}
        else if(Settings::settings["theme"] == "2") {ThemeManager::appTheme = 2;}
        else {ThemeManager::appTheme = 0;}

        if (Settings::settings["playMusic"] == "0") {ThemeManager::appMusic = 0;}
        else {ThemeManager::appMusic = 1;}
        
        this->setNextState("Settings");
        this->setFinished(true);
    }

    // tutorialButton
    if (buttons[5]->pressed(x, y)) {
        this->setNextState("Tutorial");
        this->setFinished(true);
    }

    Settings::writeSettings();

    // Make Sound
    for (Button* button: buttons)
        {if (button->pressed(x, y) && Settings::settings["playSounds"] == "1") {SoundManager::playSong("buttonClick", false);}
    }
}

void AppState::resize(ofImage image, int width, int height) {};

// ============================== Custom Functions ==============================
void AppState::changeFormat() {
    if (isHexArt) {
        if (isBigRoom) {size[0] = 480; size[1] = 340;}
        else {size[0] = 192; size[1] = 196;}
        cubeColors = colors.averageColors;
    } else {
        if (isBigRoom) {size[0] = 30; size[1] = 30;}
        else {size[0] = 12; size[1] = 12;}
        cubeColors = colors.topSideColors;
    }

    // Write Settings
    // Repeat If cause it looks cleaner xd
    if (isHexArt) {Settings::settings["isHexArt"] = "1";}
    else {Settings::settings["isHexArt"] = "0";}
    if (isBigRoom) {Settings::settings["isBigRoom"] = "1";}
    else {Settings::settings["isBigRoom"] = "0";}
    Settings::writeSettings();

    openedFileResized = openedFile;
    openedFileResized.resize(size[0], size[1]);
}

void AppState::drawAssets() {
    // Draw Background
    ofSetColor(ofColor::white);
    for (int y = 0; y < 5; ++y) {
        for (int x = 6; x >= -1; --x) {
            background.draw(x*background.getWidth()+backGroundOffset, y*background.getHeight()-backGroundOffset,
                background.getWidth(), background.getHeight());
            if (ofGetFrameNum() % 2 == 0) {backGroundOffset += 0.1;}
            if (backGroundOffset >= background.getWidth()) {backGroundOffset = 0;}
        }
    }

    // Change Button Images
    if (isBigRoom) {buttons[2]->setImage(ThemeManager::buttonIsBig);}
    else {buttons[2]->setImage(ThemeManager::buttonIsSmall);}
    if (isHexArt) {buttons[1]->setImage(ThemeManager::buttonIsHex);}
    else {buttons[1]->setImage(ThemeManager::buttonIsSquare);}

    // Draw Static Images
    ofSetColor(ofColor::white);
    grayBar.draw(margin, margin+200*2, 300, 50);
    box1.draw(resultImageX-25, margin-25, resultImageWidth+50, resultImageWidth+50);
    box2.draw(resultImageX+resultImageWidth+margin-25, margin-25, buttonWidth+50, resultImageWidth+50);

    // Draw Button Texts
    font.drawString("Room Size", margin+buttonWidth/2-font.stringWidth("Room Size")/2, margin+150+fontSize);
    font.drawString("Art Type", margin+buttonWidth/2-font.stringWidth("Art Type")/2, margin+350+fontSize);

    // Draw Gray Intensity Text
    grayPercentage = (buttons[3]->getXPos()-(margin-25))/3;
    font.drawString("Gray Intensity: "+to_string(grayPercentage)+"%",
        margin+buttonWidth/2-font.stringWidth("Gray Intensity: 00%")/2, margin+200*2+50+fontSize);

    // Draw Gray Intensity Active Part
    grayBarActive.drawSubsection(margin, margin+200*2, 3*grayPercentage, 50, 0, 0, 6*grayPercentage, grayBarActive.getHeight());

    // Draw Error Text
    if (showErrorFileType) {font.drawString("Type not supported (Use PNG)",
        margin, margin+200*2+185+font.stringHeight("Type not supported (Use PNG)"));}
    if (showErrorLoading) {font.drawString("Error Loading Image",
        margin, margin+200*2+185+font.stringHeight("Error Loading Image"));}
}

void AppState::updateSettings() {
    Settings::readSettings();

    if (Settings::settings["saveSettings"] == "1") {
        if (Settings::settings["isBigRoom"] == "1") {isBigRoom = true;}
        else {isBigRoom = false;}

        if (Settings::settings["isHexArt"] == "1") {isHexArt = true;}
        else {isHexArt = false;}

        graySliderPos = stoi(Settings::settings["graySliderPos"]);
    }

    ThemeManager::updateImages();

    changeFormat();
}

// ---------- Cube Colors ----------

ofColor AppState::closestCubeColor(ofColor color) {
    ofColor closestColor = cubeColors[0];
    int closestColorDistance = 200000;
    int closestColorIndex = 0;

    for (unsigned int index = 0; index < cubeColors.size(); ++index) {
        int colorsDistance = pow(cubeColors[index].r-color.r, 2)+pow(cubeColors[index].g-color.g, 2)+pow(cubeColors[index].b-color.b, 2);

        grayIntensityPercentage = (colorsDistance*15)*(100-grayPercentage)/100;
        if (index < 12) {colorsDistance += grayIntensityPercentage;}

        if (colorsDistance < closestColorDistance) {
            closestColorDistance = colorsDistance;
            closestColor = cubeColors[index];
            closestColorIndex = index;
        }
    }
    colorCounts[closestColorIndex/4][1] = to_string(stoi(colorCounts[closestColorIndex/4][1])+1);
    return closestColor;
}

void AppState::drawCubeAmounts() {
    ofSetColor(ofColor::white);
    int offset = 0, invisAmount = 0;
    int x = resultImageX+resultImageWidth+margin;
    int y = margin+fontSize*2;
    if (isHexArt && isFileOpened) {
        if (isBigRoom) {invisAmount = 413;}
        else {invisAmount = 161;}
    }

    // Invisible Cube Outline
    ofDrawLine(x+10, y-fontSize-13, x+10, y-fontSize-9);
    ofDrawLine(x+10, y-fontSize-5, x+10, y-fontSize-1);
    ofDrawLine(x+10, y-fontSize+3, x+10, y-fontSize+7);

    ofDrawLine(x+30, y-fontSize-13, x+30, y-fontSize-9);
    ofDrawLine(x+30, y-fontSize-5, x+30, y-fontSize-1);
    ofDrawLine(x+30, y-fontSize+3, x+30, y-fontSize+7);

    ofDrawLine(x+10, y-fontSize-13, x+14, y-fontSize-13);
    ofDrawLine(x+18, y-fontSize-13, x+22, y-fontSize-13);
    ofDrawLine(x+26, y-fontSize-13, x+30, y-fontSize-13);

    ofDrawLine(x+10, y-fontSize+7, x+14, y-fontSize+7);
    ofDrawLine(x+18, y-fontSize+7, x+22, y-fontSize+7);
    ofDrawLine(x+26, y-fontSize+7, x+30, y-fontSize+7);

    font.drawString("Invisible (rec.):", x+40, y-fontSize+5);
    font.drawString(to_string(invisAmount), x+245, y-fontSize+5);

    // Normal Pixel Cube Colors
    for (unsigned int index = 0; index != colorCounts.size(); ++index) {
        ofSetColor(colors.topSideColors[index*4]);
        ofDrawRectangle(x+10, y+offset-13, 20, 20);
        ofSetColor(ofColor::black);
        ofNoFill();
        ofDrawRectangle(x+10, y+offset-13, 20, 20);
        ofFill();

        ofSetColor(ofColor::white);
        font.drawString(colorCounts[index][0]+":", x+40, y+offset+5);
        font.drawString(colorCounts[index][1], x+245, y+offset+5);
        offset += fontSize;
    }
}

void AppState::drawCubeColor() {
    ofImage screenGrab;
    screenGrab.grabScreen(ofGetMouseX(), ofGetMouseY(), 1, 1);
    ofColor pickedColor = screenGrab.getColor(0, 0);

    string color = colors.toString(pickedColor, cubeColors);
    int colorWidth = font.stringWidth(color);
    int colorHeight = font.stringHeight(color);

    ofSetColor(0, 0, 0, 100);
    ofDrawRectangle(ofGetMouseX()+25, ofGetMouseY()-colorHeight+fontSize/2-5, colorWidth+10, colorHeight+10);
    ofSetColor(ofColor::black);
    ofNoFill();
    ofDrawRectangle(ofGetMouseX()+25, ofGetMouseY()-colorHeight+fontSize/2-5, colorWidth+10, colorHeight+10);
    ofFill();

    ofSetColor(ofColor::white);
    font.drawString(color, ofGetMouseX()+30, ofGetMouseY()+fontSize/2);
}

// ---------- Square Art ----------

void AppState::drawSquare(int x, int y, int size, ofColor color) {
    if (color.a != 0) {
        ofSetColor(color);
        ofDrawRectangle((x*size)+resultImageX, (y*size)+margin, size, size);
    }

    // Outline
    ofSetColor(ofColor::black);
    ofNoFill();
    ofDrawRectangle((x*size)+resultImageX, (y*size)+margin, size, size);
    ofFill();
}

void AppState::drawSquareArt() {
    int pixelSize;
    if (isBigRoom) {pixelSize = resultImageWidth/30;}
    else {pixelSize = resultImageWidth/12;}

    for (int y = 0; y < openedFileResized.getHeight(); ++y) {
        for (int x = 0; x < openedFileResized.getWidth(); ++x) {
            ofColor pixelColor = openedFileResized.getColor(x, y);
            if (pixelColor.a >= 128) {pixelColor = closestCubeColor(pixelColor);}
            else {pixelColor = ofColor(0, 0, 0, 0);}
            drawSquare(x, y, pixelSize, pixelColor);
        }
    }
}

// ---------- Hex Art ----------

ofColor AppState::findHexAverage(int xCorner, int yCorner) {
    int red = 0, green = 0, blue = 0, alpha = 0;
    for (int y = yCorner; y < yCorner+16; ++y) {
        for (int x = xCorner; x < xCorner+16; ++x) {
            int xHex = x-xCorner;
            int yHex = (y-yCorner)*2;
            if (xHex+yHex >= 8 && xHex-yHex < 8 && xHex+yHex < 40 && xHex-yHex >= -24) {
                red += openedFileResized.getColor(x, y).r;
                green += openedFileResized.getColor(x, y).g;
                blue += openedFileResized.getColor(x, y).b;
                alpha += openedFileResized.getColor(x, y).a;
            }
        }
    }
    return ofColor(red/192, green/192, blue/192, alpha/192);
}

void AppState::drawHex(int x, int y, int size, ofColor color) {
    int offset = 0;
    if (y%2 != 0) {offset = size/2;}

    int totalOffset = (size/2)+(size*3/4)*5;
    if (!isBigRoom) {totalOffset = -size/4;}

    x = (x*size+offset)+resultImageX;
    y = (y*size*3/4)+margin+totalOffset;
    if (color.a != 0) {
        ofSetColor(color);
        ofDrawTriangle(x, y+(size/4), x+(size/2), y, x+(size), y+(size/4));
        ofDrawRectangle(x, y+(size/4), size, size/2);
        ofDrawTriangle(x, y+(size*3/4), x+(size/2), y+(size), x+(size), y+(size*3/4));
    }

    // Outline
    ofSetColor(ofColor::black);
    ofDrawLine(x, y+(size/4), x+(size/2), y);
    ofDrawLine(x+(size/2), y, x+(size), y+(size/4));
    ofDrawLine(x+(size), y+(size/4), x+(size), y+(size*3/4));
    ofDrawLine(x+(size), y+(size*3/4), x+(size/2), y+(size));
    ofDrawLine(x+(size/2), y+(size), x, y+(size*3/4));
    ofDrawLine(x, y+(size*3/4), x, y+(size/4));
}

void AppState::drawHexArt() {
    int pixelSize;
    int offset = 0;
    if (isBigRoom) {pixelSize = resultImageWidth/30;}
    else {pixelSize = resultImageWidth/12;}

    for (int y = 0; y < openedFileResized.getHeight(); ++y) {
        int yHexTile = y*12;
        if (yHexTile >= openedFileResized.getHeight()) {break;}

        if (y%2 == 0) {offset = 0;}
        else {offset = 8;}

        for (int x = 0; x < openedFileResized.getWidth(); ++x) {
            int xHexTile = (x*16)+offset;
            if (xHexTile+offset >= openedFileResized.getWidth()) {break;}

            if (xHexTile+2*yHexTile >= openedFileResized.getWidth()/2 &&
                xHexTile-2*yHexTile < openedFileResized.getWidth()/2 &&
                xHexTile+2*(yHexTile+12) < openedFileResized.getWidth()/2+2*openedFileResized.getHeight() &&
                xHexTile-2*(yHexTile+12) >= openedFileResized.getWidth()/2-2*openedFileResized.getHeight())
                {
                ofColor pixelColor;
                pixelColor = findHexAverage(xHexTile, yHexTile);
                if (pixelColor.a >= 128) {pixelColor = closestCubeColor(pixelColor);}
                else {pixelColor = ofColor(0, 0, 0, 0);}
                drawHex(x, y, pixelSize, pixelColor);
            }
        }
    }

    // Room Outline
    ofSetColor(ofColor::white);
    if (isFileOpened) {
        if (isBigRoom) {
            ofDrawLine(resultImageX, margin+pixelSize*12, resultImageX+resultImageWidth/2, margin+pixelSize*9/2);
            ofDrawLine(resultImageX+resultImageWidth/2, margin+pixelSize*9/2, resultImageX+resultImageWidth, margin+pixelSize*12);
            ofDrawLine(resultImageX+resultImageWidth, margin+pixelSize*12, resultImageX+resultImageWidth, margin+pixelSize*18);
            ofDrawLine(resultImageX+resultImageWidth, margin+pixelSize*18, resultImageX+resultImageWidth/2, margin+pixelSize*51/2);
            ofDrawLine(resultImageX+resultImageWidth/2, margin+pixelSize*51/2, resultImageX, margin+pixelSize*18);
            ofDrawLine(resultImageX, margin+pixelSize*18, resultImageX, margin+pixelSize*12);
        } else {
            ofDrawLine(resultImageX, margin+pixelSize*3, resultImageX+resultImageWidth/2, margin);
            ofDrawLine(resultImageX+resultImageWidth/2, margin, resultImageX+resultImageWidth, margin+pixelSize*3);
            ofDrawLine(resultImageX+resultImageWidth, margin+pixelSize*3, resultImageX+resultImageWidth, margin+pixelSize*9);
            ofDrawLine(resultImageX+resultImageWidth, margin+pixelSize*9, resultImageX+resultImageWidth/2, margin+resultImageWidth);
            ofDrawLine(resultImageX+resultImageWidth/2, margin+resultImageWidth, resultImageX, margin+pixelSize*9);
            ofDrawLine(resultImageX, margin+pixelSize*9, resultImageX, margin+pixelSize*3);
        }
    }
}
#include "SettingsState.h"

SettingsState::SettingsState() {
    updateSettings();

    // Asset Load
    ofBackground(000000);

    background.load("settings/Background.png");
    bar.load("settings/Bar.png");
    barActive.load("settings/BarActive.png");
    selectedTheme.load("settings/SelectedTheme.png");

    fontTitle.load("Jersey10-Regular.ttf", fontTitleSize);
    fontText.load("Jersey10-Regular.ttf", fontTextSize);

    // Buttons
    Button* returnButton = new Button(ofGetWidth()-margin, 0, margin, margin, "settings/Return.png");
    
    Button* saveSettings = new Button(margin, margin, buttonWidth, buttonWidth, "settings/Checked.png");

    Button* playAnimation = new Button(margin, margin+buttonWidth+separation, buttonWidth, buttonWidth, "settings/Checked.png");

    Button* showTutorial = new Button(ofGetWidth()/2, margin, buttonWidth, buttonWidth, "settings/Checked.png");

    Button* playMusic = new Button(margin, margin+buttonWidth*2+separation*2, buttonWidth, buttonWidth, "settings/Checked.png");
    Button* playSounds = new Button(ofGetWidth()/2, margin+buttonWidth*2+separation*2,
        buttonWidth, buttonWidth, "settings/Checked.png");

    Button* musicSlider = new Button(musicSliderPos, margin+buttonWidth*2+separation*2+fontTitleSize, 50, 50, "settings/Slider.png");
    Button* soundSlider = new Button(soundSliderPos, margin+buttonWidth*2+separation*2+fontTitleSize, 50, 50, "settings/Slider.png");

    Button* defaultTheme = new Button(margin, margin+buttonWidth*3+separation*3+50,
        buttonWidth+25, buttonWidth+25, "settings/DefaultTheme.png");
    Button* classicTheme = new Button(margin+buttonWidth+25+separation, margin+buttonWidth*3+separation*3+50,
        buttonWidth+25, buttonWidth+25, "settings/ClassicTheme.png");
    Button* factoryTheme = new Button(margin+(buttonWidth+25)*2+separation*2, margin+buttonWidth*3+separation*3+50,
        buttonWidth+25, buttonWidth+25, "settings/FactoryTheme.png");

    buttons.push_back(returnButton);
    buttons.push_back(saveSettings);
    buttons.push_back(playAnimation);
    buttons.push_back(playMusic);
    buttons.push_back(playSounds);
    buttons.push_back(musicSlider);
    buttons.push_back(soundSlider);
    buttons.push_back(defaultTheme);
    buttons.push_back(classicTheme);
    buttons.push_back(factoryTheme);
    buttons.push_back(showTutorial);
}

void SettingsState::update() {}

void SettingsState::draw() {
    ofSetColor(ofColor::white);

    // Draw Assets
    background.draw(0, 0, ofGetWidth(), ofGetHeight());
    bar.draw(margin+buttonWidth+75, margin+buttonWidth*2+separation*2+fontTitleSize, barSize, 50);
    bar.draw(ofGetWidth()/2+buttonWidth+75, margin+buttonWidth*2+separation*2+fontTitleSize, barSize, 50);

    barActive.drawSubsection(margin+buttonWidth+75, margin+buttonWidth*2+separation*2+fontTitleSize, 5*musicVolume, 50,
        0, 0, 5*musicVolume, barActive.getHeight());
    barActive.drawSubsection(ofGetWidth()/2+buttonWidth+75, margin+buttonWidth*2+separation*2+fontTitleSize, 5*soundVolume, 50,
        0, 0, 5*soundVolume, barActive.getHeight());

    // Draw Sliders
    if (canMoveMusicSlider) {
        if (ofGetMouseX() <= margin+buttonWidth+75) {buttons[5]->setXPos(margin+buttonWidth+50);}
        else if (ofGetMouseX() >= margin+buttonWidth+75+barSize) {buttons[5]->setXPos(margin+buttonWidth+50+barSize);}
        else {buttons[5]->setXPos(ofGetMouseX()-25);}
    }
    if (canMoveSoundSlider) {
        if (ofGetMouseX() <= ofGetWidth()/2+buttonWidth+75) {buttons[6]->setXPos(ofGetWidth()/2+buttonWidth+50);}
        else if (ofGetMouseX() >= ofGetWidth()/2+buttonWidth+75+barSize) {buttons[6]->setXPos(ofGetWidth()/2+buttonWidth+50+barSize);}
        else {buttons[6]->setXPos(ofGetMouseX()-25);}
    }

    // Draw Theme Selection
    if (Settings::settings["theme"] == "0") {selectedTheme.draw(margin-15, margin+buttonWidth*3+separation*3+35, 155, 155);}
    else if (Settings::settings["theme"] == "1") {selectedTheme.draw(margin+buttonWidth+25+separation-15,
        margin+buttonWidth*3+separation*3+35, 155, 155);}
    else if (Settings::settings["theme"] == "2") {selectedTheme.draw(margin+(buttonWidth+25)*2+separation*2-15,
        margin+buttonWidth*3+separation*3+35, 155, 155);}

    // Draw Buttons
    for (Button* button: buttons) {button->draw();}

    updateButtons();

    // Draw Strings
    drawStrings();
}

void SettingsState::reset() {}

void SettingsState::keyPressed(int key) {}

void SettingsState::keyReleased(int key) {}

void SettingsState::mousePressed(int x, int y, int button) {
    // returnButton
    if (buttons[0]->pressed(x, y)) {
        this->setNextState("App");
        this->setFinished(true);
    }

    // saveSettings
    if (buttons[1]->pressed(x, y)) {
        saveSettings = !saveSettings;
        if (saveSettings) {Settings::settings["saveSettings"] = "1";}
        else {Settings::settings["saveSettings"] = "0";}
    }

    // playAnimation
    if (buttons[2]->pressed(x, y)) {
        playAnimation = !playAnimation;
        if (playAnimation) {Settings::settings["playAnimation"] = "1";}
        else {Settings::settings["playAnimation"] = "0";}
    }

    // playMusic
    if (buttons[3]->pressed(x, y)) {
        playMusic = !playMusic;
        if (playMusic) {
            Settings::settings["playMusic"] = "1";
        } else {
            Settings::settings["playMusic"] = "0";
        }
    }

    // playSounds
    if (buttons[4]->pressed(x, y)) {
        playSounds = !playSounds;
        if (playSounds) {Settings::settings["playSounds"] = "1";}
        else {Settings::settings["playSounds"] = "0";}
    }

    // musicSlider
    if (buttons[5]->pressed(x, y)) {canMoveMusicSlider = !canMoveMusicSlider;}
    else {canMoveMusicSlider = false;}
    SoundManager::setVolume("song", (buttons[5]->getXPos()-(margin+buttonWidth+50))/500);
    Settings::settings["musicVolume"] = to_string(buttons[5]->getXPos());

    // soundSlider
    if (buttons[6]->pressed(x, y)) {canMoveSoundSlider = !canMoveSoundSlider;}
    else {canMoveSoundSlider = false;}
    SoundManager::setVolume("buttonClick", (buttons[6]->getXPos()-(ofGetWidth()/2+buttonWidth+50))/500);
    Settings::settings["soundVolume"] = to_string(buttons[6]->getXPos());

    // defaultTheme
    if (buttons[7]->pressed(x, y)) {
        Settings::settings["theme"] = "0";
        ThemeManager::settingsTheme = 0;
    }

    // classicTheme
    if (buttons[8]->pressed(x, y)) {
        Settings::settings["theme"] = "1";
        ThemeManager::settingsTheme = 1;
    }

    // factoryTheme
    if (buttons[9]->pressed(x, y)) {
        Settings::settings["theme"] = "2";
        ThemeManager::settingsTheme = 2;
    }

    // showTutorial
    if (buttons[10]->pressed(x, y)) {
        showTutorial = !showTutorial;
        if (showTutorial) {Settings::settings["showTutorial"] = "1";}
        else {Settings::settings["showTutorial"] = "0";}
    }

    Settings::writeSettings();

    // Make Sound
    for (Button* button: buttons)
        {if (button->pressed(x, y) && Settings::settings["playSounds"] == "1") {SoundManager::playSong("buttonClick", false);}
    }
}

// ============================== Custom Functions ==============================
void SettingsState::drawStrings() {
    int xpos = margin+buttonWidth+25;

    fontTitle.drawString("Save Format Settings", xpos, margin+fontTitle.stringHeight("Save Format Settings"));
    fontText.drawString("Save the size and art style between sessions", xpos,
        margin+fontTitle.stringHeight("Save the size and art style between sessions")*2);
    
    fontTitle.drawString("Play Animation", xpos, margin+buttonWidth+separation+fontTitle.stringHeight("Play Animation"));
    fontText.drawString("If disabled, it will skip the start-up animation", xpos,
        margin+buttonWidth+separation+fontTitle.stringHeight("If disabled, it will skip the start-up animation")*2);

    fontTitle.drawString("Show Hex Art Tutorial", ofGetWidth()/2+buttonWidth+25, margin+fontTitle.stringHeight("Show Hex Art Tutorial"));
    fontText.drawString("Shows the Tutorial button whenever the art is Hex", ofGetWidth()/2+buttonWidth+25,
        margin+fontTitle.stringHeight("Shows the Tutorial button whenever the art is Hex")*2);
    
    musicVolume = (buttons[5]->getXPos()-(margin+buttonWidth+50))/5;
    fontTitle.drawString("Music: "+to_string(musicVolume)+"%", xpos, margin+buttonWidth*2+separation*2+fontTitle.stringHeight("Music"));
    soundVolume = (buttons[6]->getXPos()-(ofGetWidth()/2+buttonWidth+50))/5;
    fontTitle.drawString("SFX: "+to_string(soundVolume)+"%", ofGetWidth()/2+buttonWidth+25,
        margin+buttonWidth*2+separation*2+fontTitle.stringHeight("SFX"));
    
    fontTitle.drawString("Themes", margin, margin+buttonWidth*3+separation*3+fontText.stringHeight("Themes"));

    fontText.drawString("Default", margin+(buttonWidth+25)*1/2-fontText.stringWidth("Default")/2,
        margin+buttonWidth*4+separation*3+95+fontTitle.stringHeight("Default"));
    fontText.drawString("Classic", margin+(buttonWidth+25)*3/2+separation-fontText.stringWidth("Classic")/2,
        margin+buttonWidth*4+separation*3+95+fontTitle.stringHeight("Classic"));
    fontText.drawString("Factory", margin+(buttonWidth+25)*5/2+separation*2-fontText.stringWidth("Factory")/2,
        margin+buttonWidth*4+separation*3+95+fontTitle.stringHeight("Factory"));
}

void SettingsState::updateSettings() {
    Settings::readSettings();

    if (Settings::settings["saveSettings"] == "0") {saveSettings = false;}
    if (Settings::settings["playAnimation"] == "0") {playAnimation = false;}
    if (Settings::settings["playMusic"] == "0") {playMusic = false;}
    if (Settings::settings["playSounds"] == "0") {playSounds = false;}

    musicSliderPos = stoi(Settings::settings["musicVolume"]);
    soundSliderPos = stoi(Settings::settings["soundVolume"]);

    ThemeManager::updateImages();
}

void SettingsState::updateButtons() {
    if (saveSettings) {buttons[1]->setImage("settings/Checked.png");}
    else {buttons[1]->setImage("settings/Unchecked.png");}

    if (playAnimation) {buttons[2]->setImage("settings/Checked.png");}
    else {buttons[2]->setImage("settings/Unchecked.png");}

    if (showTutorial) {buttons[10]->setImage("settings/Checked.png");}
    else {buttons[10]->setImage("settings/Unchecked.png");}

    if (playMusic) {buttons[3]->setImage("settings/Checked.png");}
    else {buttons[3]->setImage("settings/Unchecked.png");}

    if (playSounds) {buttons[4]->setImage("settings/Checked.png");}
    else {buttons[4]->setImage("settings/Unchecked.png");}
}
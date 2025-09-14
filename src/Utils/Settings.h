#pragma once
#include "ofMain.h"
#include <fstream>
using namespace std;

class Settings {
    public:
        inline static map<string, string> settings {
            {"saveSettings", "1"},
            {"isBigRoom", "1"},
            {"isHexArt", "1"},
            {"graySliderPos", "375"},
            {"playAnimation", "1"},
            {"showTutorial", "1"},
            {"playMusic", "1"},
            {"playSounds", "1"},
            {"musicVolume", "750"},
            {"soundVolume", "1510"},
            {"theme", "0"}
        };

        static void writeSettings() {
            ofstream settingsFile("Settings.txt");
            if (settingsFile.is_open()) {
                for (const auto& pair: settings) {settingsFile << pair.first << "=" << pair.second << endl;}
                settingsFile.close();
            }
        }

        static void readSettings() {
            ifstream settingsFile("Settings.txt");
            if (settingsFile.is_open()) {
                string line;
                while (getline(settingsFile, line)) {
                    auto equalPos = line.find("=");
                    if (equalPos != string::npos) {
                        string key = line.substr(0, equalPos);
                        string value = line.substr(equalPos+1);
                        settings[key] = value;
                    }
                }
                settingsFile.close();
            }
        }
};
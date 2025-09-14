#pragma once
#include "ofMain.h"

class ThemeManager {
    public:
        inline static string background;
        inline static string box1;
        inline static string box2;

        inline static string buttonIsBig;
        inline static string buttonIsSmall;
        inline static string buttonIsHex;
        inline static string buttonIsSquare;

        inline static string importFile;

        inline static string grayBar;
        inline static string grayBarActive;
        inline static string graySlider;

        inline static string settings;

        // Music Playing Logic
        inline static int appTheme = 0;
        inline static int settingsTheme = 0;

        inline static int appMusic = 0;

        // Test
        inline static string white;

        // Functions
        static void updateImages() {
            Settings::readSettings();

            background = "themes/"+Settings::settings["theme"]+"/Background.png";
            box1 = "themes/"+Settings::settings["theme"]+"/Box1.png";
            box2 = "themes/"+Settings::settings["theme"]+"/Box2.png";

            buttonIsBig = "themes/"+Settings::settings["theme"]+"/ButtonIsBig.png";
            buttonIsSmall = "themes/"+Settings::settings["theme"]+"/ButtonIsSmall.png";
            buttonIsHex = "themes/"+Settings::settings["theme"]+"/ButtonIsHex.png";
            buttonIsSquare = "themes/"+Settings::settings["theme"]+"/ButtonIsSquare.png";

            importFile = "themes/"+Settings::settings["theme"]+"/ImportFile.png";

            grayBar = "themes/"+Settings::settings["theme"]+"/GrayBar.png";
            grayBarActive = "themes/"+Settings::settings["theme"]+"/GrayBarActive.png";
            graySlider = "themes/"+Settings::settings["theme"]+"/GraySlider.png";

            white = "themes/"+Settings::settings["theme"]+"/White.png";

            settings = "themes/"+Settings::settings["theme"]+"/Settings.png";
        }
};
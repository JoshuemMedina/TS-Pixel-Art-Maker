#pragma once
#include "ofMain.h"
#include <vector>

class Colors {
    public:
// ---------- Top Side Colors ----------    
    ofColor
    BLACK0 = ofColor(91, 91, 91),
    BLACK1 = ofColor(66, 66, 66),
    BLACK2 = ofColor(48, 48, 48),
    BLACK3 = ofColor(23, 23, 23),

    GRAY0 = ofColor(157, 157, 157),
    GRAY1 = ofColor(116, 116, 116),
    GRAY2 = ofColor(85, 85, 85),
    GRAY3 = ofColor(62, 62, 62),

    WHITE0 = ofColor(255, 255, 255),
    WHITE1 = ofColor(221, 221, 221),
    WHITE2 = ofColor(191, 191, 191),
    WHITE3 = ofColor(162, 162, 162),

    CORAL0 = ofColor(255, 83, 131),
    CORAL1 = ofColor(255, 61, 96),
    CORAL2 = ofColor(222, 77, 94),
    CORAL3 = ofColor(195, 64, 73),

    RED0 = ofColor(227, 32, 54),
    RED1 = ofColor(190, 23, 39),
    RED2 = ofColor(146, 17, 28),
    RED3 = ofColor(107, 12, 20),

    MAGENTA0 = ofColor(229, 31, 154),
    MAGENTA1 = ofColor(193, 23, 113),
    MAGENTA2 = ofColor(149, 17, 82),
    MAGENTA3 = ofColor(109, 12, 60),

    PINK0 = ofColor(255, 126, 249),
    PINK1 = ofColor(255, 92, 233),
    PINK2 = ofColor(219, 76, 200),
    PINK3 = ofColor(157, 50, 137),

    PURPLE0 = ofColor(171, 36, 255),
    PURPLE1 = ofColor(128, 26, 255),
    PURPLE2 = ofColor(114, 75, 199),
    PURPLE3 = ofColor(98, 64, 175),

    BLUE0 = ofColor(36, 157, 242),
    BLUE1 = ofColor(26, 116, 216),
    BLUE2 = ofColor(19, 85, 175),
    BLUE3 = ofColor(14, 62, 131),

    LIGHTBLUE0 = ofColor(48, 210, 255),
    LIGHTBLUE1 = ofColor(35, 168, 255),
    LIGHTBLUE2 = ofColor(58, 129, 223),
    LIGHTBLUE3 = ofColor(62, 107, 211),

    CYAN0 = ofColor(48, 251, 255),
    CYAN1 = ofColor(35, 239, 255),
    CYAN2 = ofColor(53, 192, 227),
    CYAN3 = ofColor(70, 154, 203),

    TURQUOISE0 = ofColor(32, 227, 165),
    TURQUOISE1 = ofColor(23, 190, 123),
    TURQUOISE2 = ofColor(17, 146, 90),
    TURQUOISE3 = ofColor(12, 107, 66),

    SEAGREEN0 = ofColor(33, 219, 135),
    SEAGREEN1 = ofColor(24, 179, 99),
    SEAGREEN2 = ofColor(18, 135, 72),
    SEAGREEN3 = ofColor(13, 99, 53),

    LIMEGREEN0 = ofColor(70, 233, 73),
    LIMEGREEN1 = ofColor(51, 199, 53),
    LIMEGREEN2 = ofColor(37, 155, 39),
    LIMEGREEN3 = ofColor(27, 114, 28),

    GOLDYELLOW0 = ofColor(233, 214, 70),
    GOLDYELLOW1 = ofColor(199, 172, 51),
    GOLDYELLOW2 = ofColor(155, 129, 37),
    GOLDYELLOW3 = ofColor(114, 94, 27),

    ORANGE0 = ofColor(255, 103, 48),
    ORANGE1 = ofColor(241, 73, 21),
    ORANGE2 = ofColor(205, 61, 17),
    ORANGE3 = ofColor(164, 45, 13),

    PEACH0 = ofColor(255, 170, 126),
    PEACH1 = ofColor(255, 127, 92),
    PEACH2 = ofColor(255, 93, 67),
    PEACH3 = ofColor(255, 68, 49),

    BROWN0 = ofColor(170, 89, 60),
    BROWN1 = ofColor(127, 65, 44),
    BROWN2 = ofColor(93, 47, 32),
    BROWN3 = ofColor(68, 34, 23),

    BRIGHTYELLOW0 = ofColor(253, 245, 84),
    BRIGHTYELLOW1 = ofColor(246, 224, 63),
    BRIGHTYELLOW2 = ofColor(225, 186, 46),
    BRIGHTYELLOW3 = ofColor(206, 158, 27);

    vector<ofColor> topSideColors = {
    BLACK0, BLACK1, BLACK2, BLACK3,
    GRAY0, GRAY1, GRAY2, GRAY3,
    WHITE0, WHITE1, WHITE2, WHITE3,
    CORAL0, CORAL1, CORAL2, CORAL3,
    RED0, RED1, RED2, RED3,
    MAGENTA0, MAGENTA1, MAGENTA2, MAGENTA3,
    PINK0, PINK1, PINK2, PINK3,
    PURPLE0, PURPLE1, PURPLE2, PURPLE3,
    BLUE0, BLUE1, BLUE2, BLUE3,
    LIGHTBLUE0, LIGHTBLUE1, LIGHTBLUE2, LIGHTBLUE3,
    CYAN0, CYAN1, CYAN2, CYAN3,
    TURQUOISE0, TURQUOISE1, TURQUOISE2, TURQUOISE3,
    SEAGREEN0, SEAGREEN1, SEAGREEN2, SEAGREEN3,
    LIMEGREEN0, LIMEGREEN1, LIMEGREEN2, LIMEGREEN3,
    GOLDYELLOW0, GOLDYELLOW1, GOLDYELLOW2, GOLDYELLOW3,
    ORANGE0, ORANGE1, ORANGE2, ORANGE3,
    PEACH0, PEACH1, PEACH2, PEACH3,
    BROWN0, BROWN1, BROWN2, BROWN3,
    BRIGHTYELLOW0, BRIGHTYELLOW1, BRIGHTYELLOW2, BRIGHTYELLOW3
    };

// ---------- Average Colors ----------
    ofColor
    BLACK0average = ofColor(57, 57, 57),
    BLACK1average = ofColor(42, 42, 42),
    BLACK2average = ofColor(30, 30, 30),
    BLACK3average = ofColor(22, 22, 22),

    GRAY0average = ofColor(114, 114, 114),
    GRAY1average = ofColor(83, 83, 83),
    GRAY2average = ofColor(61, 61, 61),
    GRAY3average = ofColor(44, 44, 44),

    WHITE0average = ofColor(221, 221, 221),
    WHITE1average = ofColor(182, 182, 182),
    WHITE2average = ofColor(145, 145, 145),
    WHITE3average = ofColor(113, 113, 113),

    CORAL0average = ofColor(221, 49, 100),
    CORAL1average = ofColor(196, 36, 73),
    CORAL2average = ofColor(159, 37, 62),
    CORAL3average = ofColor(138, 41, 56),

    RED0average = ofColor(189, 18, 27),
    RED1average = ofColor(149, 13, 20),
    RED2average = ofColor(112, 10, 14),
    RED3average = ofColor(82, 7, 10),

    MAGENTA0average = ofColor(190, 18, 124),
    MAGENTA1average = ofColor(150, 13, 90),
    MAGENTA2average = ofColor(113, 10, 66),
    MAGENTA3average = ofColor(83, 7, 48),

    PINK0average = ofColor(210, 102, 240),
    PINK1average = ofColor(196, 75, 216),
    PINK2average = ofColor(156, 57, 179),
    PINK3average = ofColor(113, 40, 131),

    PURPLE0average = ofColor(140, 20, 198),
    PURPLE1average = ofColor(104, 14, 171),
    PURPLE2average = ofColor(77, 43, 116),
    PURPLE3average = ofColor(72, 42, 106),

    BLUE0average = ofColor(20, 121, 194),
    BLUE1average = ofColor(14, 89, 158),
    BLUE2average = ofColor(11, 66, 122),
    BLUE3average = ofColor(48, 48, 90),

    LIGHTBLUE0average = ofColor(150, 167, 206),
    LIGHTBLUE1average = ofColor(12, 128, 179),
    LIGHTBLUE2average = ofColor(20, 96, 144),
    LIGHTBLUE3average = ofColor(21, 74, 121),

    CYAN0average = ofColor(16, 204, 204),
    CYAN1average = ofColor(12, 173, 177),
    CYAN2average = ofColor(18, 134, 144),
    CYAN3average = ofColor(24, 102, 117),

    TURQUOISE0average = ofColor(18, 189, 145),
    TURQUOISE1average = ofColor(13, 149, 107),
    TURQUOISE2average = ofColor(10, 112, 79),
    TURQUOISE3average = ofColor(7, 82, 58),

    SEAGREEN0average = ofColor(18, 178, 107),
    SEAGREEN1average = ofColor(13, 138, 78),
    SEAGREEN2average = ofColor(10, 103, 57),
    SEAGREEN3average = ofColor(7, 75, 42),

    LIMEGREEN0average = ofColor(29, 193, 29),
    LIMEGREEN1average = ofColor(22, 154, 21),
    LIMEGREEN2average = ofColor(16, 116, 16),
    LIMEGREEN3average = ofColor(12, 85, 11),

    GOLDYELLOW0average = ofColor(193, 171, 28),
    GOLDYELLOW1average = ofColor(154, 132, 21),
    GOLDYELLOW2average = ofColor(116, 97, 15),
    GOLDYELLOW3average = ofColor(85, 71, 11),

    ORANGE0average = ofColor(205, 64, 16),
    ORANGE1average = ofColor(174, 46, 7),
    ORANGE2average = ofColor(161, 39, 57),
    ORANGE3average = ofColor(124, 29, 5),

    PEACH0average = ofColor(242, 128, 102),
    PEACH1average = ofColor(223, 94, 75),
    PEACH2average = ofColor(197, 69, 54),
    PEACH3average = ofColor(170, 50, 40),

    BROWN0average = ofColor(134, 59, 34),
    BROWN1average = ofColor(99, 43, 25),
    BROWN2average = ofColor(73, 31, 18),
    BROWN3average = ofColor(53, 23, 13),

    BRIGHTYELLOW0average = ofColor(238, 216, 31),
    BRIGHTYELLOW1average = ofColor(216, 184, 24),
    BRIGHTYELLOW2average = ofColor(182, 145, 17),
    BRIGHTYELLOW3average = ofColor(154, 113, 10);

    vector<ofColor> averageColors = {
    BLACK0average, BLACK1average, BLACK2average, BLACK3average,
    GRAY0average, GRAY1average, GRAY2average, GRAY3average,
    WHITE0average, WHITE1average, WHITE2average, WHITE3average,
    CORAL0average, CORAL1average, CORAL2average, CORAL3average,
    RED0average, RED1average, RED2average, RED3average,
    MAGENTA0average, MAGENTA1average, MAGENTA2average, MAGENTA3average,
    PINK0average, PINK1average, PINK2average, PINK3average,
    PURPLE0average, PURPLE1average, PURPLE2average, PURPLE3average,
    BLUE0average, BLUE1average, BLUE2average, BLUE3average,
    LIGHTBLUE0average, LIGHTBLUE1average, LIGHTBLUE2average, LIGHTBLUE3average,
    CYAN0average, CYAN1average, CYAN2average, CYAN3average,
    TURQUOISE0average, TURQUOISE1average, TURQUOISE2average, TURQUOISE3average,
    SEAGREEN0average, SEAGREEN1average, SEAGREEN2average, SEAGREEN3average,
    LIMEGREEN0average, LIMEGREEN1average, LIMEGREEN2average, LIMEGREEN3average,
    GOLDYELLOW0average, GOLDYELLOW1average, GOLDYELLOW2average, GOLDYELLOW3average,
    ORANGE0average, ORANGE1average, ORANGE2average, ORANGE3average,
    PEACH0average, PEACH1average, PEACH2average, PEACH3average,
    BROWN0average, BROWN1average, BROWN2average, BROWN3average,
    BRIGHTYELLOW0average, BRIGHTYELLOW1average, BRIGHTYELLOW2average, BRIGHTYELLOW3average
    };

// ============================== Custom Functions ==============================
    string toString(ofColor color, vector<ofColor> colorList) {
        string output;
        int cubeIndex = -1;
        int cubeRotation = -1;
        for (unsigned int index = 0; index <= colorList.size(); ++index) {
            if (color == colorList[index]) {
                cubeIndex = index/4;
                cubeRotation = index%4;
                break;
            }
        }
        switch(cubeIndex) {
            case 0: output = "Black"; break;
            case 1: output = "Gray"; break;
            case 2: output = "White"; break;
            case 3: output = "Coral"; break;
            case 4: output = "Red"; break;
            case 5: output = "Magenta"; break;
            case 6: output = "Pink"; break;
            case 7: output = "Purple"; break;
            case 8: output = "Blue"; break;
            case 9: output = "Light Blue"; break;
            case 10: output = "Cyan"; break;
            case 11: output = "Turquoise"; break;
            case 12: output = "Sea Green"; break;
            case 13: output = "Lime Green"; break;
            case 14: output = "Gold Yellow"; break;
            case 15: output = "Orange"; break;
            case 16: output = "Peach"; break;
            case 17: output = "Brown"; break;
            case 18: output = "Bright Yellow"; break;
            default: return "";
        }
        string addPlural = "s";
        if (cubeRotation == 1) {addPlural = "";}
        if (cubeRotation > 0) {output += ": "+to_string(cubeRotation)+" Rotation"+addPlural;}
        return output;
    }
};
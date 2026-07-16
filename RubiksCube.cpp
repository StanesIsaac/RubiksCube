//
// Created by Stanes Isaac on 17-07-2026.
//

#include "RubiksCube.h"

char RubiksCube::getColorLetter(COLOR c) {
    switch(c){
        case COLOR::GREEN:
            return 'G';
        case COLOR::BLUE:
            return 'B';
        case COLOR::RED:
            return 'R';
        case COLOR::YELLOW:
            return 'Y';
        case COLOR::ORANGE:
            return 'O';
    }
    return 'W';
}
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

void RubiksCube::print() const {

    for (int row = 0; row < 3; row++) {
        for (int i=0;i<9;i++) cout<<" ";
        for (int col = 0; col < 3; col++) {
            cout << getColorLetter(getColor(FACE(0),row,col))<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';

    for (int row = 0; row < 3; row++) {
        for (int face = 1; face < 5; face++) {
            for (int col = 0; col < 3; col++) {
                cout << getColorLetter(getColor(FACE(face),row,col))<<" ";
            }
            for (int i=0;i<3;i++) cout<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    for (int row = 0; row < 3; row++) {
        for (int i=0;i<9;i++) cout<<" ";
        for (int col = 0; col < 3; col++) {
            cout << getColorLetter(getColor(FACE(5),row,col))<<" ";
        }
        cout<<'\n';
    }
}
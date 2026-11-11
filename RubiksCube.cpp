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

RubiksCube &RubiksCube::move(MOVE m) {
    switch (m) {
        case MOVE::U:
            return this->u();
        case MOVE::D:
            return this->d();
        case MOVE::L:
            return this->l();
        case MOVE::R:
            return this->r();
        case MOVE::F:
            return this->f();
        case MOVE::B:
            return this->b();

        case MOVE::L2:
            return this->l2();
        case MOVE::R2:
            return this->r2();
        case MOVE::F2:
            return this->f2();
        case MOVE::D2:
            return this->d2();
        case MOVE::U2:
            return this->u2();
        case MOVE::B2:
            return this->b2();
        case MOVE::LPRIME:
            return this->lPrime();
        case MOVE::RPRIME:
            return this->rPrime();
        case MOVE::FPRIME:
            return this->fPrime();
        case MOVE::DPRIME:
            return this->dPrime();
        case MOVE::UPRIME:
            return this->uPrime();
        case MOVE::BPRIME:
            return this->bPrime();
        default:
            return this->uPrime();
    }
}

RubiksCube& RubiksCube::revert(MOVE m) {
    switch (m) {
        case MOVE::U:
            return this->uPrime();
        case MOVE::D:
            return this->dPrime();
        case MOVE::L:
            return this->lPrime();
        case MOVE::R:
            return this->rPrime();
        case MOVE::F:
            return this->fPrime();
        case MOVE::B:
            return this->bPrime();

        case MOVE::L2:
            return this->l2();
        case MOVE::R2:
            return this->r2();
        case MOVE::F2:
            return this->f2();
        case MOVE::D2:
            return this->d2();
        case MOVE::U2:
            return this->u2();
        case MOVE::B2:
            return this->b2();
        case MOVE::LPRIME:
            return this->l();
        case MOVE::RPRIME:
            return this->r();
        case MOVE::FPRIME:
            return this->f();
        case MOVE::DPRIME:
            return this->d();
        case MOVE::UPRIME:
            return this->u();
        case MOVE::BPRIME:
            return this->b();

        default:
            return this->uPrime();
    }
}

string RubiksCube::getMove(MOVE ind) {
    switch (ind) {
        case MOVE::L:
            return "L";
        case MOVE::LPRIME:
            return "L'";
        case MOVE::L2:
            return "L2";
        case MOVE::R:
            return "R";
        case MOVE::RPRIME:
            return "R'";
        case MOVE::R2:
            return "R2";
        case MOVE::U:
            return "U";
        case MOVE::UPRIME:
            return "U'";
        case MOVE::U2:
            return "U2";
        case MOVE::D:
            return "D";
        case MOVE::DPRIME:
            return "D'";
        case MOVE::D2:
            return "D2";
        case MOVE::F:
            return "F";
        case MOVE::FPRIME:
            return "F'";
        case MOVE::F2:
            return "F2";
        case MOVE::B:
            return "B";
        case MOVE::BPRIME:
            return "B'";
        case MOVE::B2:
            return "B2";

        default:
            return "";
    }
}

vector<RubiksCube::MOVE> RubiksCube::randomShuffleCube(unsigned int times) {
    vector<RubiksCube::MOVE> mvs;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 17);
    for (unsigned int i = 0; i < times; i++) {
        unsigned int selectMove = (dist(gen));
        mvs.push_back(static_cast<MOVE>(selectMove));
        this->move(static_cast<MOVE>(selectMove));
    }
    return mvs;
}

string RubiksCube::getCornerColorString(uint8_t ind) const {
    string str = "";

    switch (ind) {
//        UFR
        case 0:
            str += getColorLetter(getColor(FACE::UP, 2, 2));
            str += getColorLetter(getColor(FACE::FRONT, 0, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 0));
            break;

//            UFL
        case 1:
            str += getColorLetter(getColor(FACE::UP, 2, 0));
            str += getColorLetter(getColor(FACE::FRONT, 0, 0));
            str += getColorLetter(getColor(FACE::LEFT, 0, 2));
            break;

//            UBL
        case 2:
            str += getColorLetter(getColor(FACE::UP, 0, 0));
            str += getColorLetter(getColor(FACE::BACK, 0, 2));
            str += getColorLetter(getColor(FACE::LEFT, 0, 0));
            break;

//            UBR
        case 3:
            str += getColorLetter(getColor(FACE::UP, 0, 2));
            str += getColorLetter(getColor(FACE::BACK, 0, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 2));
            break;

//            DFR
        case 4:
            str += getColorLetter(getColor(FACE::DOWN, 0, 2));
            str += getColorLetter(getColor(FACE::FRONT, 2, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 0));
            break;

//            DFL
        case 5:
            str += getColorLetter(getColor(FACE::DOWN, 0, 0));
            str += getColorLetter(getColor(FACE::FRONT, 2, 0));
            str += getColorLetter(getColor(FACE::LEFT, 2, 2));
            break;

//            DBR
        case 6:
            str += getColorLetter(getColor(FACE::DOWN, 2, 2));
            str += getColorLetter(getColor(FACE::BACK, 2, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 2));
            break;

//            DBL
        case 7:
            str += getColorLetter(getColor(FACE::DOWN, 2, 0));
            str += getColorLetter(getColor(FACE::BACK, 2, 2));
            str += getColorLetter(getColor(FACE::LEFT, 2, 0));
            break;
    }
    return str;
}

uint8_t RubiksCube::getCornerIndex(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    uint8_t ret = 0;
    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        if (c == 'Y') {
            ret |= (1 << 2);
        }
    }

    for (auto c: corner) {
        if (c != 'R' && c != 'O') continue;
        if (c == 'O') {
            ret |= (1 << 1);
        }
    }

    for (auto c: corner) {
        if (c != 'B' && c != 'G') continue;
        if (c == 'G') {
            ret |= (1 << 0);
        }
    }
    return ret;
}

uint8_t RubiksCube::getCornerOrientation(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    string actual_str = "";

    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        actual_str.push_back(c);
    }

    if (corner[1] == actual_str[0]) {
        return 1;
    } else if (corner[2] == actual_str[0]) {
        return 2;
    } else return 0;
}
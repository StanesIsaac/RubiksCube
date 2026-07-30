//
// Created by Stanes Isaac on 15-07-2026.
//

#ifndef RUBIKSCUBE_RUBIKSCUBE_H
#define RUBIKSCUBE_RUBIKSCUBE_H

#include <bits/stdc++.h>
using namespace std;

class RubiksCube {
    public:
    virtual ~RubiksCube() = default;

    enum class FACE {
        UP,LEFT,FRONT,RIGHT,BACK,DOWN
    };
    enum class COLOR {
        WHITE,GREEN,RED,BLUE,ORANGE,YELLOW
    };
    enum class MOVE {
        L,R,U,D,F,B,
        L2,R2,U2,D2,F2,B2,
        LPRIME,RPRIME,UPRIME,DPRIME,FPRIME,BPRIME,
    };

    virtual bool isSolved() const=0; // to check if the cube is solved
    void print()const; // to print the cube
    vector<MOVE> randomShuffleCube(unsigned int time); // to randomly shuffle the cube
    static char getColorLetter(COLOR c);
    virtual COLOR getColor(FACE face,int row,int col) const = 0;
    RubiksCube& move(MOVE m);
    RubiksCube& revert(MOVE m);
    static string getMove(MOVE m);

    virtual RubiksCube& l() = 0;
    virtual RubiksCube& r() = 0;
    virtual RubiksCube& u() = 0;
    virtual RubiksCube& d() = 0;
    virtual RubiksCube& f() = 0;
    virtual RubiksCube& b() = 0;

    virtual RubiksCube& l2() = 0;
    virtual RubiksCube& r2() = 0;
    virtual RubiksCube& u2() = 0;
    virtual RubiksCube& d2() = 0;
    virtual RubiksCube& f2() = 0;
    virtual RubiksCube& b2() = 0;

    virtual RubiksCube& lPrime() = 0;
    virtual RubiksCube& rPrime() = 0;
    virtual RubiksCube& uPrime() = 0;
    virtual RubiksCube& dPrime() = 0;
    virtual RubiksCube& bPrime() = 0;
    virtual RubiksCube& fPrime() = 0;
};

#endif //RUBIKSCUBE_RUBIKSCUBE_H

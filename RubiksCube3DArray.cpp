#include "RubiksCube.h"

class RubiksCube3DArray : public RubiksCube {
private:
    char cube[6][3][3]{};

    void rotateFaceClockwise(const int face) {
        // transposing the matrix
        for (int row=0;row<3;row++) {
            for (int col=0;col<3;col++) {
                std::swap(cube[face][row][col],cube[face][col][row]);
            }
        }
        // reversing it to get the rotated face
        for (int row=0;row<3;row++) {
            std::reverse(cube[face][row],cube[face][row]+3);
        }
    }

public:

    RubiksCube3DArray() {
        for (int face = 0; face < 6; face++) {
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    cube[face][row][col] = getColorLetter(COLOR(face));
                }
            }
        }
    }

    bool isSolved() const override {
        for (int face=0;face<6;face++) {
            for (int row=0;row<3;row++) {
                for (int col=0;col<3;col++) {
                    if (cube[face][row][col] != getColorLetter(COLOR(face))) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    RubiksCube & l() override {
        char temp[3];
        for (int row=0;row<3;row++) temp[row] = cube[2][row][0];
        for (int row=0;row<3;row++) cube[2][row][0] = cube[0][row][0];
        for (int row=0;row<3;row++) cube[0][row][0] = cube[4][2-row][0];
        for (int row=0;row<3;row++) cube[4][2-row][0] = cube[5][row][0];
        for (int row=0;row<3;row++) cube[5][row][0] = temp[row];
        this->rotateFaceClockwise(1);
        return *this;
    }

    RubiksCube & r() override {
        char temp[3] = {};
        for (int row = 0; row < 3; row++) temp[row] = cube[0][row][2];
        for (int row = 0; row < 3; row++) cube[0][row][2] = cube[2][row][2];
        for (int row = 0; row < 3; row++) cube[2][row][2] = cube[5][row][2];
        for (int row = 0; row < 3; row++) cube[5][row][2] = cube[4][2-row][0];
        for (int row = 0; row < 3; row++) cube[4][2-row][0] = temp[row];
        this->rotateFaceClockwise(3);
        return *this;
    }

    RubiksCube & u() override {
        return *this;
    }

    RubiksCube & d() override {
        return *this;
    }

    RubiksCube & f() override {
        return *this;
    }

    RubiksCube & b() {
        return *this;
    }

    RubiksCube & l2() {
        return *this;
    }

    RubiksCube & r2() {
        return *this;
    }

    RubiksCube & u2() {
        return *this;
    }

    RubiksCube & d2() {
        return *this;
    }

    RubiksCube & f2() override {
        return *this;
    }

    RubiksCube & b2() override {
        return *this;
    }

    RubiksCube & lPrime() override {
        return *this;
    }

    RubiksCube & rPrime() override {
        return *this;
    }

    RubiksCube & uPrime() override {
        return *this;
    }

    RubiksCube & dPrime() override {
        return *this;
    }

    RubiksCube & bPrime() override {
        return *this;
    }
};
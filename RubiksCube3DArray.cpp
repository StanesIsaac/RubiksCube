#include "RubiksCube.h"

class RubiksCube3DArray : public RubiksCube {
private:
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
    char cube[6][3][3]{};
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

    COLOR getColor(FACE face,int row,int col) const override {
        char c = cube[int(face)][row][col];
        switch (c) {
            case 'R':
                return COLOR::RED;
            case 'B':
                return COLOR::BLUE;
            case 'Y':
                return COLOR::YELLOW;
            case 'G':
                return COLOR::GREEN;
            case 'W':
                return COLOR::WHITE;
            default:
                return COLOR::ORANGE;
        }
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
        char temp_arr[3] = {};
        for (int col = 0; col < 3; col++) temp_arr[col] = cube[4][0][col];
        for (int col = 0; col < 3; col++) cube[4][0][col] = cube[1][0][col];
        for (int col = 0; col < 3; col++) cube[1][0][col] = cube[2][0][col];
        for (int col = 0; col < 3; col++) cube[2][0][col] = cube[3][0][col];
        for (int col = 0; col < 3; col++) cube[3][0][col] = temp_arr[col];

        this->rotateFaceClockwise(0);
        return *this;
    }

    RubiksCube & d() override {
        char temp_arr[3] = {};
        for (int col = 0; col < 3; col++) temp_arr[col] = cube[2][2][col];
        for (int col = 0; col < 3; col++) cube[2][2][col] = cube[1][2][col];
        for (int col = 0; col < 3; col++) cube[1][2][col] = cube[4][2][col];
        for (int col = 0; col < 3; col++) cube[4][2][col] = cube[3][2][col];
        for (int col = 0; col < 3; col++) cube[3][2][col] = temp_arr[col];
        this->rotateFaceClockwise(5);
        return *this;
    }

    RubiksCube & f() override {
        char temp_arr[3] = {};
        for (int col = 0; col < 3; col++) temp_arr[col] = cube[0][2][col];
        for (int col = 0; col < 3; col++) cube[0][2][col] = cube[1][2 - col][2];
        for (int col = 0; col < 3; col++) cube[1][2 - col][2] = cube[5][0][2 - col];
        for (int col = 0; col < 3; col++) cube[5][0][2 - col] = cube[3][col][0];
        for (int col = 0; col < 3; col++) cube[3][col][0] = temp_arr[col];
        this->rotateFaceClockwise(2);
        return *this;
    }

    RubiksCube & b() override{
        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp_arr[i];

        this->rotateFaceClockwise(4);
        return *this;
    }

    RubiksCube & l2() override {
        this->l();
        this->l();
        return *this;
    }

    RubiksCube & r2() override{
        this->r();
        this->r();
        return *this;
    }

    RubiksCube & u2() override{
        this->u();
        this->u();
        return *this;
    }

    RubiksCube & d2() override{
        this->d();
        this->d();
        return *this;
    }

    RubiksCube & f2() override {
        this->f();
        this->f();
        return *this;
    }

    RubiksCube & b2() override {
        this->b();
        this->b();
        return *this;
    }

    RubiksCube & lPrime() override {
        this->l();
        this->l();
        this->l();
        return *this;
    }

    RubiksCube & rPrime() override {
        this->r();
        this->r();
        this->r();
        return *this;
    }

    RubiksCube & uPrime() override {
        this->u();
        this->u();
        this->u();
        return *this;
    }

    RubiksCube & dPrime() override {
        this->d();
        this->d();
        this->d();
        return *this;
    }

    RubiksCube & bPrime() override {
        this->b();
        this->b();
        this->b();
        return *this;
    }

    RubiksCube& fPrime() override {
        this->f();
        this->f();
        this->f();
        return *this;
    }
    bool operator==(const RubiksCube3DArray &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    RubiksCube3DArray &operator=(const RubiksCube3DArray &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

struct Hash3d {
    size_t operator()(const RubiksCube3DArray &r1) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += r1.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }

};
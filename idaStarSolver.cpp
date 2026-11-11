//
// Created by Stanes Isaac on 31-08-2026.
//

#include "RubiksCube.h"
#include <bits/stdc++.h>
using namespace std;

template<typename T>
class idaStarSolver {
    public:
    T rubiksCube;
    const int FOUND = -1;
    const int INF = 1e9;
    const int MAX_DEPTH = 20;
    bool sameFace(RubiksCube::MOVE m1, RubiksCube::MOVE m2) {
        return static_cast<int>(m1) % 6 == static_cast<int>(m2) % 6;
    }

    idaStarSolver(T _rubiksCube) {
        this->rubiksCube = _rubiksCube;
    }
    int h(const T& cube) {
        return 0;
    }
    int search(int g, int bound, bool hasprevMove,RubiksCube::MOVE prevMove,vector<RubiksCube::MOVE> &moves) {
        int f = g+h(rubiksCube);
        if (f>bound) {
            return f;
        }
        if (rubiksCube.isSolved()) {
            return FOUND;
        }
        int mn = 1e9;
        for (int i=0;i<18; i++) {
            if (hasprevMove && sameFace(prevMove,RubiksCube::MOVE(i))) {
                continue;
            }
            rubiksCube.move(RubiksCube::MOVE(i));
            moves.push_back(RubiksCube::MOVE(i));
            int result = search(g+1,bound,true,RubiksCube::MOVE(i),moves);
            rubiksCube.revert(RubiksCube::MOVE(i));
            if (result == FOUND) {
                return FOUND;
            }
            mn = min(result,mn);
            moves.pop_back();
        }
        return mn;
    }
    vector<RubiksCube::MOVE> solve() {
        vector<RubiksCube::MOVE> moves;
        int bound = h(rubiksCube);
        while (true) {
            int result = search(0,bound,false,RubiksCube::MOVE(0),moves);
            if (result == FOUND) {
                return moves;
            }
            if (result == INF) {
                break;
            }
            if (result == INF || result > MAX_DEPTH) {
                break;
            }
            bound = result;
        }
        return {};
    }
};

//
// Created by Stanes Isaac on 30-07-2026.
//

#include<bits/stdc++.h>
#include "RubiksCube.h"
#ifndef DFS_SOLVER
#define DFS_SOLVER

template<typename T>
class DfsSolver {
private:
    int maxDepth;
    bool dfs(int depth) {
        if (cube.isSolved()) {return true;}
        if (depth>=maxDepth) {
            return false;
        }
        for (int i=0;i<18;i++) {
            moves.push_back(RubiksCube::MOVE(i));
            cube.move(RubiksCube::MOVE(i));
            if (dfs(depth+1)) return true;
            cube.revert(RubiksCube::MOVE(i));
            moves.pop_back();
        }
        return false;
    }
public:
    T cube;
    vector<RubiksCube::MOVE> moves;
    DfsSolver(T cube, int maxDepth = 8):cube(cube) ,maxDepth(maxDepth) {
    }

    bool solve() {
        return dfs(0);
    }

};
#endif
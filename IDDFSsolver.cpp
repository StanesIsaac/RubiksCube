//
// Created by Stanes Isaac on 08-08-2026.
//

#include <bits/stdc++.h>
#include "dfsSolver.cpp"
#include "RubiksCube.h"
using namespace std;

template <typename T>
class IDDFSsolver {
private:
    int maxDepth;
    vector<RubiksCube::MOVE> moves;
public:
    T cube;
    IDDFSsolver(T cubee,int maxDepth = 20) {
        cube = cubee;
        this->maxDepth = maxDepth;
    }
    vector<RubiksCube::MOVE> solve(){
        for (int i=1;i<=maxDepth;i++) {
            DfsSolver<T> solver(cube,i);
            if (solver.solve()){
                moves = solver.moves;
                break;
            }
        }
        return moves;
    }
};
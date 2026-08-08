//
// Created by Stanes Isaac on 08-08-2026.
//
#include <bits/stdc++.h>
#include "RubiksCube.h"
using namespace std;

#ifndef bfsSolver_CPP
#define bfsSolver_CPP
template<typename T,typename H>
class bfsSolver {
private:
    vector<RubiksCube::MOVE> moves;
    unordered_map<T, bool, H> visited;
    unordered_map<T, RubiksCube::MOVE, H> move_done;
    T bfs() {
        queue<T> q;
        q.push(cube);
        visited[cube] = true;

        while (!q.empty()) {
            T node = q.front();
            q.pop();
            if (node.isSolved()) {
                return node;
            }
            for (int i = 0; i < 18; i++) {
                auto curr_move = RubiksCube::MOVE(i);
                node.move(curr_move);
                if (!visited[node]) {
                    visited[node] = true;
                    move_done[node] = curr_move;
                    q.push(node);
                }
                node.revert(curr_move);
            }
        }
        return cube;
    }
    public:
    T cube;
    bfsSolver(T cb):cube(cb) {}
    vector<RubiksCube::MOVE> solve() {
        T solved_cube =  bfs();
        T curr_cube = solved_cube;
        while (!(curr_cube == cube)) {
            RubiksCube::MOVE curr_move = move_done[curr_cube];
            moves.push_back(curr_move);
            curr_cube.revert(curr_move);
        }
        cube = solved_cube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
};
#endif


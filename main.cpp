#include <iostream>
#include "RubiksCube3DArray.cpp"
#include "dfsSolver.cpp"
#include "bfsSolver.cpp"
#include "IDDFSsolver.cpp"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

void dfstest() {
    RubiksCube3DArray cb;
    //cb.randomShuffleCube(8);
    cb.l();
    cb.r();
    cb.u();
    cb.d();
    //cout<<cb.isSolved()<<'\n';
    //cb.print();
    DfsSolver solver(cb,8);
    cout<<solver.solve()<<'\n';
    //return solver.solve();
    vector<RubiksCube::MOVE>vec = solver.moves;
    for (int i=0;i<vec.size();i++) {
        cout<<(RubiksCube::getMove(vec[i]))<<" ";
    }
}

void bfstest() {
    RubiksCube3DArray cube;
    cube.print();

    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(4);
    for(auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();

    bfsSolver<RubiksCube3DArray, Hash3d> bfsSolver(cube);
    vector<RubiksCube::MOVE> solve_moves = bfsSolver.solve();

    for(auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    bfsSolver.cube.print();
}

void iddfstest() {
    RubiksCube3DArray cube;
    cube.print();
    vector<RubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(8);
    for(auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    cube.print();
    IDDFSsolver<RubiksCube3DArray> iddfsSolver(cube,9);
    vector<RubiksCube::MOVE> solve_moves = iddfsSolver.solve();

    for(auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
}

int main() {
    int t =1;
    while (t--) {
        iddfstest();
    }
}
#include <iostream>
#include "RubiksCube3DArray.cpp"
#include "dfsSolver.cpp"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

bool test() {
    RubiksCube3DArray cb;
    cb.randomShuffleCube(8);
    //cout<<cb.isSolved()<<'\n';
    //cb.print();
    DfsSolver solver(cb,8);
    //cout<<solver.solve()<<'\n';
    return solver.solve();
    // vector<RubiksCube::MOVE>vec = solver.moves;
    // for (int i=0;i<vec.size();i++) {
    //     cout<<(RubiksCube::getMove(vec[i]))<<" ";
    // }
    // for (auto mv:vec) {
    //     cb.move(mv);
    // }
}

int main() {
    int t =1;
    int cnt{0};
    while (t--) {
        cnt+=test();
    }
    cout<<cnt<<'\n';
}
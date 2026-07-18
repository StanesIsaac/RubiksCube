#include <iostream>
#include "RubiksCube3DArray.cpp"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.

int main() {
    RubiksCube3DArray cb;
    cb.r();
    cb.r();
    cb.r();
    cb.r();
    cb.l();
    cb.l();
    cb.l();
    cb.l();
    cout<<cb.isSolved()<<'\n';
    cb.print();
}
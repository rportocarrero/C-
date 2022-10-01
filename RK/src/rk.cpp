#include "rk.h"
#include <iostream>

using namespace std;

float rk1(float (*function)(float, float), float h, float x, float y){
    return (y + (h * function(x,y)));
}

float func(float y, float x){
    return x + y;
}

int main(){

    float x = 1;
    float y = 2;
    float h = 0.1;

    cout << rk1(&func, h, x, y) << endl;
    return 0;
}
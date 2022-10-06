#include "rk.hpp"
#include <iostream>

using namespace std;

float rk1(float (*f)(float, float), float h, float x, float y){
    return (y + (h * f(x,y)));
}

float midpoint(float (*f)(float, float), float h, float x, float y){
    return (y + (h * f(x + 1/2 * h,y + h * 1/2 * f(x,y))));
}

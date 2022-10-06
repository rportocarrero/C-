#include "rk.hpp"
#include "gtest/gtest.h"


using namespace std;

float (midpoint_test_function)(float x, float y){return x*y;}

TEST(midpoint, test_midpoint_single){
    float dt = 0.25;
    float t0 = 1.0;
    float y0 = 2.0;
    float t = t0;
    float y = y0;
    float max_time = 3.0;

    while(t < max_time){
        y = rk1(midpoint_test_function, dt, t, y);
        t = t + dt;
    }
    ASSERT_FLOAT_EQ(y, 0.00323326);
}
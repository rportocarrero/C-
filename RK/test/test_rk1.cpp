#include "rk.hpp"
#include "gtest/gtest.h"
#include <cmath>

using namespace std;

TEST(RK1, test_sanity){
    ASSERT_EQ(1,1);
}

float (test_function)(float x, float y){return y;}

TEST(RK1, test_rk1_single){
    float dt = 0.1;
    float t0 = 0.0;
    float t = t0;
    float y0 = 1.0;
    float y = y0;
    float max_time = 1.0;

    while(t < max_time){
        y = rk1(test_function, dt, t, y);
        t = t + dt;
    }
    ASSERT_FLOAT_EQ(y, 2.5937426);
}

TEST(RK1, test_rk1_single_longer_dt){
    float dt = 0.2;
    float t0 = 0.0;
    float t = t0;
    float y0 = 1.0;
    float y = y0;
    float max_time = 1.0;

    while(t < max_time){
        y = rk1(test_function, dt, t, y);
        t = t + dt;
    }
    ASSERT_FLOAT_EQ(y, 2.48832);
}

float (test_function2)(float x, float y){return x + y + x * y;}

TEST(RK1, test_rk1_single2){
    float dt = 0.025;
    float t0 = 0.0;
    float t = t0;
    float y0 = 1.0;
    float y = y0;
    float max_time = 0.1;

    while(t < max_time){
        y = rk1(test_function2, dt, t, y);
        t = t + dt;
    }
    ASSERT_FLOAT_EQ(y, 1.111673);
}
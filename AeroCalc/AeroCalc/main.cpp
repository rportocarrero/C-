//
//  main.cpp
//  AeroCalc
//
//  Created by Ryan Portocarrero on 7/10/20.
//  Copyright © 2020 Ryan Portocarrero. All rights reserved.
//

#include <iostream>
#include "StandardAtmosphere.cpp"
#include "CompressibleFlow.cpp"

float in[10];

int main(int argc, const char * argv[]) {
    
    CompFlow(1.4,.9,in);
    //dispCompFlow(in);
    
    Atmosphere(11,in);
    dispAtmosphere(in);
    
    
    return 0;
}

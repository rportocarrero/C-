//
//  StandardAtmosphere.cpp
//  AeroCalc
//
//  Created by Ryan Portocarrero on 7/10/20.
//  Copyright © 2020 Ryan Portocarrero. All rights reserved.
//

#include "StandardAtmosphere.hpp"
#include <math.h>
#include <iostream>

/*
 This function calculates atmospheric parameters for a given altitude
 */
float* Atmosphere(float z,float* output){
    const float r0 = 6356.766;  // radius of the earth in km
    const float MAX_HEIGHT = 86;    // maximum height of the atmospheric model
    const float K = 34.163195;
    const float T_SL = 288.15;   // sea level temperature (K)
    const float P_SL = 1.01325e5; // sea level pressure (N/m^2)
    const float A_SL =  340.294;    // speed of sound at sea level (m/s)
    const float D_SL = 1.2250;     // density at sea level (kg/m^3)
    const float beta = 1.458e-6;
    const float S = 110.4;  // Sutherlands constant (K)

    const float Hb[] = {    // height of the base of each layer (km)
        0,
        11,
        20,
        32,
        47,
        51,
        71,
        84.852
    };
    const float Tb[] = {    // temperature at the base of each layer (K)
        288.15,
        216.65,
        216.65,
        228.65,
        270.65,
        270.65,
        214.65
    };
    const float Lm[] = {    // lapse rate in each layer (K/km)
        -6.5,
        0,
        1,
        2.8,
        0,
        -2.8,
        -2.0
    };
    const float Prb[] = {   // pressure ratio at the base of each layer
        1,
        2.2336e-1,
        5.4032e-2,
        8.5666e-3,
        1.0945e-4,
        6.6063e-4,
        3.9046e-5
    };

    float H;    // geometric height
    int Layer;
    float T;    // temperature
    float Tr; //temperature ratio
    float Pr;   // pressure ratio
    float Dr;   // density ratio
    float a;    // speed of sound
    float mu;   // coefficient of viscosity
    float P;    // pressure
    float D;    // density
    float Re;   // Reynolds number per unit length
    
    H = z / (1 + (z / r0)); // calculate geometric height
    
    if(H > MAX_HEIGHT) return NULL; // model doesn't extend pas 86 km
    
    for(int i = 0; i < 7;i++){  // find the corresponding layer for the height
        if(Hb[i] > H){
            Layer = i-1;
            break;
        }
    }
    
    T = Tb[Layer] + Lm[Layer] * (H - Hb[Layer]);    // find ambient temperature
    
    Tr = T / T_SL;  // calculate temperature ratio

    if(Lm[Layer] != 0){     // calculate pressure ratio
        Pr = Prb[Layer] * pow( (Tb[Layer] / T), (K / Lm[Layer]));
    }else if(Lm[Layer] == 0){
        Pr = Prb[Layer] * exp( (-K * (H - Hb[Layer])) / Tb[Layer]);
    }

    Dr = Pr / Tr;   // calculate density ratio

    P = P_SL * Pr;  // calculate pressure
    
    D = D_SL * Dr;  // calculate density
    
    a = A_SL * sqrt( Tr ); // calculate speed of sound
    
    mu = (beta * pow(T, 1.5)) / (T + S);    // calculate the coefficient of viscosity
    
    Re = (D * a) / mu;
    
    // Load output array
    output[0] = H;
    output[1] = T;
    output[2] = P;
    output[3] = D;
    output[4] = Tr;
    output[5] = Pr;
    output[6] = Dr;
    output[7] = a;
    output[8] = mu;
    output[9] = Re;
    
    return 0;
};

/*
 This function displays the results of the atmosphere function
 */
void dispAtmosphere(float *in){
    std::cout << "Altitude: " << in[0] << " km\n";
    std::cout << "Temperature: " << in[1] << " K\n";
    std::cout << "Pressure: " << in[2] << " N/m^2\n";
    std::cout << "Density: " << in[3] << " kg/m^3\n";
    std::cout << "Temperature Ratio: " << in[4] << "\n";
    std::cout << "Pressure Ratio: " << in[5] << "\n";
    std::cout << "Density Ratio: " << in[6] << "\n";
    std::cout << "Speed of Sound: " << in[7] << " m/s\n";
    std::cout << "Coefficient of viscosity: " << in[8] << "\n";
    std::cout << "Reynolds number per unit length: " << in[9] << "\n";
};

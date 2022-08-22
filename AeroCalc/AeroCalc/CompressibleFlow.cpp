//
//  CompressibleFlow.cpp
//  AeroCalc
//
//  Created by Ryan Portocarrero on 7/10/20.
//  Copyright © 2020 Ryan Portocarrero. All rights reserved.
//

#include "CompressibleFlow.hpp"
#include <math.h>

float* CompFlow(float gamma, float M, float* output){
    float beta; //  Prandtl-Glauert Factor
    float Tr;   // Stagnation temperature ratio
    float Pr;   // Stagnation pressure ratio
    float Dr;   // stagnation density ratio
    float Ar;   // stagnation speed of sound
    float Qr;   // ratio of dynamic pressure to total pressure
    float Xr;   // cross sectional area ratio
    float Vr;   // ratio of velocity to critical velocity
    float CpCrit;   // critical pressure coeffcient
    float Cpvac;    // vacuum pressure coefficient
    float v;    // prantdl-meyer angle
    float u;    // Mach angle
    float M2;   // Downstream mach number for normal shockwave
    
    beta = sqrt(abs( pow (M,2) - 1) ); // calculate Prandtl-Glauert Factor
    
    Tr = 1 / (1 + ((gamma - 1) / 2) * pow(M, 2)); // calculate stagnation temperature ratio
    
    Pr = pow(Tr, (gamma / (gamma - 1))); // calculate stagnation pressure ratio
    
    Dr = pow(Pr, (1 /(gamma - 1)));  // calculate stagnation density ratio
    
    Ar = sqrt( Tr );    // calculate the stagnation speed of sound
    
    Qr = gamma / 2  * pow(M, 2) * Pr;   // calculate dynamic pressure ratio
    
    Xr = pow((gamma + 1) / 2, 0.5 * ((gamma + 1)/(gamma - 1))) * M * pow(Tr, 0.5 * ((gamma + 1)/(gamma - 1)));  // calculate cross sectional area ratio
    
    Vr = ((gamma + 1) / 2) * pow(M, 2) * Tr;    // calculate the velocity to critical velocity ratio

    CpCrit = -(2 / pow(gamma, pow(M, 2))) * (1 - pow((2 / (gamma + 1)),gamma / (gamma - 1))) * (1 / Pr);    // calculate critial pressure coefficient
    
    Cpvac = NULL;   // TODO: define M inf
    
    v = sqrt((gamma + 1)/(gamma - 1)) * atan(sqrt(((gamma - 1)/(gamma + 1) * (pow(M,2) - 1)) - acos(1/M))) - acos(1/M); // calculate prandtl-myer fan angle
    
    u = asin(1 / M);    // calculate mach angle
    
    M2 = ((gamma - 1) * pow(M,2) + 2) / (2 * gamma * pow(M, 2) - (gamma - 1));  // calculate downstream mach number
    
    output[0] = M;
    output[1] = Pr;
    output[2] = Dr;
    output[3] = Tr;
    output[4] = beta;
    output[5] = Qr;
    output[6] = Xr;
    output[7] = Vr;
    output[8] = CpCrit;
    output[9] = Cpvac;
    output[10] = v;
    output[11] = u;
    output[12] = M2;
    
    return 0;
};

void dispCompFlow(float *in){
    std::cout << "Mach Number: " << in[0] << "\n";
    std::cout << "Stagnation Pressure Ratio: " << in[1] << "\n";
    std::cout << "Stagnation Density Ratio: " << in[2] << "\n";
    std::cout << "Stagnation Temperature Ratio: " << in[3] << "\n";
    std::cout << "Prandtl-Glauert Factor: " << in[4] << "\n";
    std::cout << "Dynamic Pressure Ratio: " << in[5] << "\n";
    std::cout << "Cross Sectional Area Ratio: " << in[6] << "\n";
    std::cout << "Velocity to Critial Velocity Ratio: " << in[7] << "\n";
    std::cout << "Critical Pressure Coefficient: " << in[8] << "\n";
    std::cout << "Vacuum Pressure Coefficient: " << in[9] << "\n";
    std::cout << "Prandtl-Myer Fan Angle: " << in[10]*180/M_PI << "\n";
    std::cout << "Mach Angle: " << in[11]*180/M_PI<< "\n";
    std::cout << "Downstream Mach Number: " << in[12] << "\n";
};

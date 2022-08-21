#include "Fibonacci.h"

using namespace std;

unsigned short int Fib_uint2(unsigned short int n, unsigned short int precomputed[]){
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(precomputed[n] > 0) return precomputed[n];

    precomputed[n] = Fib_uint2(n-1, precomputed) + Fib_uint2(n-2, precomputed);
    return precomputed[n];
}

unsigned int Fib_uint4(unsigned int n, unsigned int precomputed[]){
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(precomputed[n] > 0) return precomputed[n];

    precomputed[n] = Fib_uint4(n-1, precomputed) + Fib_uint4(n-2, precomputed);
    return precomputed[n];
}

unsigned long long int Fib_uint8(unsigned long long int n, unsigned long long int precomputed[]){
    if(n==0) return 0;
    else if(n==1) return 1;
    else if(precomputed[n] > 0) return precomputed[n];

    precomputed[n] = Fib_uint8(n-1, precomputed) + Fib_uint8(n-2, precomputed);
    return precomputed[n];
}
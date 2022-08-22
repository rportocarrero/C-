#include <stdio.h>
#include <iostream>

using namespace std;

//2x2 identity matrix I
double I[2][2] = {{1,0},{0,1}};

//class for translation matrix
class freeSpacePropogation{
    double distance;
    double matrix[2][2] = {{1,distance},{0,1}};
};

//class for flat refcraftion matrix
class flatRefraction{
    double n1,n2;
    double matrix[2][2] = {{1,0},{0,n1/n2}};
};

//class for curved refraction matrix
class curvedRefraction{
    double n1,n2,R;
    double matrix[2][2] = {{1,0},{-(n2-n1)/(R*n2),n1/n2}};
};

class flatReflection {
    double matrix[2][2] = {{1,0},{0,1}};
};

class curvedReflection {
    double Re;
    double matrix[2][2] = {{1,0},{-2/Re,1}};
};

class thinLens {
    double f;
    double matrix[2][2] = {{1,0},{-1/f,1}};
};

//function to multiply 2x2 matrix
void multiply(double a[2][2], double b[2][2], double c[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main(){

};
/* Copyright (c) 2022 Max Gulda, KTH

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE. */

#include "cordic-math.h"

/* AngTable = 45, 26.565, 14.036, 7.125, 3.576, 1.790, 0.895, 0.448, 0.225, 0.112, 0.056, 0.028, 0.014, 0.007,  0.003 */
int LUT_CORDIC_ATAN[15] = {11520, 6801, 3593, 1824, 916, 458, 229, 115, 57, 28, 14, 7, 4, 2, 1}; /* Degree << 8 */

int32_t cordic_atan(int32_t y, int32_t x){
    int sumAngle = 0;
    int newX=x, newY=y;
    if(x<0 && y>0){              
        sumAngle = 180*256; 
        x = -x;
        y = -y;
    }else if(y < 0 && x>0){  
        sumAngle = 360*256;
    }
    for (int i = 0; i < 15; i++){
        if(y>0){
            /* Rotate clockwise */
            newX += (y>>i);
            newY -= (x>>i);
            sumAngle += LUT_CORDIC_ATAN[i];
        }else{
            /* Rotate counterclockwise */
            newX -= (y>>i);
            newY += (x>>i);
            sumAngle -= LUT_CORDIC_ATAN[i];
        }
        x = newX;
        y = newY;
    }
    /* If hypotenusa calculation is needed you will need to multiply 'x' by the cordic-gain which is cos(0.45)*cos(26.565)....
    The cordic gain for all 15 angles is 0.607252935 */
    return sumAngle;
}

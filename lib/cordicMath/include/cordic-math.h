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

#include "gd32vf103.h"

/**
 * @brief Fast aTan2 fixedpoint cordic
 * input adjacent (x) and opposite (y), returns arctan bitshifted <<8
 * 
 * @param x = adjacent
 * @param y = opposite
 * @return arctan(y/x) bitshifted 8 <<
 */
int cordic_atan(int32_t y, int32_t x);

/**
 * @brief Fast cos
 * 
 * @param theta degrees << 8
 * @return int, fixed point cos value 
 */
int cordic_cos(int theta);


/**
 * @brief Fast cos
 * 
 * @param theta degrees << 8
 * @return int, fixed point sin value 
 */
int cordic_sin(int x);

/**
 * @brief Fast arcsin
 * 
 * @param xInput value between -256 and 256
 * @return int bitshifted 8 left
 */
int cordic_asin(int xInput);

/**
 * @brief Fast arccos
 * 
 * @param xInput value between -256 and 256
 * @return int bitshifted 8 left
 */
int cordic_acos(int xInput);
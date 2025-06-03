/*
 * Copyright (c) 2025 Ismael Mosquera Rivera
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <stdio.h>
#include "imr_math.h"

/*
* This example demonstrates the imr_math library.
*
* Author: Ismael Mosquera Rivera.
*
*/
int main()
{
	printf("FUNDAMENTAL CONSTANTS:\n");
printf("e = %.10lf\n", e);
printf("pi = %.10lf\n", pi);
printf("\n");

printf("GENERAL PURPOSE FUNCTIONS:\n");
printf("integer part of 32.75 = %.2lf\n", imr_int(32.75));
printf("decimal part of 32.75 = %.2lf\n", imr_dec(32.75));
printf("abs(-12.57) = %.2lf\n", imr_abs(-12.57));
printf("fmod(3*pi, 2*pi) = %lf\n", imr_fmod(3.0*pi, 2.0*pi));
printf("sign(-12.57) = %.1lf\n", imr_sign(-12.75));
printf("neg(-12.57) = %.2lf\n", imr_neg(-12.57));
printf("ceil(2.6) = %.2lf\n", imr_ceil(2.6));
printf("floor(2.6) = %.2lf\n", imr_floor(2.6));
printf("round(2.6) = %.2lf\n", imr_round(2.6));
printf("max(6, 3) = %.1lf\n", imr_max(6.0, 3.0));
printf("min(6, 3) = %.1lf\n", imr_min(6.0, 3.0));
printf("square(3) = %.1lf\n", imr_square(3.0));
printf("hypot(3, 4) = %.1lf\n", imr_hypot(3.0, 4.0));
printf("factorial(120) = %E\n", imr_factorial(120));
printf("\n");

printf("ANALYTIC FUNCTIONS:\n");
printf("exp(0) = %.1lf\n", imr_exp(0.0));
printf("exp(1) = %.10lf\n", imr_exp(1.0));
printf("log(1) = %.1lf\n", imr_log(1.0));
printf("log2(1024) = %.1lf\n", imr_log2(1024.0));
printf("log10(1000000) = %.1lf\n", imr_log10(1000000.0));
printf("log10(1/1000) = %.1lf\n", imr_log10(1.0/1000.0));
printf("2.0^1.0 = %.1lf\n", imr_pow(2.0, 1.0));
printf("2.0^3.0 = %.1lf\n", imr_pow(2.0, 3.0));
printf("-2.0^-2.0 = %.2lf\n", imr_pow(-2.0, -2.0));
printf("sqrt(2.0) = %lf\n", imr_sqrt(2.0));
printf("curt(125) = %.1lf\n", imr_curt(125.0));
printf("12th root of 2.0 = %lf\n", imr_ithrt(2.0, 12));
printf("\n");

printf("TRIGONOMETRIC FUNCTIONS:\n");
double x = 3.0/4.0*pi;
double z = imr_sin(x);
printf("sin(3/4*pi) = %lf\n", z);
double y = imr_asin(z);
printf("asin(%lf) = %lf radians, %.2lf degrees.\n", z, y, imr_to_degrees(y));
x = pi / 8.0;
z = imr_cos(x);
printf("cos(pi/8) = %lf\n", z);
y = imr_acos(z);
printf("acos(%lf) = %lf radians, %.2lf degrees.\n", z, y, imr_to_degrees(y));
x = 3.0/4.0*pi;
z = imr_tan(x);
printf("tan(3/4*pi) = %.1lf\n", z);
y = imr_atan(z);
printf("atan(%.1lf) = %lf radians, %.2lf degrees.\n", z, y, imr_to_degrees(y));
y = imr_atan2(4.0, 3.0);
printf("atan2(4, 3) = %lf radians, %.2lf degrees.\n", y, imr_to_degrees(y));
printf("\n");

printf("HYPERBOLIC FUNCTIONS:\n");
printf("cosh(1/4) = %lf\n", imr_cosh(1.0/4.0));
printf("sinh(3/2) = %lf\n", imr_sinh(3.0/2.0));
x = 4.0/3.0;
y = imr_tanh(x);
printf("tanh(4/3) = %lf\n", y);
printf("atanh(%lf) = %lf\n", y, imr_atanh(y));

printf("\n");
printf("bye.\n");

return 0;
}

/* END */

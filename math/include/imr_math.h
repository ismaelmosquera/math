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

#ifndef ___IMR_MATH___
#define ___IMR_MATH___

#ifdef __cplusplus
extern "C"{
	#endif

/*
* this header has the prototypes needed to code a comprehensive math library.
* Here, you can find even more functions that in the standard math.h header that comes with any C compiler.
* Most of these functions are implemented using Taylor | Maclaurin Series or combinations of them.
* - Analytic functions: exp, log, log2, log10, pow, sqrt, curt, ithrt ...
* - Trigonometric functions and its inverses.
* - Hyperbolic functions.
* - Other general pourpose functions.
*
* All of them coded from the scratch without needed any other headers of the C compiler.
*/

/*
* Prototypes declaration and an explanation for each of them.
*/

/*
* Gets the absolute value of the parameter 'x'.
* param x -> value to compute its absolute value.
*
* returns absolute value of 'x'
*/
double imr_abs(double x);

/*
* Gets the negated value of the value passed as parameter.
* param x -> value to negate.
*
* returns -x
*/
double imr_neg(double x);

/*
* Gets the ceil of the value passed as parameter.
* param x -> value to get its ceil.
*
* returns ceil of 'x'
*/
double imr_ceil(double x);

/*
* Gets the floor of the value passed as parameter.
* param x -> value to get its flor.
*
* returns floor of 'x'
*/
double imr_floor(double x);

/*
* Rounds the value passed as parameter.
* param x -> value to round.
*
* returns rounded value
*/
double imr_round(double x);

/*
* Gets the integer part of the parameter 'x'.
* param x -> value to get its integer part.
*
* returns integer part of 'x'
*/
double imr_int(double x);

/*
* Gets the decimal part of the parameter 'x'.
* param x -> value to get its decimal part.
*
* returns decimal part of 'x'
*/
double imr_dec(double x);

/*
* Converts degrees ( sexagesimal ) to radians.
* param degrees -> value expressed in degrees.
*
* returns value expressed in radians
*/
double imr_to_radians(double degrees);

/*
* Converts radians to degrees ( sexagesimal ).
* param radians -> value expressed in radians.
*
* returns value expressed in degrees
*/
double imr_to_degrees(double radians);

/*
* Gets the sign of the parameter 'x'.
* param x -> value to evaluate its sign.
*
* returns -1.0 if negative or 1.0 if positive
*/
double imr_sign(double x);

/*
* Computes the remainder for the floating-point division.
* param x -> value to get its remainder according to the second parameter.
* param y -> divisor.
*
* returns remainder as a floating-point value
*/
double imr_fmod(double x, double y);

/*
* Gets the maximum value according two parameters.
* param x -> first parameter.
* param y -> second parameter.
*
* returns maximum value according 'x' and 'y'
*/
double imr_max(double x, double y);

/*
* Gets the minimum value according two parameters.
* param x -> first parameter.
* param y -> second parameter.
*
* returns minimum value according 'x' and 'y'
*/
double imr_min(double x, double y);

/*
* Computes the factorial of the integer parameter 'n'.
* param n -> int value to compute its factorial.
*
* This function uses, internally, floating-point arithmetics thus, we can compute factorials for bigger values
* avoiding a possible overflow.
*
* returns factorial of 'x' as a floating-point number.
*/
double imr_factorial(int n);

/*
* computes sqrt(x^2 + y^2).
* In other words, applies the Pitagoras theorem.
* param x -> first component.
* param y -> second component.
*
* You can view it as computing the magnitude for a vector in R2.
*
* returns hypot according 'x' and 'y' parameters
*/
double imr_hypot(double x, double y);

/*
* Gets the square of the parameter 'x'.
* param x -> value to compute its square.
*
* returns square of 'x'
*/
double imr_square(double x);

/*
* All trigonometric functions work with values expressed in radians.
*/

/*
* Computes the sine of the parameter 'x'.
* param x -> value to compute its sine.
*
* returns sine of 'x'
*/
double imr_sin(double x);

/*
* Computes the cosine of the parameter 'x'.
* param x -> value to compute its cosine.
*
* returns cosine of 'x'
*/
double imr_cos(double x);

/*
* Computes the arc-sine of the parameter 'x'.
* param x -> value to compute its arc-sine.
*
* returns arc-sine of 'x'
*/
double imr_asin(double x);

/*
* Computest the arc-cosine of the parameter 'x'.
* param x -> value to compute its arc-cosine.
*
* returns the arc-cosine of 'x'
*/
double imr_acos(double x);

/*
* Computes the tangent of the parameter 'x'.
* param x -> value to compute its tangent.
*
* returns tangent of 'x'
*/
double imr_tan(double x);

/*
* Computes the arctangent of the parameter 'x'
* param x -> value to compute its arctangent.
*
* returns arctangent of 'x'
*/
double imr_atan(double x);

/*
* Computes the arctangent according two parameters.
* param x -> first parameter.
* param y -> second parameter.
*
* In fact, you can get the same result using the atan(x) function:
* atan(x/y).
*
* returns arctangent according the 'x' and 'y' parameters.
*/
double imr_atan2(double x, double y);

/*
* Computes the hyperbolic cosine of the parameter 'x'.
* param x -> value to compute its hyperbolic cosine.
*
* returns hyperbolic cosine of 'x'
*/
double imr_cosh(double x);

/*
* Computes the hyperbolic sine of the parameter 'x'.
* param x -> value to compute its hyperbolic sine.
*
* returns hyperbolic sine of 'x'
*/
double imr_sinh(double x);

/*
* Computes the hyperbolic tangent of the parameter 'x'.
* param x -> value to compute its hyperbolic tangent.
*
* returns hyperbolic tangent of 'x'
*/
double imr_tanh(double x);

/*
* Computes the hyperbolic arctangent of the parameter 'x'.
* param x -> value to compute its hyperbolic arctangent.
*
* returns hyperbolic arctangent of 'x'
*/
double imr_atanh(double x);

/*
* Computes the exponential function 'exp(x)'.
* The exponential function is the inverse of the natural logarithm.
* param x -> value to compute its exponential.
*
* returns exponential of 'x'
*/
double imr_exp(double x);

/*
* Computes the natural logarithm of the parameter 'x'.
* The base of the natural logarithm is the 'e' constant.
* param x -> value to compute its natural logarithm.
*
* The natural logarithm is so useful; you can compute a logarithm for any base by using it.
* We know that:
* loga(b) = log(b) / log(a)
* Example:
* log2(8) = log(8) / log(2) = 3
*
* returns natural logarithm of 'x'
*/
double imr_log(double x);

/*
* Computes the base 2 logarithm of the parameter 'x'.
* param x -> value to compute its base 2 logarithm.
*
* returns log2 of 'x'
*/
double imr_log2(double x);
/*
* Computes the base 10 logarithm of the parameter 'x'.
* param x -> value to compute its base 10 logarithm.
*
* returns log10 of 'x'
*/
double imr_log10(double x);

/*
* Function to compute the power of the parameter 'base' raised to the parameter 'exp'.
* Since the exponent can be a fractional number, we are able to compute even ith roots for a value.
* The ith root of a value can be expressed as:
* double ithroot = pow(x, 1.0/ithindex);
* where 'x' is the value to compute its ithroot, and ith index is the radical index.
* Obiously, you can also compute powers for non-decimal values.
* param base -> base of the power.
* param exp -> exponent of the power.
*
* returns base^exp
*/
double imr_pow(double base, double exp);

/*
* Computes the square root of the parameter 'x'.
* param x -> value to compute its square root.
*
* returns square root of 'x'.
*/
double imr_sqrt(double x);
/*
* Computes the cubic root of the parameter 'x'.
* param x -> value to compute its cubic root.
*
* returns cubic root of 'x'.
*/
double imr_curt(double x);

/*
* Computes the ith root of 'x'.
* The ith index is an unsigned value in the range [1 .. n]
* Anyway, it is useful for radical indexes in the range [2 .. n]
* You can use negative values for the parameter 'x' just for odd ith indexes.
* param x -> value to compute its ith root.
*
* returns ith root of 'x'.
*/
double imr_ithrt(double x, unsigned ithindex);

/*
* Compute 'e' constant using the Euler's method.
* The number 'e' is the base of the natural logarithm.
*
* returns 'e'
*/
double imr_e();

/*
* Compute the 'pi' constent.
*
* returns 'pi'
*/
double imr_pi();

/*
* 'e' and 'pi' constants definition.
*/
#define e imr_e()
#define pi imr_pi()

#ifdef __cplusplus
}
	#endif

#endif

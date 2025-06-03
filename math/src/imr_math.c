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

#include "imr_math.h"

#define NaN 1E-12 /* not a number */
#define COS 0
#define SIN 1
#define SERIES_LENGTH 150

/*
*  Helper functions
*/
static double __abs_(double x)
{
return (x < 0.0) ? -x : x;
}

static double __pow_(double x, int n)
{
if(n < 0) return 1.0/__pow_(x, __abs_(n));
	if(n == 0) return 1.0;
	double y = x;
	for(int i = 1; i< n; i++)
	{
	y *= x;
	}
	return y;
}

static double __factorial_(int n)
{
	if(n < 0) return 0.0;
	if(n == 1 || n == 0) return 1;
	return (double)n*__factorial_(n-1);
}

/* just for abs(x) < 1 */
static double __atan_(double x)
{
double _atan = 0.0;
double sign = 1.0;
for(int n = 1; n < SERIES_LENGTH; n+=2)
{
_atan += sign * __pow_(x, n) / (double )n;
sign *= -1.0;
}
return _atan;
}

static double __log_(double x)
{
	if(x <= 0.0) return NaN;
	double aux = x - 1.0;
	double _log = aux;
	for(int n = 0; n <= SERIES_LENGTH; n++)
	{
	_log = aux + 2.0 * (x - imr_exp(aux)) / (x + imr_exp(aux));
	aux = _log;
	}
return _log;
}

static double __sincos_(double x, int type)
{
double y = imr_fmod(x, 2.0*pi);
double _sincos = 0.0;
double sign = 1.0;
int n = type;
while(n < SERIES_LENGTH)
{
_sincos += sign * __pow_(y, n) / __factorial_(n);
sign *= -1.0;
n += 2;
}
return _sincos;
}

static double __sinhcosh_(double x, int type)
{
double y = imr_fmod(x, 2.0*pi);
double _sincosh = 0.0;
int n = type;
while(n < SERIES_LENGTH)
{
_sincosh += __pow_(y, n) / __factorial_(n);
n += 2;
}
return _sincosh;
}

/* end helper functions */


/* implementation */

double imr_abs(double x)
{
return __abs_(x);
}

double imr_neg(double x)
{
	return -x;
}

double imr_ceil(double x)
{
double v = x;
double dec = imr_abs(imr_dec(v));
if(dec == 0) return (double)((int)v);
double _sign = imr_sign(v);
double z = (_sign < 0.0) ? (double)((int)v) : (double)((int)v) + 1.0;
return z;
}

double imr_floor(double x)
{
double v = x;
double dec = imr_abs(imr_dec(v));
if(dec == 0.0) return (double)((int)v);
double _sign = imr_sign(v);
double z = (_sign < 0.0) ? (double)((int)v)-1.0 : (double)((int)v);
return z;
}

double imr_round(double x)
{
	if(x == 0.0) return 0.0;
double dec = imr_abs(imr_dec(x));
if(dec == 0.0) return imr_int(x);
 if(x > 0.0)
 {
 return (dec >= 0.5) ? imr_ceil(x) : imr_floor(x);
}
return (dec >= 0.5) ? imr_floor(x) : imr_ceil(x);
}

double imr_int(double x)
{
	return (double)((int)x);

}

double imr_dec(double x)
{
double _int = imr_int(x);
return x - _int;
}

double imr_sign(double x)
{
return (x < 0.0) ? -1.0 : 1.0;
}

double imr_fmod(double x, double y)
{
double x2 = y;
	if(x2 == 0.0) return NaN;
	double x1 = x;
	double s = (imr_sign(x1) != imr_sign(x2)) ? -1.0 : 1.0;
	x1 = __abs_(x1);
	x2 = __abs_(x2);
	while(x1 >= x2)
	{
		x1 -= x2;
	}
	return s * x1;
}

double imr_to_radians(double degrees)
{
return degrees * pi / 180.0;
}

double imr_to_degrees(double radians)
{
return radians * 180.0 / pi;
}


double imr_max(double x, double y)
{
	return (x < y) ? y : x;
}

double imr_min(double x, double y)
{
	return (x <= y) ? x : y;
}

double imr_factorial(int n)
{
	return __factorial_(n);
}

double imr_square(double x)
{
return x*x;
}

double imr_hypot(double x, double y)
{
return imr_sqrt(imr_square(x) + imr_square(y));
}

double imr_sin(double x)
{
return __sincos_(x, SIN);
}

double imr_cos(double x)
{
return __sincos_(x, COS);
}

double imr_asin(double x)
{
double y = x;
if(y == 1.0) return pi/2.0;
if(y == -1.0) return -pi/2.0;
double _asin = 0.0;
for(int n = 0; n < SERIES_LENGTH-70; n++)
{
	_asin += (__factorial_(2*n)*__pow_(y, 2*n+1)) / (__pow_(4.0, n)*(double)(2*n+1)*imr_square(__factorial_(n)));
}
return _asin;
}

double imr_acos(double x)
{
double _acos = pi/2.0-imr_asin(x);
return _acos;
}

double imr_tan(double x)
{
return imr_sin(x) / imr_cos(x);
}

double imr_atan(double x)
{
double y = x;
	if(__abs_(y) < 1.0) return __atan_(y);
	/*
	* According Euler's proog:
	* 1/sqrt(1+x^2) = cos( atan(x) )
	*/
	double z = 1.0 / imr_sqrt(1.0 + imr_square(y));
	/*
	* thus, acos(1/sqrt(1+z^2)) = atan(x)
	*/
	return imr_sign(y) * imr_acos(z);
}

double imr_atan2(double x, double y)
{
if(y == 0.0) return imr_sign(x) * pi/2.0;
	double z = __abs_(x/y);
	return imr_sign(x) * imr_atan(z);
}

double imr_cosh(double x)
{
return __sinhcosh_(x, COS);
}

double imr_sinh(double x)
{
return __sinhcosh_(x, SIN);
}

double imr_tanh(double x)
{
return imr_sinh(x) / imr_cosh(x);
}

double imr_atanh(double x)
{
double y =x;
double _atanh = 0.0;
for(int n = 1; n < SERIES_LENGTH; n+=2)
{
	_atanh += __pow_(y, n)/(double )n;
}
return _atanh;
}

double imr_exp(double x)
{
double _exp = 0.0;
for(int n = 0; n < SERIES_LENGTH; n++)
{
_exp += __pow_(x, n) / __factorial_(n);
}
return _exp;
}

double imr_log(double x)
{
if(x <= 100.0) return __log_(x);
double y = x;
double _count = 0.0;
double d = 100.0;
while(y >= d)
{
y /= d;
_count += 1.0;
}
/*
* log(a*b) = log(a) + log(b)
*/
double _log = __log_(100.0) * _count + __log_(y);
return _log;
}

double imr_log2(double x)
{
return imr_log(x) / imr_log(2.0);
}

double imr_log10(double x)
{
	return imr_log(x) / imr_log(10.0);
}

double imr_pow(double base, double exp)
{
	if(exp == 1.0) return base;
if(base == 0.0) return 0.0;
if(exp == 0.0) return 1.0;
if(base < 0.0 || exp < 0.0) return __pow_(base, (int)exp);
return imr_exp(imr_log(base) * exp);
}

double imr_sqrt(double x)
{
	if(x < 0.0) return NaN;
return imr_pow(x, 1.0/2.0);
}

double imr_curt(double x)
{
double _sign = imr_sign(x);
return _sign * imr_pow(__abs_(x), 1.0/3.0);
}

double imr_ithrt(double x, unsigned ithindex)
{
	if(ithindex == 0) return NaN;
double _sign = imr_sign(x);
if(ithindex % 2 == 0 && _sign < 0.0) return NaN;
return _sign * imr_pow(__abs_(x), 1.0/(double)ithindex);
}

double imr_e()
{
double _e = 0.0;
for(int i = 0; i < SERIES_LENGTH; i++)
{
_e += 1.0 / __factorial_(i);
}
return _e;
}

double imr_pi()
{
return 4.0*(5.0*__atan_(1.0/7.0) + 2.0*__atan_(3.0/79.0));
}


/* END */

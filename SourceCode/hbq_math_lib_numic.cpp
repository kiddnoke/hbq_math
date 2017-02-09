#include "hbq_math_lib.h"

#define __HI(x) *(int*)&x
#define __LO(x) *(1+(int*)&x)
#define __HIp(x) *(int*)x
#define __LOp(x) *(1+(int*)x)
//#define M_PI 3.141592653589793E+00
namespace HBQ_MATH {
	const double uvnan = 0x7FF8000000000001;
	const double uvinf = 0x7FF0000000000000;
	const double uvneginf = 0xFFF0000000000000;
	const int mask = 0x7FF;
	const int shift = 64 - 11 - 1;
	const int bias = 1023;
	union fnum 
	{
		int m;
		float f;
	};
	float nan() {
		fnum nan;
		nan.m = uvnan;
		return nan.f;
	}
 
	float hbq_rsqrtf(float number){
		long i;
		float x2, y;
		const float threehalfs = 1.5F;

		x2 = number * 0.5F;
		y = number;
		i = *(long *)&y;						// evil floating point bit level hacking
		i = 0x5f3759df - (i >> 1);               // what the fuck?
		y = *(float *)&i;
		y = y * (threehalfs - (x2 * y * y));   // 1st iteration
											   //	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
		return y;
	}
	float hbq_sqrtf(float number) {
		int i;
		float x2, y;
		const float threehalfs = 1.5F;
		if (number == 0.0f) {
			return number;
		}
		if (number < 0.0f) {
			return 0.0f;
		}
		x2 = number * 0.5F;
		y = number;
		i = *(int *)&y;
		i = 0x5f375a86 - (i >> 1);
		y = *(float *)&i;
		y = y * (threehalfs - (x2 * y * y));
		y = y * (threehalfs - (x2 * y * y));
		y = y * (threehalfs - (x2 * y * y));
		return number*y;
	}
	float hbq_fabsf(float x) {
		return x < 0 ? -x : x;
	}
	double hbq_fabs(double x) {
		return x < 0 ? -x : x; 
	}
	float hbq_floorf(float x) {
		return (int)(x + 0x4000 ) - 0x4000 ;
	}
	float hbq_ceilf(float x) {
		return (int)(x - 0x4000 ) + 0x4000 ;
	}
	float xatan(float x ) {
		float z; 
		const float P0 = -8.750608600031904122785e-01 ;
		const float P1 = -1.615753718733365076637e+01 ;
		const float P2 = -7.500855792314704667340e+01 ;
		const float P3 = -1.228866684490136173410e+02 ;
		const float P4 = -6.485021904942025371773e+01 ;
		const float Q0 = +2.485846490142306297962e+01 ;
		const float Q1 = +1.650270098316988542046e+02 ;
		const float Q2 = +4.328810604912902668951e+02 ;
		const float Q3 = +4.853903996359136964868e+02 ;
		const float Q4 = +1.945506571482613964425e+02 ;
		z = x * x;
		z = z * ((((P0*z + P1)*z + P2)*z + P3)*z + P4) / (((((z + Q0)*z + Q1)*z + Q2)*z + Q3)*z + Q4);
		z = x*z + x;
		return z;
	}
	float satan(float x) {
		const float Morebits = 6.123233995736765886130e-17;
		const float Tan3pio8 = 2.41421356237309504880;
		if ( x <= 0.66 ){
			return xatan(x);
		}
		if (x > Tan3pio8){
			return M_PI / 2 - xatan(1 / x) + Morebits;
		}
		return M_PI / 4 + xatan((x - 1) / (x + 1)) + 0.5*Morebits;
	}
	float hbq_atanf(float x) {
		if (x == 0) {
			return x;
		}
		if (x > 0) {
			return satan(x);
		}
		return -satan(-x);
	}
	float hbq_asinf(float x) {
		bool sign;
		if (x == 0) {
			return x;// special case
		}
		if (x >= 1) {
			return M_PI /2 ;
		}
		else if (x <= -1) {
			return -(M_PI / 2);
		}
		sign = false;
		if (x < 0) {
			x = -x;
			sign = true;
		}
		if (x >= 1) {
			return M_PI /2 ;
		}
		//else if (x*x > 1) {
		//	return M_PI / 2;
		//}

		float temp = hbq_sqrtf(1 - x*x);
		if (x > 0.7) {
			temp = M_PI / 2 - satan(temp / x);
		} else {
			temp = satan(x / temp);
		}
		if (sign ){
			temp = -temp;
		}
		return temp;
	}
	float hbq_acosf(float x) {
		if (x >= 1) {
			return 0;
		}
		else if (x <= -1) {
			return M_PI;
		}
		double result = M_PI / 2 - hbq_asinf(x);
		if ( hbq_fabs(result) < 0.000001f ) {
			return 0.0f;
		}
		return result;
	}
	// sin coefficients
	const double _sin[] = {
		1.58962301576546568060E-10, // 0x3de5d8fd1fd19ccd
		-2.50507477628578072866E-8, // 0xbe5ae5e5a9291f5d
		2.75573136213857245213E-6,  // 0x3ec71de3567d48a1
		-1.98412698295895385996E-4, // 0xbf2a01a019bfdf03
		8.33333333332211858878E-3,  // 0x3f8111111110f7d0
		-1.66666666666666307295E-1, // 0xbfc5555555555548
	};
	// cos coefficients
	const double _cos[] = {
	-1.13585365213876817300E-11, // 0xbda8fa49a0861a9b
	2.08757008419747316778E-9,   // 0x3e21ee9d7b4e3f05
	-2.75573141792967388112E-7,  // 0xbe927e4f7eac4bc6
	2.48015872888517045348E-5,   // 0x3efa01a019c844f5
	-1.38888888888730564116E-3,  // 0xbf56c16c16c14f91
	4.16666666666665929218E-2,   // 0x3fa555555555554b
	};
	const double PI4A = 7.85398125648498535156E-1;                            // 0x3fe921fb40000000, Pi/4 split into three parts
	const double PI4B = 3.77489470793079817668E-8;                            // 0x3e64442d00000000,
	const double PI4C = 2.69515142907905952645E-15;                           // 0x3ce8469898cc5170,
	const double M4PI = 1.273239544735162542821171882678754627704620361328125; // 4/pi
	float hbq_cosf(float x) {
		bool sign;																		   // make argument positive
		sign = false;
		if (x < 0) {
			x = -x;
		}
		int j = int(x * M4PI);      // integer part of x/(Pi/4), as integer for tests on the phase angle
		double y = double(j);      // integer part of x/(Pi/4), as float
								// map zeros to origin
		if (j & 1 == 1) {
			j++;
			y++;
		}
		j &= 7;// octant modulo 2Pi radians (360 degrees)
		if (j > 3) {
			j -= 4;
			sign = !sign;
		}
		if (j > 1) {
			sign = !sign;
		}
		double z = ((x - y*PI4A) - y*PI4B) - y*PI4C; // Extended precision modular arithmetic
		double zz  = z * z;
		if ((j == 1) || (j == 2)) {
			y = z + z*zz*((((((_sin[0] * zz) + _sin[1])*zz + _sin[2])*zz + _sin[3])*zz + _sin[4])*zz + _sin[5]);
		} else {
			y = 1.0 - 0.5*zz + zz*zz*((((((_cos[0] * zz) + _cos[1])*zz + _cos[2])*zz + _cos[3])*zz + _cos[4])*zz + _cos[5]);
		}
		if (sign) {
			y = -y;
		}
		if (hbq_fabs(y) < 0.000001f) {
			return 0.0f;
		}
		return y;
	}

	float hbq_sinf(float x) {
		bool sign = false;
		if (x < 0) {
			x = -x; 
			sign = true;
		}
		int j = int(x * M4PI);
		double y = double(j);
		if (j & 1 == 1) {
			j++;
			y++;
		}
		j &= 7;
		if (j > 3) {
			sign = !sign;
			j -= 4;
		}
		double z = ((x - y*PI4A) - y*PI4B) - y*PI4C;
		double zz = z*z;
		if (j == 1 || j == 2) {
			y = 1.0 - 0.5*zz + zz*zz*((((((_cos[0] * zz) + _cos[1])*zz + _cos[2])*zz + _cos[3])*zz + _cos[4])*zz + _cos[5]);
		}
		else {
			y = z + z*zz*((((((_sin[0] * zz) + _sin[1])*zz + _sin[2])*zz + _sin[3])*zz + _sin[4])*zz + _sin[5]);
		}
		if (sign) {
			y = -y;
		}
		if (hbq_fabs(y) < 0.000001f) {
			return 0.0f;
		}
		return y; 
	}

	float hbq_tanf( float x ) {
		return hbq_sinf(x) / hbq_cosf(x);
	}

	const double
		tiny = 1.0e-300,
		zero = 0.0,
		pi = M_PI ,
		pi_o_4 = 7.8539816339744827900E-01, /* 0x3FE921FB, 0x54442D18 */
		pi_o_2 = 1.5707963267948965580E+00, /* 0x3FF921FB, 0x54442D18 */
		pi_lo = 1.2246467991473531772E-16; /* 0x3CA1A626, 0x33145C07 */
	float hbq_atan2f(float y, float x) {
		double z;
		int k, m, hx, hy, ix, iy;
		unsigned lx, ly;

		hx = __HI(x); ix = hx & 0x7fffffff;
		lx = __LO(x);
		hy = __HI(y); iy = hy & 0x7fffffff;
		ly = __LO(y);
		if (((ix | ((lx | -lx) >> 31))>0x7ff00000  ) ||((iy | ((ly | -ly) >> 31))>0x7ff00000))	/* x or y is NaN */
			return x + y;
		if ((hx - 0x3ff00000 | lx) == 0) return hbq_atanf(y);   /* x=1.0 */
		m = ((hy >> 31) & 1) | ((hx >> 30) & 2);	/* 2*sign(x)+sign(y) */

													/* when y = 0 */
		if ((iy | ly) == 0) {
			switch (m) {
			case 0:
			case 1: return y; 	/* atan(+-0,+anything)=+-0 */
			case 2: return  pi + tiny;/* atan(+0,-anything) = pi */
			case 3: return -pi - tiny;/* atan(-0,-anything) =-pi */
			}
		}
		/* when x = 0 */
		if ((ix | lx) == 0) return (hy<0) ? -pi_o_2 - tiny : pi_o_2 + tiny;

		/* when x is INF */
		if (ix == 0x7ff00000) {
			if (iy == 0x7ff00000) {
				switch (m) {
				case 0: return  pi_o_4 + tiny;/* atan(+INF,+INF) */
				case 1: return -pi_o_4 - tiny;/* atan(-INF,+INF) */
				case 2: return  3.0*pi_o_4 + tiny;/*atan(+INF,-INF)*/
				case 3: return -3.0*pi_o_4 - tiny;/*atan(-INF,-INF)*/
				}
			}
			else {
				switch (m) {
				case 0: return  zero;	/* atan(+...,+INF) */
				case 1: return -zero;	/* atan(-...,+INF) */
				case 2: return  pi + tiny;	/* atan(+...,-INF) */
				case 3: return -pi - tiny;	/* atan(-...,-INF) */
				}
			}
		}
		/* when y is INF */
		if (iy == 0x7ff00000) return (hy<0) ? -pi_o_2 - tiny : pi_o_2 + tiny;

		/* compute y/x */
		k = (iy - ix) >> 20;
		if (k > 60) z = pi_o_2 + 0.5*pi_lo; 	/* |y/x| >  2**60 */
		else if (hx<0 && k<-60) z = 0.0; 	/* |y|/x < -2**60 */
		else z = hbq_atanf(hbq_fabs(y / x));		/* safe to do y/x */
		switch (m) {
		case 0: return       z;	/* atan(+,+) */
		case 1: //__HI(z) ^= 0x80000000;
			return       -z;	/* atan(-,+) */
		case 2: return  pi - (z - pi_lo);/* atan(+,-) */
		default: /* case 3 */
			return  (z - pi_lo) - pi;/* atan(-,-) */
		}
	}
	float hbq_copysign(float x, float y)	{
		__HI(x) = (__HI(x) & 0x7fffffff) | (__HI(y) & 0x80000000);
		return x ;
	}
	int isnan(double x)	{
		int hx, lx;
		hx = (__HI(x) & 0x7fffffff);
		lx = __LO(x);
		hx |= (unsigned)(lx | (-lx)) >> 31;
		hx = 0x7ff00000 - hx;
		return ((unsigned)(hx)) >> 31;
	}
}

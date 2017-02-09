#ifndef HBQ_MATH_LIB_H
#define HBQ_MATH_LIB_H
#define M_PI   3.1415926535897932384626433832795
namespace HBQ_MATH {
	float hbq_sinf(float x);
	float hbq_cosf(float x);
	float hbq_tanf(float x);
	float hbq_asinf(float x);
	float hbq_acosf(float x);
	float hbq_atanf(float x);
	float hbq_atan2f(float y, float x);
	float hbq_rsqrtf(float x);
	float hbq_sqrtf(float x);
	float hbq_floorf(float x);
	float hbq_fabsf(float x);
	double hbq_fabs(double x);
	float hbq_ceilf(float x);
	float hbq_copysign(float x, float y);
}
#endif // QUAKE_MATH_LIB_H
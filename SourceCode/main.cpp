#include <iostream>
#include <stdio.h>
#include <cmath>
#include "Timing.h"
#include "hbq_math_lib.h"
using  std::cin;
using  std::cout;
using  std::endl;

float print_binary(float x)
{
	printf("0x%08x", *((int*)&x));
	return x;
};
#define PRINT_BINARY(X)  *((int*)&X)

//float print_binary( float x )
//{
//	union ufloat {
//		float f;
//		unsigned u;
//	};
//	ufloat a;
//	a.f = x;
//	unsigned os = 1;
//	for (int i = sizeof(unsigned) * 8 - 1; i >= 0; i--)
//	{
//		cout << ((a.u >> i) & os) << "";
//	}
//	return x;
//};
int Trigonometric_table()
{
	for ( int i = 0; i < 2000000; i++)
	{
		cout << i << endl;
		cout << "  HBQ_MATH::sinf=  " << print_binary(HBQ_MATH::hbq_sinf(i)) << endl;
		cout << "  HBQ_MATH::cosf=  " << print_binary(HBQ_MATH::hbq_cosf(i)) << endl;
		cout << "  HBQ_MATH::tanf=  " << print_binary(HBQ_MATH::hbq_tanf(i)) << endl;
	}
	return 0; 
}
int  arcTrigonometric_table()
{
	double i;
	for (i = -1.0f; i < 1.0f; i += 0.0001)
	{
		cout << i << endl;
		cout << "  HBQ_MATH::sinf=  " << print_binary(HBQ_MATH::hbq_asinf(i)) << endl;
		cout << "  HBQ_MATH::cosf=  " << print_binary(HBQ_MATH::hbq_acosf(i)) << endl;
	}
	return 0;
} 

int Trigonometric_table_test()
{
	float result;
	for (double i = - M_PI * 2; i < M_PI * 2 ; i += 1.0f/ 65536)
	{
		result = HBQ_MATH::hbq_sinf(i);
		printf(" HBQ_MATH::sinf( %4.10f ) = %4.20f  , 0x%08x\n", i, result , PRINT_BINARY(result));
		result = ::sinf(i);
		printf(" SYSTEM::sinf( %4.10f ) = %4.20f , 0x%08x\n", i, result , PRINT_BINARY(result));
		result = HBQ_MATH::hbq_cosf(i);
		printf(" HBQ_MATH::cosf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
		result = ::cosf(i);
		printf(" SYSTEM::cosf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
		result = HBQ_MATH::hbq_tanf(i);
		printf(" HBQ_MATH::tanf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
		result = ::tanf(i);
		printf(" SYSTEM::tanf( %4.10f ) = %4.20f , 0x%08x\n" , i , result, PRINT_BINARY(result)) ;
	}
	return 0;
}
int atan2f_test() {
	float result; 
	result = HBQ_MATH::hbq_atan2f(1.0f, 1.0f);
	printf(" HBQ_MATH::atan2f(1.0f, 1.0f ) = %4.20f  , 0x%08x\n",   result, PRINT_BINARY(result));
	result = ::atan2f(1.0f, 1.0f);
	printf(" SYSTEM::atan2f( 1.0f, 1.0f) = %4.20f , 0x%08x\n",   result, PRINT_BINARY(result));
	result = HBQ_MATH::hbq_atan2f(1.0f, -1.0f);
	printf(" HBQ_MATH::atan2f(1.0f, -1.0f ) = %4.20f  , 0x%08x\n", result, PRINT_BINARY(result));
	result = ::atan2f(1.0f, -1.0f);
	printf(" SYSTEM::atan2f( 1.0f, -1.0f) = %4.20f , 0x%08x\n", result, PRINT_BINARY(result));
	result = HBQ_MATH::hbq_atan2f(-1.0f, 1.0f);
	printf(" HBQ_MATH::atan2f(-1.0f, 1.0f ) = %4.20f  , 0x%08x\n", result, PRINT_BINARY(result));
	result = ::atan2f(-1.0f, 1.0f);
	printf(" SYSTEM::atan2f( -1.0f, 1.0f) = %4.20f , 0x%08x\n", result, PRINT_BINARY(result));
	result = HBQ_MATH::hbq_atan2f(-1.0f, -1.0f);
	printf(" HBQ_MATH::atan2f(-1.0f, -1.0f ) = %4.20f  , 0x%08x\n", result, PRINT_BINARY(result));
	result = ::atan2f(-1.0f, -1.0f);
	printf(" SYSTEM::atan2f(-1.0f, -1.0f ) = %4.20f , 0x%08x\n", result, PRINT_BINARY(result));
	cout << endl;
	result = HBQ_MATH::hbq_atan2f(0.9f, 1.0f);
	printf(" HBQ_MATH::atan2f(0.9f, 1.0f ) = %4.20f  , 0x%08x\n", result, PRINT_BINARY(result));
	result = ::atan2f(0.9f, 1.0f);
	printf(" SYSTEM::atan2f( 0.9f, 1.0f) = %4.20f , 0x%08x\n", result, PRINT_BINARY(result));
	result = HBQ_MATH::hbq_atan2f(0.9f, -1.0f);
	printf(" HBQ_MATH::atan2f(0.9f, -1.0f ) = %4.20f  , 0x%08x\n", result, PRINT_BINARY(result));
	result = ::atan2f(0.9f, -1.0f);
	printf(" SYSTEM::atan2f( 0.9f, -1.0f) = %4.20f , 0x%08x\n", result, PRINT_BINARY(result));
	result = HBQ_MATH::hbq_atan2f(-0.9f, 1.0f);
	printf(" HBQ_MATH::atan2f(-0.9f, 1.0f ) = %4.20f  , 0x%08x\n", result, PRINT_BINARY(result));
	result = ::atan2f(-0.9f, 1.0f);
	printf(" SYSTEM::atan2f( -0.9f, 1.0f) = %4.20f , 0x%08x\n", result, PRINT_BINARY(result));
	result = HBQ_MATH::hbq_atan2f(-0.9f, -1.0f);
	printf(" HBQ_MATH::atan2f(-0.9f, -1.0f ) = %4.20f  , 0x%08x\n", result, PRINT_BINARY(result));
	result = ::atan2f(-0.9f, -1.0f);
	printf(" SYSTEM::atan2f(-0.9f, -1.0f ) = %4.20f , 0x%08x\n", result, PRINT_BINARY(result));
	cout << endl;
	result = HBQ_MATH::hbq_atan2f(1.1f, 1.0f);
	printf(" HBQ_MATH::atan2f(1.1f, 1.0f ) = %4.20f  , 0x%08x\n", result, PRINT_BINARY(result));
	result = ::atan2f(1.1f, 1.0f);
	printf(" SYSTEM::atan2f( 1.1f, 1.0f) = %4.20f , 0x%08x\n", result, PRINT_BINARY(result));
	result = HBQ_MATH::hbq_atan2f(1.1f, -1.0f);
	printf(" HBQ_MATH::atan2f(1.1f, -1.0f ) = %4.20f  , 0x%08x\n", result, PRINT_BINARY(result));
	result = ::atan2f(1.1f, -1.0f);
	printf(" SYSTEM::atan2f( 1.1f, -1.0f) = %4.20f , 0x%08x\n", result, PRINT_BINARY(result));
	result = HBQ_MATH::hbq_atan2f(-1.1f, 1.0f);
	printf(" HBQ_MATH::atan2f(-1.1f, 1.0f ) = %4.20f  , 0x%08x\n", result, PRINT_BINARY(result));
	result = ::atan2f(-1.1f, 1.0f);
	printf(" SYSTEM::atan2f( -1.1f, 1.0f) = %4.20f , 0x%08x\n", result, PRINT_BINARY(result));
	result = HBQ_MATH::hbq_atan2f(-1.1f, -1.0f);
	printf(" HBQ_MATH::atan2f(-1.1f, -1.0f ) = %4.20f  , 0x%08x\n", result, PRINT_BINARY(result));
	result = ::atan2f(-1.1f, -1.0f);
	printf(" SYSTEM::atan2f(-1.1f, -1.0f ) = %4.20f , 0x%08x\n", result, PRINT_BINARY(result));
	cout << endl;
	return 0;
}
int  arcTrigonometric_table_test()
{
	double i;
	float result;
	for (i = -1.0f; i <= 1.0f;  i += 1.0f / 65536)
	{
		result = HBQ_MATH::hbq_asinf(i);
		printf(" HBQ_MATH::asinf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
		result = ::asinf(i);
		printf(" SYSTEM::asinf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
		result = HBQ_MATH::hbq_acosf(i);
		printf(" HBQ_MATH::acosf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
		result = ::acosf(i);
		printf(" SYSTEM::acosf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
	}
	return 0;
} 
int arctanf_test() {
	double i; float result;
	for (i = -20 ; i < 20 ; i += 1.0f / 128 ) {
		result = HBQ_MATH::hbq_atanf(i);
		printf(" HBQ_MATH::atanf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
		result = ::tanf(i);
		printf(" SYSTEM::atanf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
	}
	return 0;
}
int arctanf_one_one_test() {
	double i; float result;
	for (i = -1.0f; i < 1.0f; i += 1.0f / 65536 ) {
		result = HBQ_MATH::hbq_atanf(i);
		printf(" HBQ_MATH::atanf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
		result = ::tanf(i);
		printf(" SYSTEM::atanf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
	}
	return 0; 
}
int Trigonometric_table_system()
{
	for (int i = 0; i < 2000000; i++)
	{
		cout << "HBQ_MATH::sinf=" << print_binary(::sinf(i)) << endl;
		cout << "HBQ_MATH::cosf=" << print_binary(::cosf(i)) << endl;
		cout << "HBQ_MATH::tanf=" << print_binary(::tanf(i)) << endl;
	}
	return 0;
}
int  arcTrigonometric_table_system()
{
	double i;
	for (i = -1.0f; i < 1.0f; i += 0.0001)
	{
		cout << "HBQ_MATH::asinf=" << print_binary(::asinf(i)) << endl;
		cout << "HBQ_MATH::acosf=" << print_binary(::acosf(i)) << endl;
	}
	return 0;
}
int sqrt_test() {
	float result; 
	for ( double i = 0; i < 500000; i++) {
		result = HBQ_MATH::hbq_sqrtf( i );
		printf(" HBQ_MATH::sqrtf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
		result = ::sqrtf( i );
		printf(" SYSTEM::sqrtf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
	}
	return 0; 
}
int ceilf_test() {
	float result; 
	for (float i = -1000; i < 1000; i += 1.0f/8 )
	{
		result = HBQ_MATH::hbq_ceilf(i);
		printf(" HBQ_MATH::ceilf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
		result = ::ceilf(i);
		printf(" SYSTEM::ceilf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
	}
	return 0; 
}
int floorf_test() {
	float result;
	for (float i = -1000; i < 1000; i += 1.0f / 8)
	{
		result = HBQ_MATH::hbq_floorf(i);
		printf(" HBQ_MATH::floorf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
		result = ::floorf(i);
		printf(" SYSTEM::floorf( %4.10f ) = %4.20f , 0x%08x\n", i, result, PRINT_BINARY(result));
	}
	return 0;
}
int fabsf_test() {
	for (float i = -1000; i < 1000; i += 0.05) {
		cout << " HBQ_MATH::fabsf(" << i << ")=" << print_binary(HBQ_MATH::hbq_fabsf(i)) << endl;
	}
	return 0; 
}
//int pow_test() {
//	for (float i = -5.0f; i < 32.0f; i += 0.001) {
//		float __pow = HBQ_MATH::powf(2, i);
//		printf(" 0x%08x , %4.20f = HBQ_MATH::powf(2 , %4.20f ) \n ", PRINT_BINARY(__pow), __pow ,  i);
//	}
//	return 0; 
//}
void acosf_delte_test() {
	double i;
	int count = 0;
	for (i = -1.0f; i <= 1.0f; i += 0.0000152587890625f) {
		count++;
		float a = acosf(i);
		float b = HBQ_MATH::hbq_acosf(i);
		if (::fabs(a - b) > 0.003) {
			printf(" a =%4.20f , b =%4.20f ", a, b);
		}
	}
}

class Foo

{
public:
	Foo(int i )  : m_i(i){}
	Foo(){ 
		Foo(1);
	}
	int GetI(void){ return m_i; }
private:
	int m_i;
};
union fnum
{
	int m;
	float f;
};


int main(int argc, char* argv[])
{  
	cout << sizeof(int) << endl;
	cout << sizeof(float) << endl;
	fnum xx, yy , zz ,zero ,Zero;
	xx.m = 0x7fc00000;
	yy.m = 0x3fc90fdb;
	zz.m = 0x40490fdb;
	zero.m = 0x80000000;
	Zero.m = 0x00000000;
	fnum float_3db0fc50;
	float_3db0fc50.m = 0x3db0fc50;
	printf(" x.m  = %4.20f , y.m  = %4.20f ,z.m  = %4.20f , zero.m = %4.20f , Zero.m = %4.20f \n", xx.f, yy.f , zz.f , zero.f , Zero.f );
	cout << sizeof(double) << endl;
	printf("这是无理数Pi的常量 %2.20f \n", M_PI);
	float s = HBQ_MATH::hbq_sinf(2);
	printf("%4.20f = HBQ_MATH::sinf(2) \n", s);
	s = sinf(2);
	printf("%4.20f = ::sinf(2) \n", s);

	s = HBQ_MATH::hbq_cosf(float_3db0fc50.f);
	printf("%4.20f = HBQ_MATH::hbq_cosf(%4.20f)\n", s, float_3db0fc50.f);
	fnum acos_cos_;
	acos_cos_.f = HBQ_MATH::hbq_acosf(HBQ_MATH::hbq_cosf(M_PI));
	printf("%4.20f , 0x%08x \n", acos_cos_.f, acos_cos_.m);

	fnum nan , result ;
	nan.m = 0x7fc00000;
	result.f = M_PI / 2 - nan.f;
	printf(" M_PI / 2 - nan.f = %4.20f \n", result.f);

	s = HBQ_MATH::hbq_cosf(2);
	printf("%4.20f = HBQ_MATH::cos(2) \n", s);
	s = cosf(2);
	printf("%4.20f = ::cos(2) \n", s);

	s = HBQ_MATH::hbq_tanf(2);
	printf("%4.20f = HBQ_MATH::tanf(2)\n", s);
	s = tanf(2);
	printf("%4.20f = ::tanf(2)\n", s);

	s = HBQ_MATH::hbq_asinf(0.5);
	printf("%4.20f , 0x%08x = HBQ_MATH::asin(0.5) \n", s , PRINT_BINARY(s));
	s = asinf(0.5);
	printf("%4.20f = ::asin(0.5)\n", s);

	s = HBQ_MATH::hbq_acosf(0.999999999999999f);
	printf("%4.20f = HBQ_MATH::acos(0.999999999999999f) \n", s);
	s = acosf(0.999999999999999f);
	printf("%4.20f = ::acos(0.999999999999999f) \n", s);

	s = HBQ_MATH::hbq_atanf(1);
	printf("%4.20f= HBQ_MATH::atanf(1)\n", s);
	s = atanf(1);
	printf("%4.20f = ::atanf(1)\n", s);

	s = HBQ_MATH::hbq_atan2f(1, 1);
	printf("%4.20f = HBQ_MATH::atan2(1, 1)\n", s);
	s = atan2f(1 ,1 );
	printf("%4.20f = ::atan2f(1, 1) \n", s);
	
	fnum zero_;
	fnum zero_result;
	zero_result.f = HBQ_MATH::hbq_sqrtf(-0.0f);
	zero_.f = ::sqrtf(-0.0f);
	printf("HBQ_MATH::hbq_sqrtf(-0.0f) = 0x%08x , %4.20f  \n::sqrtf(-0.0f) = 0x%08x , %4.20f \n",zero_result.m , zero_result.f , zero_.m , zero_.f  );

	s = HBQ_MATH::hbq_sqrtf(20);
	printf("%4.20f ,0x%08x = HBQ_MATH::sqrtf(20) \n", s , PRINT_BINARY(s));
	s = sqrtf(20);
	printf("%4.20f ,0x%08x = ::sqrtf(20) \n", s , PRINT_BINARY(s) );

	double x = 12.34, y = -32.5, a, b;   //为变量赋初值
	a = HBQ_MATH::hbq_copysign(x, y);
	//a = _copysign(x, y);

	//求由x的数据和y的符号组成的数
	b = HBQ_MATH::hbq_copysign(a, x);
	//b = _copysign(a, x);
	//求由a的数据和x的符号组成的数
	cout << x << "\t" << y << "\n";
	cout << a << "\t" << b << "\n";
 
 

	//s = HBQ_MATH::powf(2.2 , 3.3 );
	//printf("%4.20f = HBQ_MATH::powf(2.2 , 3.3 ) \n", s);
	//s = ::powf(2.2, 3.3);
	//printf("%4.20f = ::powf(2.2 , 3.3 )\n", s);

	//s = HBQ_MATH::expf(2);
	//printf("%4.20f = HBQ_MATH::exp(2) \n", s);
	//s = expf(2);
	//printf("%4.20f = ::exp(2) \n", s);

	//s = HBQ_MATH::ldexp(3, 2);
	//printf("%4.20f = HBQ_MATH::ldexp(2) \n", s);
	//s = ldexp(3, 2);
	//printf("%4.20f = ::ldexp(2) \n", s);

	//int n; 
	//s = HBQ_MATH::frexp(242.354, &n);
	//printf("%4.20f , %4.20f = HBQ_MATH::frexp(242.354, &n) \n", s , n );
	//s = frexp(242.354, &n);
	//printf("%4.20f , %4.20f = ::frexp(242.354, &n) \n",  s , n );

	cout << " =============Test HBQ_MATH::sinf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f++) {
		HBQ_MATH::hbq_sinf(f);
	}
	stopWithPrintTiming();

	cout << " =============Test ::sinf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f++) {
		sinf(f);
	}

	cout << " =============Test ::tan 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f++) {
		tan(f);
	}
	stopWithPrintTiming();
	cout << " =============Test HBQ_MATH::asinf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f++) {
		HBQ_MATH::hbq_asinf(f);
	}
	stopWithPrintTiming();
 
	cout << " =============Test ::atanf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f++) {
		 ::atanf(f);
	}
	stopWithPrintTiming();

	cout << " =============Test HBQ_MATH::atan 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f++) {
		HBQ_MATH::hbq_atanf(f);
	}
	stopWithPrintTiming();
	cout << " =============Test ::ceilf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f += 1) {
		::ceilf(f);
	}
	stopWithPrintTiming(); 
	cout << " =============Test HBQ_MATH::ceilf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f += 1) {
		HBQ_MATH::hbq_ceilf(f);
	}
	stopWithPrintTiming();

	cout << " =============Test  ::floorf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f += 1) {
		::floorf(f);
	}
	stopWithPrintTiming();
	cout << " =============Test HBQ_MATH::floorf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f += 1) {
		HBQ_MATH::hbq_floorf(f);
	}
	stopWithPrintTiming();

	cout << " =============Test  ::sqrt 1000w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 10000000.0f; f += 1) {
		 ::sqrt(f);
	}
	stopWithPrintTiming();

	cout << " =============Test HBQ_MATH::sqrtf 1000w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 10000000.0f; f += 1) {
		HBQ_MATH::hbq_sqrtf(f);
	}
	stopWithPrintTiming();

	cout << " =============Test  ::floorf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f += 1) {
		::floorf(f);
	}
	stopWithPrintTiming();

	cout << " =============Test HBQ_MATH::floorf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f += 1) {
		HBQ_MATH::hbq_floorf(f);
	}
	stopWithPrintTiming();

	cout << " =============Test  ::ceilf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f += 1) {
		::ceilf(f);
	}
	stopWithPrintTiming();

	cout << " =============Test HBQ_MATH::ceil 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f += 1) {
		HBQ_MATH::hbq_ceilf(f);
	}
	stopWithPrintTiming();

	cout << " =============Test  ::fabsf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f += 1) {
		::fabsf(f);
	}
	stopWithPrintTiming();

	cout << " =============Test HBQ_MATH::fabsf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f += 1) {
		HBQ_MATH::hbq_fabsf(f);
	}
	stopWithPrintTiming();
	cout << " =============Test ::powf 500w次 效率=========" << endl;
	startTiming();
	for (float f = 0.0f; f < 5000000.0f; f += 1) {
		::powf(2, f);
	}
	stopWithPrintTiming();
	cout << " =============Test HBQ_MATH::powf 500w次 效率=========" << endl;
	startTiming();
	//for (float f = 0.0f; f < 5000000.0f; f += 1) {
	//	HBQ_MATH::powf(2, f);
	//}
	stopWithPrintTiming();
	cout << "=============trigonometric_test_test=========" << endl;
	Trigonometric_table_test();
	cout << "=============arctrigonometric_test_test=========" << endl;
	arcTrigonometric_table_test();
	cout << "===============HBQ_MATH::atanf===================" << endl;
	arctanf_test();
	arctanf_one_one_test();
	cout << " =============trigonometric_test=========" << endl;
	//Trigonometric_table();
	cout << "=============arctrigonometric_test==========" << endl; 
	//arcTrigonometric_table();
	cout << "=============sqrtf_test==============" << endl;
	sqrt_test();
	cout << "=============ceilf_test==============" << endl;
	//ceilf_test();
	cout << "==============floor_test==============" << endl;
	//floorf_test();
	cout << "==============fabsf_test===============" << endl;
	//fabsf_test();
	cout << "==============powf_test===============" << endl;
	//pow_test();
	cout << "=================atan2f_test===============" << endl; 
	atan2f_test();
	return  0;
}
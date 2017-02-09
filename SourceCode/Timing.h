#ifndef TIMING_H  
#define TIMING_H  

#include <time.h>  
#include <stdio.h>  

#ifdef _WIN32 || _WIN64  
#include <windows.h>  
#define timing_t double  
static _LARGE_INTEGER time_start, time_over;
static double dqFreq;

static inline void startTiming()
{
	_LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;

	QueryPerformanceCounter(&time_start);
}

// unit: ms  
static inline timing_t stopTiming()
{
	QueryPerformanceCounter(&time_over);
	return ((double)(time_over.QuadPart - time_start.QuadPart) / dqFreq * 1000);
}

static inline timing_t stopWithPrintTiming()
{
	timing_t timing;
	QueryPerformanceCounter(&time_over);
	timing = ((double)(time_over.QuadPart - time_start.QuadPart) / dqFreq * 1000);
	printf("----------Elapsed Timing(ms) : %.3lf --------------\n", timing);

	return timing;
}

#else  
#include <unistd.h>  
typedef unsigned long long int64;
#define timing_t int64  
#if defined(__i386__)  
inline int64 GetCycleCount() {
	int64 result;
	__asm__ __volatile__("rdtsc" : "=A" (result));
	return result;
}
#elif defined(__x86_64__)  
inline int64 GetCycleCount()
{
	int64 hi, lo;
	__asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
	return ((int64)lo) | (((int64)hi) << 32);
}
#endif  

static int64 ticks_start, ticks_end;

static inline void startTiming()
{
	ticks_start = GetCycleCount();
}

// unit: cycles  
static inline int64 stopTiming()
{
	ticks_end = GetCycleCount();
	return (ticks_end - ticks_start);
}

static inline int64 stopWithPrintTiming()
{
	int64 timing;
	ticks_end = GetCycleCount();
	timing = (ticks_end - ticks_start);
	printf("----------Elapsed Timing(Cycles) : %llu ----------\n", timing);

	return timing;
}
#endif  

// unit: ms  
static inline void wait(int ms)
{
#ifdef WIN32  
	Sleep(ms);
#else  
	usleep(ms * 1000);
#endif  
}

#endif  
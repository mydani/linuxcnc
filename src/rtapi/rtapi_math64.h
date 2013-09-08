#ifndef RTAPI_MATH64_H
#define RTAPI_MATH64_H

#ifdef __KERNEL__
#include <linux/math64.h>
#define rtapi_div_u64_rem div_u64_rem
#define rtapi_div_u64 div_u64
#define rtapi_div_s64_rem div_s64_rem
#define rtapi_div_s64 div_s64
#else
static inline __u64 rtapi_div_u64_rem(__u64 dividend, __u32 divisor, __u32 *remainder)
{
	*remainder = dividend % divisor;
	return dividend / divisor;
}

static inline __u64 rtapi_div_u64(__u64 dividend, __u32 divisor) {
	return dividend / divisor;
}
static inline __s64 rtapi_div_s64_rem(__s64 dividend, __s32 divisor, __s32 *remainder)
{
	*remainder = dividend % divisor;
	return dividend / divisor;
}

static inline __s64 rtapi_div_s64(__s64 dividend, __s32 divisor) {
	return dividend / divisor;
}
#endif

#endif

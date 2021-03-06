/* --
MIT License

Copyright (c) 2018 Abe Takafumi

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
SOFTWARE.
**/

#ifndef _TIMEOFDAY_H_
#define _TIMEOFDAY_H_

#ifdef __cplusplus
	#ifndef CPP_SRC
		#define CPP_SRC(x) x
	#endif
	#if __cplusplus >= 201103L	// >= C++11
	
	#else				// < C++11

	#endif
#else
	#ifndef CPP_SRC
		#define CPP_SRC(x)
	#endif
#endif

#include <stdint.h>
#ifdef __GNUC__
#include <arch/gcc/timeofday.h>
#elif _WIN32
#include <arch/vc/timeofday.h>
#else
	#error "not supported."
#endif

extern int64_t	____generictime_usec;
extern int64_t	____generictime_msec;

static void
generic_upd_generictime(void) {
	____generictime_usec = __generic_get_usec();
	____generictime_msec = ____generictime_usec / 1000;
}

static inline int64_t
generic_get_usec_fast(void) {
	return ____generictime_usec;
}

static inline int64_t
generic_get_usec(void) {
	generic_upd_generictime();
	return generic_get_usec_fast();
}

static inline int64_t
generic_get_msec_fast(void) {
	return ____generictime_msec;
}

static inline int64_t
generic_get_msec(void) {
	generic_upd_generictime();
	return generic_get_msec_fast();
}


#endif /* WQ_H_ */

/****************************************************************

The author of this software is David M. Gay.

Copyright (C) 1998, 2000 by Lucent Technologies
All Rights Reserved

Permission to use, copy, modify, and distribute this software and
its documentation for any purpose and without fee is hereby
granted, provided that the above copyright notice appear in all
copies and that both that the copyright notice and this
permission notice and warranty disclaimer appear in supporting
documentation, and that the name of Lucent or any of its entities
not be used in advertising or publicity pertaining to
distribution of the software without specific, written prior
permission.

LUCENT DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.
IN NO EVENT SHALL LUCENT OR ANY OF ITS ENTITIES BE LIABLE FOR ANY
SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF
THIS SOFTWARE.

****************************************************************/

/* Please send bug reports to David M. Gay (dmg at acm dot org,
 * with " at " changed at "@" and " dot " changed to ".").	*/

#include <_ansi.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "mprec.h"
#include "gdtoa.h"

#if defined (_HAVE_LONG_DOUBLE) && !defined (_LDBL_EQ_DBL) && __LDBL_MANT_DIG__ == 64

/* one or the other of IEEE_MC68k or IEEE_8087 should be #defined */

#ifdef IEEE_MC68k
#define _0 0
#define _1 1
#define _2 2
#define _3 3
#define _4 4
#endif
#ifdef IEEE_8087
#define _0 4
#define _1 3
#define _2 2
#define _3 1
#define _4 0
#endif

 void
#ifdef KR_headers
ULtox(L, bits, exp, k) __UShort *L; __ULong *bits; Long exp; int k;
#else
ULtox(__UShort *L, __ULong *bits, Long exp, int k)
#endif
{
	switch(k & STRTOG_Retmask) {
	  case STRTOG_NoNumber:
	  case STRTOG_Zero:
		L[0] = L[1] = L[2] = L[3] = L[4] = 0;
		break;

	  case STRTOG_Denormal:
		L[_0] = 0;
		goto normal_bits;

	  case STRTOG_Normal:
	  case STRTOG_NaNbits:
		L[_0] = exp + 0x3fff + 63;
 normal_bits:
		L[_4] = (__UShort)bits[0];
		L[_3] = (__UShort)(bits[0] >> 16);
		L[_2] = (__UShort)bits[1];
		L[_1] = (__UShort)(bits[1] >> 16);

		break;

	  case STRTOG_Infinite:
		L[_0] = 0x7fff;
		L[_1] = 0x8000;
		L[_2] = L[_3] = L[_4] = 0;
		break;

	  case STRTOG_NaN:
		*((long double*)L) = __builtin_nanl ("");
	  }
	if (k & STRTOG_Neg)
		L[_0] |= 0x8000;
	}

 int
#ifdef KR_headers
_strtorx_l(s, sp, rounding, L, loc) const char *s; char **sp; int rounding; void *L; locale_t loc;
#else
_strtorx_l(const char *s, char **sp, int rounding, void *L,
	   locale_t loc)
#endif
{
	static FPI fpi0 = { 64, 1-16383-64+1, 32766 - 16383 - 64 + 1, 1, SI };
	FPI *fpi, fpi1;
	__ULong bits[2];
	Long exp;
	int k;

	fpi = &fpi0;
	if (rounding != FPI_Round_near) {
		fpi1 = fpi0;
		fpi1.rounding = rounding;
		fpi = &fpi1;
		}
	k = _strtodg_l(s, sp, fpi, &exp, bits, loc);
	ULtox((__UShort*)L, bits, exp, k);
	return k;
	}

#endif /* _HAVE_LONG_DOUBLE && !_LDBL_EQ_DBL */

#include "dsp-lecture-q15.h"

void
add_vector_q15_fast(int n, int16_t* dst, int16_t* src1, int16_t* src2)
{
    int i;

    int16x4_t* src1x4 = (int16x4_t*)src1;
    int16x4_t* src2x4 = (int16x4_t*)src2;
    int16x4_t* dstx4 = (int16x4_t*)dst;

    for (i = 0; i < n - 3; i += 4) {
        assert((int16_t*)src1x4 == src1 + i);
        assert((int16_t*)src2x4 == src2 + i);
        assert((int16_t*)dstx4 == dst + i);

        *dstx4++ = __qadd16(*src1x4++, *src2x4++);
    }

    for (; i < n; i++) {
        dst[i] = q15_add_sat(src1[i], src2[i]);
    }
}
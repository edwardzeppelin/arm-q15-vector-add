#include "dsp-lecture-q15.h"

void
add_vector_q15_ref(int n, int16_t* dst, int16_t* src1, int16_t* src2)
{
    int i;
    for (i = 0; i < n; i++) {
        dst[i] = q15_add_sat(src1[i], src2[i]);
    }
}
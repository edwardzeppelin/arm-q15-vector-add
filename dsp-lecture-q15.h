#ifndef DSP_LECTURE_Q15_H
#define DSP_LECTURE_Q15_H

#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <arm_acle.h>
#include <arm_neon.h>

#define N_MAX 65535

typedef struct { int16_t real, imag; } cint16_t;
typedef struct { int32_t real, imag; } cint32_t;

void add_vector_q15(int n, int16_t* dst, int16_t* src1, int16_t* src2);
void add_vector_q15_ref(int n, int16_t* dst, int16_t* src1, int16_t* src2);
void add_vector_q15_fast(int n, int16_t* dst, int16_t* src1, int16_t* src2);
void add_vector_q15_tb(long int seed, unsigned runs);

static inline int16_t q15_add_sat(int16_t a, int16_t b) {
    int32_t result = (int32_t)a + (int32_t)b;

    if (result > 32767) return 32767;
    if (result < -32768) return -32768;

    return (int16_t)result;
}

#endif /* DSP_LECTURE_Q15_H */

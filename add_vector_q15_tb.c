#include "dsp-lecture-q15.h"
#include <stdio.h>
#include <stdlib.h>

void
random_vector_q15(int n, int16_t* v)
{
    int i;
    for (i = 0; i < n; i++) {
        v[i] = (int16_t)(mrand48() & 0xFFFF);
    }
}

void
add_vector_q15_tb(long int seed, unsigned runs)
{
    unsigned run;
    int i, n;

    int16_t* dst = NULL;
    int16_t* dst_ref = NULL;
    int16_t* src1 = NULL;
    int16_t* src2 = NULL;

    srand48(seed);

    for (run = 0; run < runs; run++) {
        n = lrand48() % N_MAX;

        dst = (int16_t*)realloc(dst, n * sizeof(int16_t));
        dst_ref = (int16_t*)realloc(dst_ref, n * sizeof(int16_t));
        src1 = (int16_t*)realloc(src1, n * sizeof(int16_t));
        src2 = (int16_t*)realloc(src2, n * sizeof(int16_t));

        random_vector_q15(n, src1);
        random_vector_q15(n, src2);

        printf("Test %u: n=%d, testing saturation cases...\n", run, n);

        if (n > 0) {
            src1[0] = 20000;
            src2[0] = 20000;

            src1[1] = -30000;
            src2[1] = -30000;
        }

        // Выполняем вычисления
        add_vector_q15_ref(n, dst_ref, src1, src2);
        add_vector_q15_fast(n, dst, src1, src2);

        // Проверяем результаты
        for (i = 0; i < n; i++) {
            if (dst[i] != dst_ref[i]) {
                fprintf(stderr, "Error at index %d: ref=0x%4.4x (%d) res=0x%4.4x (%d)\n",
                    i, dst_ref[i], dst_ref[i], dst[i], dst[i]);
                fprintf(stderr, "Inputs: src1=0x%4.4x (%d) src2=0x%4.4x (%d)\n",
                    src1[i], src1[i], src2[i], src2[i]);
                exit(1);
            }
        }
    }

    free(dst);
    free(dst_ref);
    free(src1);
    free(src2);

    printf("All tests passed! Q15 vector addition working correctly.\n");
}

int
main()
{
    add_vector_q15_tb(4711, 100);
    return 0;
}
# ARM Q15 Saturating Vector Addition

A C implementation of Q15 fixed-point vector addition with saturation, optimized for ARM targets using ACLE intrinsics (`__qadd16`). Includes a scalar reference version and a testbench that verifies saturation edge cases.

## Structure
* `add_vector_q15_fast.c` — SIMD-accelerated implementation using ARM intrinsics (`__qadd16`).
* `add_vector_q15_ref.c` — Standard scalar reference with Q15 saturation logic.
* `add_vector_q15.c` — Verification wrapper comparing reference and SIMD results.
* `add_vector_q15_tb.c` — Testbench validating saturation boundaries and random vectors.
* `dsp-lecture-q15.h` — DSP headers and inline `q15_add_sat` helper.

// Auto-generated file. Do not edit!
//   Template: src/f32-gemm/wasmsimd-loadsplat.c.in
//   Generator: tools/xngen
//
// Copyright 2020 Google LLC
//
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree.

#include <assert.h>

#include <wasm_simd128.h>

#include <xnnpack/gemm.h>


void xnn_f32_gemminc_minmax_ukernel_6x8__wasmsimd_loadsplat_x86(
    size_t mr,
    size_t nc,
    size_t kc,
    const float*restrict a,
    size_t a_stride,
    const float*restrict w,
    float*restrict c,
    size_t cm_stride,
    size_t cn_stride,
    const float*restrict acc,
    const union xnn_f32_minmax_params params[restrict XNN_MIN_ELEMENTS(1)])
{
  assert(mr != 0);
  assert(mr <= 6);
  assert(nc != 0);
  assert(kc != 0);
  assert(kc % sizeof(float) == 0);
  assert(a != NULL);
  assert(w != NULL);
  assert(c != NULL);
  assert(acc != NULL);

  const float* a0 = a;
  float* c0 = c;
  const float* a1 = (const float*) ((uintptr_t) a0 + a_stride);
  float* c1 = (float*) ((uintptr_t) c0 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 2) {
    a1 = a0;
    c1 = c0;
  }
  const float* a2 = (const float*) ((uintptr_t) a1 + a_stride);
  float* c2 = (float*) ((uintptr_t) c1 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 2) {
    a2 = a1;
    c2 = c1;
  }
  const float* a3 = (const float*) ((uintptr_t) a2 + a_stride);
  float* c3 = (float*) ((uintptr_t) c2 + cm_stride);
  if XNN_UNPREDICTABLE(mr < 4) {
    a3 = a2;
    c3 = c2;
  }
  const float* a4 = (const float*) ((uintptr_t) a3 + a_stride);
  float* c4 = (float*) ((uintptr_t) c3 + cm_stride);
  if XNN_UNPREDICTABLE(mr <= 4) {
    a4 = a3;
    c4 = c3;
  }
  const float* a5 = (const float*) ((uintptr_t) a4 + a_stride);
  float* c5 = (float*) ((uintptr_t) c4 + cm_stride);
  if XNN_UNPREDICTABLE(mr != 6) {
    a5 = a4;
    c5 = c4;
  }

  do {
    v128_t vacc0x0123 = wasm_v128_load(acc + 0);
    v128_t vacc0x4567 = wasm_v128_load(acc + 4);
    v128_t vacc1x0123 = wasm_v128_load(acc + 8);
    v128_t vacc1x4567 = wasm_v128_load(acc + 12);
    v128_t vacc2x0123 = wasm_v128_load(acc + 16);
    v128_t vacc2x4567 = wasm_v128_load(acc + 20);
    v128_t vacc3x0123 = wasm_v128_load(acc + 24);
    v128_t vacc3x4567 = wasm_v128_load(acc + 28);
    v128_t vacc4x0123 = wasm_v128_load(acc + 32);
    v128_t vacc4x4567 = wasm_v128_load(acc + 36);
    v128_t vacc5x0123 = wasm_v128_load(acc + 40);
    v128_t vacc5x4567 = wasm_v128_load(acc + 44);
    acc += 48;

    size_t k = kc;
    do {
      const v128_t va0 = wasm_v32x4_load_splat(a0);
      a0 += 1;
      const v128_t va1 = wasm_v32x4_load_splat(a1);
      a1 += 1;
      const v128_t va2 = wasm_v32x4_load_splat(a2);
      a2 += 1;
      const v128_t va3 = wasm_v32x4_load_splat(a3);
      a3 += 1;
      const v128_t va4 = wasm_v32x4_load_splat(a4);
      a4 += 1;
      const v128_t va5 = wasm_v32x4_load_splat(a5);
      a5 += 1;

      const v128_t vb0123 = wasm_v128_load(w);
      const v128_t vb4567 = wasm_v128_load(w + 4);
      w += 8;

      vacc0x0123 = wasm_f32x4_add(vacc0x0123, wasm_f32x4_mul(va0, vb0123));
      vacc1x0123 = wasm_f32x4_add(vacc1x0123, wasm_f32x4_mul(va1, vb0123));
      vacc2x0123 = wasm_f32x4_add(vacc2x0123, wasm_f32x4_mul(va2, vb0123));
      vacc3x0123 = wasm_f32x4_add(vacc3x0123, wasm_f32x4_mul(va3, vb0123));
      vacc4x0123 = wasm_f32x4_add(vacc4x0123, wasm_f32x4_mul(va4, vb0123));
      vacc5x0123 = wasm_f32x4_add(vacc5x0123, wasm_f32x4_mul(va5, vb0123));
      vacc0x4567 = wasm_f32x4_add(vacc0x4567, wasm_f32x4_mul(va0, vb4567));
      vacc1x4567 = wasm_f32x4_add(vacc1x4567, wasm_f32x4_mul(va1, vb4567));
      vacc2x4567 = wasm_f32x4_add(vacc2x4567, wasm_f32x4_mul(va2, vb4567));
      vacc3x4567 = wasm_f32x4_add(vacc3x4567, wasm_f32x4_mul(va3, vb4567));
      vacc4x4567 = wasm_f32x4_add(vacc4x4567, wasm_f32x4_mul(va4, vb4567));
      vacc5x4567 = wasm_f32x4_add(vacc5x4567, wasm_f32x4_mul(va5, vb4567));

      k -= sizeof(float);
    } while (k != 0);

    const v128_t vmax = wasm_v32x4_load_splat(&params->scalar.max);
    vacc0x0123 = wasm_v128_bitselect(vacc0x0123, vmax, wasm_f32x4_le(vacc0x0123, vmax));
    vacc1x0123 = wasm_v128_bitselect(vacc1x0123, vmax, wasm_f32x4_le(vacc1x0123, vmax));
    vacc2x0123 = wasm_v128_bitselect(vacc2x0123, vmax, wasm_f32x4_le(vacc2x0123, vmax));
    vacc3x0123 = wasm_v128_bitselect(vacc3x0123, vmax, wasm_f32x4_le(vacc3x0123, vmax));
    vacc4x0123 = wasm_v128_bitselect(vacc4x0123, vmax, wasm_f32x4_le(vacc4x0123, vmax));
    vacc5x0123 = wasm_v128_bitselect(vacc5x0123, vmax, wasm_f32x4_le(vacc5x0123, vmax));
    vacc0x4567 = wasm_v128_bitselect(vacc0x4567, vmax, wasm_f32x4_le(vacc0x4567, vmax));
    vacc1x4567 = wasm_v128_bitselect(vacc1x4567, vmax, wasm_f32x4_le(vacc1x4567, vmax));
    vacc2x4567 = wasm_v128_bitselect(vacc2x4567, vmax, wasm_f32x4_le(vacc2x4567, vmax));
    vacc3x4567 = wasm_v128_bitselect(vacc3x4567, vmax, wasm_f32x4_le(vacc3x4567, vmax));
    vacc4x4567 = wasm_v128_bitselect(vacc4x4567, vmax, wasm_f32x4_le(vacc4x4567, vmax));
    vacc5x4567 = wasm_v128_bitselect(vacc5x4567, vmax, wasm_f32x4_le(vacc5x4567, vmax));

    const v128_t vmin = wasm_v32x4_load_splat(&params->scalar.min);
    vacc0x0123 = wasm_v128_bitselect(vmin, vacc0x0123, wasm_f32x4_lt(vacc0x0123, vmin));
    vacc1x0123 = wasm_v128_bitselect(vmin, vacc1x0123, wasm_f32x4_lt(vacc1x0123, vmin));
    vacc2x0123 = wasm_v128_bitselect(vmin, vacc2x0123, wasm_f32x4_lt(vacc2x0123, vmin));
    vacc3x0123 = wasm_v128_bitselect(vmin, vacc3x0123, wasm_f32x4_lt(vacc3x0123, vmin));
    vacc4x0123 = wasm_v128_bitselect(vmin, vacc4x0123, wasm_f32x4_lt(vacc4x0123, vmin));
    vacc5x0123 = wasm_v128_bitselect(vmin, vacc5x0123, wasm_f32x4_lt(vacc5x0123, vmin));
    vacc0x4567 = wasm_v128_bitselect(vmin, vacc0x4567, wasm_f32x4_lt(vacc0x4567, vmin));
    vacc1x4567 = wasm_v128_bitselect(vmin, vacc1x4567, wasm_f32x4_lt(vacc1x4567, vmin));
    vacc2x4567 = wasm_v128_bitselect(vmin, vacc2x4567, wasm_f32x4_lt(vacc2x4567, vmin));
    vacc3x4567 = wasm_v128_bitselect(vmin, vacc3x4567, wasm_f32x4_lt(vacc3x4567, vmin));
    vacc4x4567 = wasm_v128_bitselect(vmin, vacc4x4567, wasm_f32x4_lt(vacc4x4567, vmin));
    vacc5x4567 = wasm_v128_bitselect(vmin, vacc5x4567, wasm_f32x4_lt(vacc5x4567, vmin));

    if XNN_LIKELY(nc >= 8) {
      wasm_v128_store(c5, vacc5x0123);
      wasm_v128_store(c5 + 4, vacc5x4567);
      c5 = (float*) ((uintptr_t) c5 + cn_stride);
      wasm_v128_store(c4, vacc4x0123);
      wasm_v128_store(c4 + 4, vacc4x4567);
      c4 = (float*) ((uintptr_t) c4 + cn_stride);
      wasm_v128_store(c3, vacc3x0123);
      wasm_v128_store(c3 + 4, vacc3x4567);
      c3 = (float*) ((uintptr_t) c3 + cn_stride);
      wasm_v128_store(c2, vacc2x0123);
      wasm_v128_store(c2 + 4, vacc2x4567);
      c2 = (float*) ((uintptr_t) c2 + cn_stride);
      wasm_v128_store(c1, vacc1x0123);
      wasm_v128_store(c1 + 4, vacc1x4567);
      c1 = (float*) ((uintptr_t) c1 + cn_stride);
      wasm_v128_store(c0, vacc0x0123);
      wasm_v128_store(c0 + 4, vacc0x4567);
      c0 = (float*) ((uintptr_t) c0 + cn_stride);

      a5 = (const float*) ((uintptr_t) a5 - kc);
      a4 = (const float*) ((uintptr_t) a4 - kc);
      a3 = (const float*) ((uintptr_t) a3 - kc);
      a2 = (const float*) ((uintptr_t) a2 - kc);
      a1 = (const float*) ((uintptr_t) a1 - kc);
      a0 = (const float*) ((uintptr_t) a0 - kc);

      nc -= 8;
    } else {
      if (nc & 4) {
        wasm_v128_store(c5, vacc5x0123);
        wasm_v128_store(c4, vacc4x0123);
        wasm_v128_store(c3, vacc3x0123);
        wasm_v128_store(c2, vacc2x0123);
        wasm_v128_store(c1, vacc1x0123);
        wasm_v128_store(c0, vacc0x0123);

        vacc5x0123 = vacc5x4567;
        vacc4x0123 = vacc4x4567;
        vacc3x0123 = vacc3x4567;
        vacc2x0123 = vacc2x4567;
        vacc1x0123 = vacc1x4567;
        vacc0x0123 = vacc0x4567;

        c5 += 4;
        c4 += 4;
        c3 += 4;
        c2 += 4;
        c1 += 4;
        c0 += 4;
      }
      if (nc & 2) {
        *((double*) c5) = wasm_f64x2_extract_lane(vacc5x0123, 0);
        *((double*) c4) = wasm_f64x2_extract_lane(vacc4x0123, 0);
        *((double*) c3) = wasm_f64x2_extract_lane(vacc3x0123, 0);
        *((double*) c2) = wasm_f64x2_extract_lane(vacc2x0123, 0);
        *((double*) c1) = wasm_f64x2_extract_lane(vacc1x0123, 0);
        *((double*) c0) = wasm_f64x2_extract_lane(vacc0x0123, 0);

        vacc5x0123 = wasm_v32x4_shuffle(vacc5x0123, vacc5x0123, 2, 3, 2, 3);
        vacc4x0123 = wasm_v32x4_shuffle(vacc4x0123, vacc4x0123, 2, 3, 2, 3);
        vacc3x0123 = wasm_v32x4_shuffle(vacc3x0123, vacc3x0123, 2, 3, 2, 3);
        vacc2x0123 = wasm_v32x4_shuffle(vacc2x0123, vacc2x0123, 2, 3, 2, 3);
        vacc1x0123 = wasm_v32x4_shuffle(vacc1x0123, vacc1x0123, 2, 3, 2, 3);
        vacc0x0123 = wasm_v32x4_shuffle(vacc0x0123, vacc0x0123, 2, 3, 2, 3);

        c5 += 2;
        c4 += 2;
        c3 += 2;
        c2 += 2;
        c1 += 2;
        c0 += 2;
      }
      if (nc & 1) {
        *c5 = wasm_f32x4_extract_lane(vacc5x0123, 0);
        *c4 = wasm_f32x4_extract_lane(vacc4x0123, 0);
        *c3 = wasm_f32x4_extract_lane(vacc3x0123, 0);
        *c2 = wasm_f32x4_extract_lane(vacc2x0123, 0);
        *c1 = wasm_f32x4_extract_lane(vacc1x0123, 0);
        *c0 = wasm_f32x4_extract_lane(vacc0x0123, 0);
      }

      nc = 0;
    }
  } while (nc != 0);
}

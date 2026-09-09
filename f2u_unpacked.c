#include <stdio.h>

/* 
 * f2u - Return bit-level representation of a single-precision float.
 * (Takes a float, returns its unsigned bit pattern via pointer casting)
 */
unsigned f2u(float x) {
  return *(unsigned *)&x;
}

/* 
 * u2f - Return the single-precision float matching an unsigned bit pattern.
 * (Takes an unsigned integer, returns it as a float via pointer casting)
 */
float u2f(unsigned u) {
  return *(float *)&u;
}

/* 
 * unpack_float - Extracts and prints the IEEE 754 fields from a float.
 */
void unpack_float(float x) {
  unsigned bits = f2u(x);

  // Mask and shift to isolate fields
  unsigned sign = (bits >> 31) & 0x1;
  unsigned exp  = (bits >> 23) & 0xFF;
  unsigned frac = bits & 0x7FFFFF;

  // Print results
  printf("Float value: %e (or NaN/Inf)\n", x);
  printf("  Full Bits: 0x%08X\n", bits);
  printf("  Sign (s) : %u\n", sign);
  printf("  Exp (exp): 0x%02X (%u)\n", exp, exp);
  printf("  Frac(frac): 0x%06X\n", frac);
  printf("\n");
}


int main() {
  printf("--- Unpacking IEEE 754 Floating-Point Fields ---\n\n");

  // Test Case 1: Simple Positive Integer
  unpack_float(1.0f);

  // Test Case 2: Negative Fractional Number
  unpack_float(-0.75f);

  // Test Case 3: Representation of Zero
  unpack_float(0.0f);

  // Test Case 4: Special Value (Positive Infinity)
  // 1.0f / 0.0f yields infinity in IEEE 754
  unpack_float(1.0f / 0.0f);

  // Test Case 5: Denormalized Number via u2f
  float denorm_float = u2f(0x00000200);
  unpack_float(denorm_float);

  // Test Case 6: Not-a-Number (NaN) via u2f
  float nan_float = u2f(0x7FC00000);
  unpack_float(nan_float);

  float very_small = 1e-20;
  unpack_float(very_small);

  float very_very_small = very_small * very_small;
  unpack_float(very_very_small);

  return 0;
}

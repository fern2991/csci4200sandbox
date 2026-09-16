#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

// The standard byte_pointer typedef from CS:APP
typedef unsigned char *byte_pointer;

/* Prints each byte's index, memory address, hex value, and bit layout */
void show_bytes_and_bits(byte_pointer start, size_t len) {
    // Print a clean, aligned table header
    printf("%-7s | %-18s | %-4s | %-8s\n", "Byte #", "Memory Address", "Hex", "Bits (MSB->LSB)");
    printf("-------------------------------------------------------------\n");

    // Iterate through each byte following host system endianness
    for (size_t i = 0; i < len; i++) {
        byte_pointer current_byte_addr = start + i;
        unsigned char byte_val = *current_byte_addr;

        // 1. Print the byte index, its exact memory pointer, and its 2-digit hex value
        printf("Byte %-2zu | 0x%016lx | 0x%02x | ", i, (uintptr_t)current_byte_addr, byte_val);

        // 2. Print the bit representation for this specific byte (MSB to LSB)
        for (int bit = 7; bit >= 0; bit--) {
            int bit_val = (byte_val >> bit) & 1;
            printf("%d", bit_val);

            if (bit == 4) { printf("_"); }
        }
        
        printf("\n");
    }
}

/* Wrapper functions matching CS:APP styling */

void show_char_combined(char x) {
    printf("--- Analyzing Char: '%c' (Size: %zu byte) ---\n", x, sizeof(char));
    show_bytes_and_bits((byte_pointer) &x, sizeof(char));
    printf("\n");
}

void show_int_combined(int x) {
    printf("--- Analyzing Integer: %d (Size: %zu bytes) ---\n", x, sizeof(int));
    show_bytes_and_bits((byte_pointer) &x, sizeof(int));
    printf("\n");
}

void show_unsigned_combined(unsigned x) {
    printf("--- Analyzing Unsigned: %u (Size: %zu bytes) ---\n", x, sizeof(unsigned));
    show_bytes_and_bits((byte_pointer) &x, sizeof(unsigned));
    printf("\n");
}

void show_float_combined(float x) {
    printf("--- Analyzing Float: %.1f (Size: %zu bytes) ---\n", x, sizeof(float));
    show_bytes_and_bits((byte_pointer) &x, sizeof(float));
    printf("\n");
}

void show_double_combined(double x) {
    printf("--- Analyzing Double: %.1f (Size: %zu bytes) ---\n", x, sizeof(double));
    show_bytes_and_bits((byte_pointer) &x, sizeof(double));
    printf("\n");
}
int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /* Give an expression using only ux, uy, sx, and sy */
    return (sx > sy) || (ux <= uy);
}
int main() {
    // char test_char = 'A';
    // int test_int = 1;
    // unsigned test_unsigned = 4294967295U; // Maximum 32-bit unsigned int (0xFFFFFFFF)
    // float test_float = 1.0;
    // double test_double = 1.0;

    // show_char_combined(test_char);
    // show_int_combined(test_int);
    // show_unsigned_combined(test_unsigned);
    // show_float_combined(test_float);
    // show_double_combined(test_double);

    // unsigned val = 0x89ABCDEF;
    // show_unsigned_combined(val);

    // unsigned mask = 0xFF;
    // unsigned byte0 = val & mask;
    // show_unsigned_combined(byte0);

    // mask = mask << 8;
    // unsigned byte1 = (val & mask) >> 8;
    // show_unsigned_combined(byte1);

    // mask = mask << 8;
    // unsigned byte2 = (val & mask) >> 16;
    // show_unsigned_combined(byte2);

    // mask = mask << 8;
    // unsigned byte3 = (val & mask) >> 24;
    // show_unsigned_combined(byte3);

    // unsigned combined = (byte3 << 24) | (byte2 << 16) | (byte1 << 8) | byte0;
    // show_unsigned_combined(combined);
    printf("%d", float_le(2.9, 5.6));
    return 0;
}

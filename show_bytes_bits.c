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

int main() {
    char test_char = 'A';
    int test_int = 1;
    unsigned test_unsigned = 4294967295U; // Maximum 32-bit unsigned int (0xFFFFFFFF)
    float test_float = 1.0;
    double test_double = 1.0;

    show_char_combined(test_char);
    show_int_combined(test_int);
    show_unsigned_combined(test_unsigned);
    show_float_combined(test_float);
    show_double_combined(test_double);

    return 0;
}

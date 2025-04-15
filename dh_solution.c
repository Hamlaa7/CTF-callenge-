#include <stdio.h>
#include <stdlib.h>

#define PRIME 23
#define BASE 5

unsigned long long mod_pow(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    unsigned long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

int discrete_log(unsigned long long base, unsigned long long target, unsigned long long mod) {
    for (int x = 1; x < mod; x++) {
        if (mod_pow(base, x, mod) == target) {
            return x;
        }
    }
    return -1;
}

int main() {
    unsigned long long public_a = 4;
    unsigned long long public_b = 17; 

    int private_a = discrete_log(BASE, public_a, PRIME);
    if (private_a == -1) {
        printf("Error: Could not compute private_a\n");
        return 1;
    }
    printf("Computed private_a: %d\n", private_a);

    unsigned long long shared_secret = mod_pow(public_b, private_a, PRIME);
    printf("Shared Secret: %llu\n", shared_secret);

    int private_b = discrete_log(BASE, public_b, PRIME);
    if (private_b == -1) {
        printf("Error: Could not compute private_b\n");
        return 1;
    }
    unsigned long long secret_verify = mod_pow(public_a, private_b, PRIME);
    printf("Verification Shared Secret: %llu\n", secret_verify); // Should be 8

    return 0;
}
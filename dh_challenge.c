// #include <stdio.h>
// #include <stdlib.h>

// #define PRIME 23
// #define BASE 5

// unsigned long long mod_pow(unsigned long long base, unsigned long long exp, unsigned long long mod) {
//     unsigned long long result = 1;
//     base %= mod;
//     while (exp > 0) {
//         if (exp & 1) result = (result * base) % mod;
//         base = (base * base) % mod;
//         exp >>= 1;
//     }
//     return result;
// }

// int main() {
//     int private_a = 4;  // 5^4 % 23 = 4
//     int private_b = 7;  // 5^7 % 23 = 8

//     unsigned long long public_a = mod_pow(BASE, private_a, PRIME); // 4
//     unsigned long long public_b = mod_pow(BASE, private_b, PRIME); // 8
//     unsigned long long secret_a = mod_pow(public_b, private_a, PRIME); // 8^4 % 23 = 2

//     printf("Public A: %llu\n", public_a);
//     printf("Public B: %llu\n", public_b);
//     printf("Secret: %llu\n", secret_a);

//     return 0;
// }


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

int main() {
    int private_a = 4;  // 5^4 % 23 = 4
    int private_b = 7;  // 5^7 % 23 = 17

    unsigned long long public_a = mod_pow(BASE, private_a, PRIME); // 4
    unsigned long long public_b = mod_pow(BASE, private_b, PRIME); // 17
    // Compute secret but don’t print it
    unsigned long long secret_a = mod_pow(public_b, private_a, PRIME); // 8

    printf("Public A: %llu\n", public_a);
    printf("Public B: %llu\n", public_b);
    // Optionally hint at the prime: printf("Modulus: %d\n", PRIME);

    return 0;
}
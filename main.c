//
//  main.c
//  RSA
//
//  Created by Calum Boal on 21/10/2016.
//  Copyright © 2016 Calum Boal. All rights reserved.
//
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint8_t getRandom();
int isPrime(uint8_t);
uint8_t randomPrime();

int main(int argc, const char * argv[]) {
    /*uint8_t p = getRandom();
    uint8_t q = getRandom();
    int n = p * q;
    int t = (p - 1) * (q - 1);
    */
    uint8_t p = randomPrime();
    printf("%d", p);
}

uint8_t getRandom() {
    FILE* randSource;
    randSource = fopen("/dev/urandom", "r");
    uint8_t rand;
    fread(&rand, 1, sizeof(rand), randSource);
    fclose(randSource);
    return rand;
}

int isPrime(uint8_t n) {
    for (int m = 2; m < n; m++) {
        if (n % m == 0) {
            return 0;
        }
    }
    return 1;
}

uint8_t randomPrime() {
    int i = 0;
    uint8_t randNum;
    while (i == 0) {
        randNum = getRandom();
        if (isPrime(randNum) > 0) {
            i++;
        }
    }
    return randNum;
}

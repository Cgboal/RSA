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
#include <math.h>

int getRandom();
int isPrime(int);
int randomPrime(int);
int intLog2(int);

int main(int argc, const char * argv[]) {
    int p = randomPrime(255);
    int q = randomPrime(255);
    int n = p * q;
    int t = (p - 1) * (q - 1);
    int e = randomPrime(255);


    printf("%d", intLog2(122));
}

int getRandom() {
    FILE* randSource;
    randSource = fopen("/dev/urandom", "r");
    int rand;
    fread(&rand, 1, sizeof(uint8_t), randSource);
    fclose(randSource);
    return rand;
}

int isPrime(int n) {
    for (int m = 2; m < n; m++) {
        if (n % m == 0) {
            return 0;
        }
    }
    return 1;
}

int randomPrime(int max) {
    int i = 0;
    int randNum;
    do {
        randNum = getRandom();
    } while (randNum > max || randNum <= 0);
    while (i == 0) {
        randNum = getRandom();
        if (isPrime(randNum) > 0) {
            i++;
        }
    }
    return randNum;
}

int intLog2(int n) {
    int c = 2;
    int i = 1;
    do {
        c *= 2;
        i++;
    } while (c < n);
    return i;
}

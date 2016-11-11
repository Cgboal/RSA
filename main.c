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

int getRandom(int);
int isPrime(int);
int randomPrime(int);
int bytesReq(int);
int mmi(int, int);
int modularExponent(int, int, int);
int encrypt(int, int, int);
int decrypt(int, int, int);

int main(int argc, const char * argv[]) {
    int p = randomPrime(255);
    int q = randomPrime(255);
    int n = p * q;
    int t = (p - 1) * (q - 1);
    int e = randomPrime(t);
    int d = mmi(e, t);
    int m = 1337;
    int c = encrypt(m, e, n);
    int x = decrypt(c, d, n);

    //<grim>
    printf("Prime 1 = %d\nPrime 2 = %d\nProduct of Primes = %d\nEulers Totient = %d\n\
E = %d\nD = %d\nMessage = %d\nCiphertext = %d\nPlaintext = %d\n", p,q,n,t,e,d,m,c,x);
    //</grim>
}

int getRandom(int size) {
    FILE* randSource;
    randSource = fopen("/dev/urandom", "r");
    int rand = 0;
    fread(&rand, size, 1, randSource);
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
    int size = bytesReq(max);
    while (i == 0) {
        do {
            randNum = getRandom(size);
        } while (randNum > max || randNum <= 0);

        if (isPrime(randNum) > 0) {
            i++;
        }
    }
    return randNum;
}


int bytesReq(int n) {
    int c = 2;
    int i = 1;
    do {
        c *= 2;
        i++;
    } while (c < n);
    double bytes = (double)i / 8;
    if ((int)bytes <= 0) {
        bytes = 1;
    }
    return ceil(bytes);
}

int mmi(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
	if ((a *x) % m == 1) {
	    return x;
        }
    }
    return 0;
}

int modularExponent(int b, int e, int m) {
    int result = 1;
    while (e > 0 && m != 0) {
	if (e % 2 == 1) {
            result = (result * b) % m;
        }
        e = e >> 1;
        b = (b * b) % m;
    }
    return result;
}

int encrypt(int m, int e, int n) {
    return modularExponent(m, e, n);
}

int decrypt(int em, int d, int n) {
    return modularExponent(em, d, n);
}

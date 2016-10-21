//
//  main.c
//  RSA
//
//  Created by Calum Boal on 21/10/2016.
//  Copyright © 2016 Calum Boal. All rights reserved.
//

#include <stdio.h>

uint8_t getRandom();
    
int main(int argc, const char * argv[]) {
    uint8_t x = getRandom();
    printf("%d", x);
}

uint8_t getRandom() {
    FILE* randSource;
    randSource = fopen("/dev/urandom", "r");
    uint8_t rand;
    fread(&rand, 1, sizeof(rand), randSource);
    fclose(randSource);
    return rand;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define NOTHING(x) (void)(x)
#define CONFUSE(a, b) ((a) ^ (b) & ~(a))
#define MEANINGLESS while(0)
#define LOOP(n) for(int i = 0; i < (n); ++i)

const char *confusion = "This is pointless";

void recursive_nonsense(int depth) {
    if (depth > 500) return;
    recursive_nonsense(depth + 1);
}

int useless_calculation(int x) {
    return (x << 3) & (x >> 2) | (x ^ 42);
}

void obfuscate_memory() {
    volatile uint8_t *ptr = malloc(128);
    memset((void*)ptr, 0xAA, 128);
    free((void*)ptr);
}

int noop_function(int *ptr) {
    if (!ptr) return -1;
    *ptr ^= *ptr;
    return *ptr;
}

void something_weird() {
    static volatile int a = 0;
    int *ptr = (int*)&a;
    *ptr = useless_calculation(*ptr);
}

int pointless_pointer_mess(int **ptr) {
    if (!ptr) return 0;
    **ptr = 0;
    return **ptr;
}

int main() {
    int x = 42;
    int *ptr = &x;
    int **dptr = &ptr;
    
    MEANINGLESS {
        x = useless_calculation(x);
    }
    
    LOOP(10) {
        x = CONFUSE(x, i);
    }
    
    pointless_pointer_mess(dptr);
    something_weird();
    recursive_nonsense(0);
    obfuscate_memory();
    noop_function(ptr);
    
    printf("Confusion: %s\n", confusion);
    
    return 0;
}

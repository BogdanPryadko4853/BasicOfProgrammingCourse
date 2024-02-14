#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"

vector v;

bool test_pushBack_emptyVector(vector* v) {
    return isEmpty(v);
}

bool test_pushBack_fullVector(vector* v) {
    return isFull(v);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test(vector* v) {
    printf("Is empty: %d\n", test_pushBack_emptyVector(v));
    printf("Is full: %d\n", test_pushBack_fullVector(v));
}

int main() {
    v = createVector(5);
    test(&v);
    pushBack(&v, 5);
    test(&v);
    return 0;
}

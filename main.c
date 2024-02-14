#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"
#include "libs/data_structures/vector/vectorVoid.h"

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

void test_atVector_notEmptyVector() {
    vector v;
    int data[] = {1, 2, 3, 4, 5};
    v.data = data;
    v.size = sizeof(data) / sizeof(data[0]);

    for (size_t i = 0; i < v.size; i++) {
        int* element = atVector(&v, i);
        assert(*element == data[i]);
    }

    printf("test_atVector_notEmptyVector passed.\n");
}

void test_atVector_requestToLastElement() {
    vector v;
    int data[] = {1, 2, 3, 4, 5};
    v.data = data;
    v.size = sizeof(data) / sizeof(data[0]);

    int* lastElement = atVector(&v, v.size - 1);
    assert(*lastElement == data[v.size - 1]);

    printf("test_atVector_requestToLastElement passed.\n");
}

void test_back_oneElementInVector() {
    vector v;
    int data[] = {42};
    v.data = data;
    v.size = sizeof(data) / sizeof(data[0]);

    int* lastElement = back(&v);
    assert(*lastElement == data[0]);

    printf("test_back_oneElementInVector passed.\n");
}

void test_front_oneElementInVector() {
    vector v;
    int data[] = {42};
    v.data = data;
    v.size = sizeof(data) / sizeof(data[0]);

    int* firstElement = front(&v);
    assert(*firstElement == data[0]);

    printf("test_front_oneElementInVector passed.\n");
}

void test(vector* v) {
    printf("Is empty: %d\n", test_pushBack_emptyVector(v));
    printf("Is full: %d\n", test_pushBack_fullVector(v));
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
    test_popBack_notEmptyVector();
}

int main() {
    size_t n;
    scanf("%zd", &n);
    vectorVoid v = createVectorV(0, sizeof(int));
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        pushBackV(&v, &x);
    }
    for (int i = 0; i < n; i++) {
        int x;
        getVectorValueV(&v, i, &x);
        printf("%d ", x);
    }
    return 0;
}

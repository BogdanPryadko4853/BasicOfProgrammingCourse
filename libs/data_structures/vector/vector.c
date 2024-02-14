#include "vector.h"
#include <stdio.h>
#include <stdlib.h>


vector createVector(size_t n) {
    vector vec;
    vec.size = n;
    vec.capacity = n > 0 ? n : 1; // Устанавливаем вместимость как минимум 1, если n = 0
    vec.data = (int *)malloc(vec.capacity * sizeof(int)); // Выделяем память под массив

    if (vec.data == NULL) {
        fprintf(stderr, "bad alloc\n");
        exit(1);
    }

    return vec;
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity == 0) {
        free(v->data);
        v->data = NULL;
    } else if (newCapacity < v->size) {
        v->size = newCapacity;
    }

    void *newData = realloc(v->data, newCapacity * sizeof(int));
    if (newData == NULL && newCapacity != 0) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    v->data = newData;
    v->capacity = newCapacity;
}

void clear(vector *v) {v->size = 0;}

void shrinkToFit(vector *v) {
    if (v->size < v->capacity) {
        v->capacity = v->size;
        v->data = (int *) realloc(v->data, v->capacity * sizeof(int));
    }
}
void deleteVector(vector *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}
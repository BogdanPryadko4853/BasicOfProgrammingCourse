#include <stdlib.h>
#include <string.h>
#include "vectorVoid.h"


vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    vectorVoid v;
    v.data = malloc(n * baseTypeSize);
    v.size = n;
    v.capacity = n;
    v.baseTypeSize = baseTypeSize;
    return v;
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity > v->capacity) {
        void *newData = realloc(v->data, newCapacity * v->baseTypeSize);
        if (newData) {
            v->data = newData;
            v->capacity = newCapacity;
        }
    }
}

void shrinkToFitV(vectorVoid *v) {
    if (v->size < v->capacity) {
        void *newData = realloc(v->data, v->size * v->baseTypeSize);
        if (newData) {
            v->data = newData;
            v->capacity = v->size;
        }
    }
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

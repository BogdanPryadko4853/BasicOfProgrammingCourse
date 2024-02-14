//
// Created by Bogdan on 14.02.2024.
//

#ifndef LAB14_VECTORVOID_H
#define LAB14_VECTORVOID_H

#include <limits.h>
typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

vectorVoid createVectorV(size_t n, size_t baseTypeSize);

void reserveV(vectorVoid *v, size_t newCapacity);

void shrinkToFitV(vectorVoid *v);

void clearV(vectorVoid *v);

void deleteVectorV(vectorVoid *v);

#endif //LAB14_VECTORVOID_H

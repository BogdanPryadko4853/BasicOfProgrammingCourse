//
// Created by Bogdan on 09.02.2024.
//

#ifndef LAB14_VECTOR_H
#define LAB14_VECTOR_H

#include <corecrt.h>

typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

#endif //LAB14_VECTOR_H

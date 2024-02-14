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

vector createVector(size_t n);// возвращает структуру-дескриптор вектор из n значений.

void reserve(vector *v, size_t newCapacity);//изменяет количество памяти, выделенное под хранение элементов вектора.

void clear(vector *v);//удаляет элементы из контейнера, но не освобождает выделенную память.

void shrinkToFit(vector *v);//освобождает память, выделенную под неиспользуемые элементы

void deleteVector(vector *v);//освобождает память, выделенную вектору

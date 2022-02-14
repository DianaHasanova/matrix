//
// Created by Дианочка on 16.12.2021.
//

#ifndef UNTITLED4_ARRAY_H
#define UNTITLED4_ARRAY_H

#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <stddef.h>

//ввод массива a размера n
void inputArray_(int *a, size_t n);

//вывод массива a размера n
void outputArray_(const int *a, size_t n);

//возвращает значение первого вхождения элемента x
//в массиве a размера n при его наличии, иначе - n
size_t linearSearch_(const int *a, const size_t n, int x);

//возвращает позицию вхождения элемента x
//в отсортированном массиве a размера n при его наличии, иначе - SIZE_MAX
size_t binarySearch_(const int *a, const size_t n, int x);

//возвращает позицию первого элемента равного или большего x
//в отсортированном массиве a размера n
//при отсутствии такого элемента возвращает n
size_t binarySearchMoreOrEqual_(const int *a, const size_t n, int x);

//вставка элемента со значением value
//в массив a размера n на позицию pos
void insert_(int *a, size_t *n, size_t pos, int value);

//добавление элемента value в конец массива a размера n
void append_(int *a, size_t *n, int value);

//удаление из массива a размера n элемента на позиции pos
//с сохранением порядка оставшихся элементов
void deleteByPosSaveOrder_(int *a, size_t *n, size_t pos);

//удаление из массива a размера n элемента на позиции pos
//без сохранения порядка оставшихся элементов
//размер массива a уменьшается на единицу
void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos);

//возвращает значение ’истина’ если все элементы
//массива a размера n соответствует функции-предикату predicate
//иначе - ’ложь’
int all_(const int *a, size_t n, int (*predicate )(int));

//возвращает значение ’истина’ если хотя бы один элемент
//массива a размера n соответствует функции-предикату predicate
//иначе - ’ложь’
int any_(const int *a, size_t n, int (*predicate )(int));

//применяет функцию predicate ко всем элементам массива source
//размера n и сохраняет результат в массиве dest размера n
void forEach_(const int *source, int *dest, size_t n, const int (*predicate )(int));

//возвращает количество элементов массива a размера n
//удовлетворяющих функции-предикату predicate
int countIf_(const int *a, size_t n, int (*predicate )(int));

//удаляет из массива a размера n все элементы, удовлетворяющие
//функции-предикату deletePredicate, записывает в n новый размер
//массива
void deleteIf_(int *a, size_t *n, int (*deletePredicate )(int));

//обменивает значения по адресам а и b
void swapInt(int *a, int *b);

//осуществляет обмен значений переменных размера size по адресам а и b
void general_swap(void *a, void *b, size_t size);



#endif //UNTITLED4_ARRAY_H

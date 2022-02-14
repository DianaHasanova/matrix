#include <assert.h>
#include "libs/data_structures/unordered_array_set/unordered_array_set.h"
#include "libs/data_structures/matrix/matrix.h"

void test_unordered_array_set_in1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert(unordered_array_set_in(&set, 3) == 2);
    unordered_array_set_delete(set);
}

void test_unordered_array_set_in2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert(unordered_array_set_in(&set, 12) == 3);
    unordered_array_set_delete(set);
}

void test_in() {
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
}

void test_unordered_array_set_isEqual1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {3, 1, 2}, 3);
    assert(unordered_array_set_isEqual(set1, set2) == 1);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isEqual2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 4}, 3);
    assert(unordered_array_set_isEqual(set1, set2) == 0);
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
}

void test_unordered_array_set_isEqual() {
    test_unordered_array_set_isEqual1();
    test_unordered_array_set_isEqual2();
}

void test_unordered_array_set_deleteElement1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2, 3, 56, 17}, 5);
    unordered_array_set resSet = unordered_array_set_create_from_array((int[]) {1, 2, 3, 56, 17}, 5);
    unordered_array_set_deleteElement(&set, 5);
   // unordered_array_set_print(set);
    assert(unordered_array_set_isEqual(set, resSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(resSet);
}

void test_unordered_array_set_deleteElement2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2, 3, 56, 17}, 5);
    unordered_array_set resSet = unordered_array_set_create_from_array((int[]) {1, 2, 3, 17}, 4);
    unordered_array_set_deleteElement(&set, 56);
    assert(unordered_array_set_isEqual(set, resSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(resSet);
}

void test_deleteElement() {
    test_unordered_array_set_deleteElement1();
    test_unordered_array_set_deleteElement2();
}


void test_unordered_array_set_union1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {3, 2, 4, 5}, 4);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}


void test_unordered_array_set_union2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {3, 1, 4}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 3}, 2);
    unordered_array_set resSet = unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {3, 1, 4}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
}

void test_unordered_array_set_intersection1() {
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 6, 10}, 6);
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {1, 4, 6}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection2() {
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 4, 2, 7}, 4);
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 3, 56, 19, 78, 9}, 6);
    unordered_array_set resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2}, 1);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_intersection() {
    test_unordered_array_set_intersection1();
    test_unordered_array_set_intersection2();
}

void test_unordered_array_set_difference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 6}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 4, 5, 6}, 4);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {5, 6, 8, 10}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {1, 4, 10, 7}, 4);
    unordered_array_set resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {5, 6, 8}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_difference() {
    test_unordered_array_set_difference1();
    test_unordered_array_set_difference2();
}

void unordered_array_set_symmetricDifference1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {99, 2, 3}, 3);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {6, 4, 5, 1}, 4);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {6, 4, 5, 1, 99, 2, 3}, 7);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void unordered_array_set_symmetricDifference2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3, 5}, 4);
    unordered_array_set set2 = unordered_array_set_create_from_array((int[]) {6, 4, 5, 1}, 4);
    unordered_array_set resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {6, 4, 2, 3}, 4);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_symmetricDifference() {
    unordered_array_set_symmetricDifference1();
    unordered_array_set_symmetricDifference2();
}

void test_unordered_array_set_complement1() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set universumSet = unordered_array_set_create_from_array((int[]) {4, 5, 1, 2}, 4);
    unordered_array_set resSet = unordered_array_set_complement(set, universumSet);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {4, 5}, 2);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(universumSet);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);

}

void test_unordered_array_set_complement2() {
    unordered_array_set set = unordered_array_set_create_from_array((int[]) {5}, 1);
    unordered_array_set universumSet = unordered_array_set_create_from_array((int[]) {4, 5, 1, 2}, 4);
    unordered_array_set resSet = unordered_array_set_complement(set, universumSet);
    unordered_array_set expectedSet = unordered_array_set_create_from_array((int[]) {4, 1, 2}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set);
    unordered_array_set_delete(universumSet);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_complement() {
    test_unordered_array_set_complement1();
    test_unordered_array_set_complement2();
}

void test_array() {
    test_in();
    test_unordered_array_set_isEqual();
    test_deleteElement();
    test_union();
    test_intersection();
    test_difference();
    test_symmetricDifference();
    test_complement();
}

int main() {
   // test_array();

    return 0;
}
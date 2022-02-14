//
// Created by Дианочка on 16.12.2021.
//

#include "bitset.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

bitset bitset_create(unsigned maxValue) {
    assert (maxValue < 32);
    return (bitset) {0, maxValue};
}

bool bitset_check_value(bitset set, unsigned value) {
    return value >= 0 && value <= set.maxValue;
}

bool bitset_in(bitset set, unsigned int value) {
    assert(bitset_check_value(set, value));
    return set.values >> value & 1;
}

bool bitset_isEqual(bitset set1, bitset set2) {
    return set1.values == set2.values;
}

bool bitset_isSubset(bitset subset, bitset set) {
    return (subset.values & set.values) == set.values;
}

void bitset_insert(bitset *set, unsigned int value) {
    assert(bitset_check_value(*set, value));
    set->values |= 1 << value;
}

void bitset_deleteElement(bitset *set, unsigned int value) {
    assert(bitset_check_value(*set, value));
    set->values &= ~(1 << value);
}

bitset bitset_union(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values | set2.values, set1.maxValue};
}

bitset bitset_intersection(bitset set1, bitset set2) {
    assert(set1.maxValue == set2.maxValue);
    return (bitset) {set1.values & set2.values, set1.maxValue};
}

bitset bitset_difference(bitset set1, bitset set2) {
    assert(bitset_check_value(set1, set1.maxValue));
    assert(bitset_check_value(set2, set2.maxValue));
    return (bitset) {set1.values & ~set2.values};
}

bitset bitset_symmetricDifference(bitset set1, bitset set2) {
    assert(bitset_check_value(set1, set1.maxValue));
    assert(bitset_check_value(set2, set2.maxValue));
    return (bitset) {(set1.values & ~set2.values) & (set2.values & ~set1.values)};
}

bitset bitset_complement(bitset set) {
    unsigned numberFromUnitToMaxValues = pow(2, set.maxValue) - 1;
    return (bitset) {numberFromUnitToMaxValues & ~set.values, set.maxValue};
}

void bitset_print(bitset set) {
    printf("{");
    int isEmpty = 1;
    for (int i = 0; i <= set.maxValue; i++) {
        if (bitset_in(set, i)) {
            printf("%d, ", i);
            isEmpty = 0;
        }
    }
    if (isEmpty)
        printf("}\n");
    else
        printf("\b\b}\n");
}
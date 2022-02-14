add_library(data_structures
        bitset/bitset.c
        ordered_array_set/ordered_array_set.c
        unordered_array_set/unordered_array_set.c
        matrix/matrix.c)

target_link_libraries(data_structures algorithms)
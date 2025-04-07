#define ARENA_IMP
#include "arena.h"

int main() {
    Arena* arena = alloc_arena();

    // Example values to insert
    char cs[] = {'A', 'B', 'C'};
    int is[] = {1, 2, 3};
    float fs[] = {1.1f, 2.2f};
    double ds[] = {9.9, 8.8, 7.7, 6.6};
    unsigned int us[] = {100, 200, 300};

    // Create 10 regions of various types
    append_data(arena, CHAR, cs, 3);      // 1
    append_data(arena, INT, is, 3);       // 2
    append_data(arena, FLOAT, fs, 2);     // 3
    append_data(arena, DOUBLE, ds, 4);    // 4
    append_data(arena, UINT, us, 3);      // 5

    // Reuse types to force new regions
    append_data(arena, CHAR, cs, 3);      // 6
    append_data(arena, INT, is, 3);       // 7
    append_data(arena, FLOAT, fs, 2);     // 8
    append_data(arena, DOUBLE, ds, 4);    // 9
    append_data(arena, UINT, us, 3);      // 10

    // Print everything
    arena_print(arena);

    // Cleanup
    arena_free(arena);
    return 0;
}

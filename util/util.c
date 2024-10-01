#include "util.h"
#include <stdbool.h>

int findTargetIndex(int array[SIZE], int current_index, int stop) {
    if (current_index == 0) {
        return current_index;
    }

    for (int target_index = current_index - 1; target_index >= 0; target_index--) {
        if (array[target_index] == 0) {
            if (target_index == stop) {
                return target_index;
            }
            continue;
        }

        if (array[target_index] != array[current_index]) {
            return target_index + 1;
        }

        return target_index;
    }
}

bool slideArray(int *array) {
    int stop_value = 0;
    bool moved = false;

    for (int current_index = 0; current_index < SIZE; current_index++) {
        if (array[current_index] == 0) {
            continue;
        }

        int target_index = findTargetIndex(array, current_index, stop_value);

        if (target_index == current_index) {
            continue;
        }
        moved = true;
        if (array[target_index] == 0) {
            array[target_index] = array[current_index];
        } else if (array[target_index] == array[current_index]) {
            array[target_index] *= 2;
            stop_value = target_index + 1;
        }

        array[current_index] = 0;
    }
    return moved;
}

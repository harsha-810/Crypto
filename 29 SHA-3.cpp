#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define LANES 25
#define MESSAGE_LANES 16
#define CAPACITY_LANES 8

void generateMessageBlock(uint64_t messageBlock[MESSAGE_LANES]) {
    for (int i = 0; i < MESSAGE_LANES; i++) {
        messageBlock[i] = (rand() % 1000000) + 1;
    }
}
void updateState(uint64_t state[LANES], uint64_t messageBlock[MESSAGE_LANES]) {
    for (int i = 0; i < MESSAGE_LANES; i++) {
        state[i] ^= messageBlock[i];
    }
    for (int i = LANES - CAPACITY_LANES; i < LANES; i++) {
        state[i] ^= (rand() % 1000000) + 1;
    }
}
int areAllCapacityLanesNonZero(uint64_t state[LANES]) {
    for (int i = LANES - CAPACITY_LANES; i < LANES; i++) {
        if (state[i] == 0) {
            return 0;
        }
    }
    return 1;
}
void printCapacityLanes(uint64_t state[LANES]) {
    for (int i = LANES - CAPACITY_LANES; i < LANES; i++) {
        printf("Lane %d: %llu\n", i, state[i]);
    }
    printf("\n");
}
int main() {
    uint64_t state[LANES] = {0};
    uint64_t messageBlock[MESSAGE_LANES];
    srand(time(NULL));

    int steps = 0;
    int maxSteps = 1000;

    while (!areAllCapacityLanesNonZero(state) && steps < maxSteps) {
        steps++;
        generateMessageBlock(messageBlock);
        updateState(state, messageBlock);
        printf("Step %d:\n", steps);
        printCapacityLanes(state);
    }
    if (areAllCapacityLanesNonZero(state)) {
        printf("All capacity lanes became non-zero after %d steps.\n", steps);
    } else {
        printf("Exceeded maximum number of steps (%d). Check algorithm.\n", maxSteps);
    }
    return 0;
}

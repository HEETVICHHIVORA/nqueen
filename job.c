#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_JOBS 5

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int min(int num1, int num2) {
    return (num1 > num2) ? num2 : num1;
}

void printJobScheduling(int deadlines[], int profits[], int n) {
    qsort(profits, n, sizeof(int), compare);

    bool slot[MAX_JOBS];
    int result[MAX_JOBS];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, deadlines[i]) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (slot[i])
            printf("%d ", result[i] + 1);
}

int main() {
    int deadlines[] = {2, 1, 2, 1, 3};
    int profits[] = {100, 19, 27, 25, 15};
    int n = sizeof(deadlines) / sizeof(deadlines[0]);

    printf("Following is the maximum profit sequence of jobs:\n");
    printJobScheduling(deadlines, profits, n);

    return 0;
}

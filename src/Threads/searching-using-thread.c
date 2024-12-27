#include <stdio.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX 16
#define MAX_THREAD 4

int arr[] = {1, 6, 8, 11, 13, 14, 15, 19, 21, 23, 26, 28, 31, 65, 108, 220};
int key = 31;
bool found = false;
int part = 0;

void binary_search(void *arg) {
    int thread_part = part++;
    int mid;
    int start = thread_part * (MAX / 4);
    int end = (thread_part + 1) * (MAX / 4);

    while (start < end && !found) {
        mid = (end + start) / 2 + start;

        if (arr[mid] == key) {
            found = true;
            break;
        } else if (arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
}

int main() {
    pthread_t threads[MAX_THREAD];

    for (int i = 0; i < MAX_THREAD; i++) {
        pthread_create(&threads[i], NULL, binary_search, (void *)NULL);
    }

    for (int i = 0; i < MAX_THREAD; i++) {
        pthread_join(threads[i], NULL);
    }

    if (found)
        printf("Found in array\n");
    else
        printf("Not found in array\n");

    return 0;
}

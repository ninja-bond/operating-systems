#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

void *thread_function(void *arg);

int main() {
    void *result;
    pthread_t a_thread;

    int num[3] = {3, 2, 7};
    pthread_create(&a_thread, NULL, thread_function, num);
    pthread_join(a_thread, &result);

    printf("Inside the main process\n");
    printf("Thread returned %d\n", (int)result);

    return 0;
}

void *thread_function(void *arg) {
    int *x = arg;
    int sum = x[0] + x[1] + x[2];

    printf("Sum is %d\n", sum);
    pthread_exit((void *)(intptr_t)sum);
}

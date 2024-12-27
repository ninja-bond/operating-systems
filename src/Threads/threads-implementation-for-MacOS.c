#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

void *thread_function(void *arg);

int main() {
    char *m = "5";
    pthread_t a_thread;
    void *result;

    pthread_create(&a_thread, NULL, thread_function, (void *)m);
    pthread_join(a_thread, &result);

    printf("Thread joined\n");

    for (int j = 20; j < 25; j++) {
        printf("%d\n", j);
        sleep(1);
    }

    printf("Thread returned: %s\n", (char *)result);

    return 0;
}

void *thread_function(void *arg) {
    int n = atoi((char *)arg);

    for (int i = 0; i < n; i++) {
        printf("%d\n", i);
        sleep(1);
    }

    pthread_exit("Done");
}

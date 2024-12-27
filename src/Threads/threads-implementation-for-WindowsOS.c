// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <pthread.h>

// void *thread_function(void *arg);

// int main() {
//     pthread_t a_thread;

//     pthread_create(&a_thread, NULL, thread_function, NULL);
//     pthread_join(a_thread, NULL);

//     printf("Inside Main Program\n");

//     for (int j = 20; j <= 25; j++) {
//         printf("%d\n", j);
//         sleep(1);
//     }

//     return 0;
// }

// void *thread_function(void *arg) {
//     printf("Inside Thread\n");

//     for (int i = 0; i < 15; i++) {
//         printf("%d\n", i);
//         sleep(1);
//     }

//     return NULL;
// }

#include <stdio.h>
#include <windows.h>

DWORD WINAPI thread_function(LPVOID lpParam) {
    printf("Inside Thread\n");
    for (int i = 0; i < 15; i++) {
        printf("%d\n", i);
        Sleep(1000); // Sleep for 1 second
    }
    return 0;
}

int main() {
    HANDLE thread;

    thread = CreateThread(NULL, 0, thread_function, NULL, 0, NULL);
    WaitForSingleObject(thread, INFINITE);

    printf("Inside Main Program\n");
    for (int j = 20; j <= 25; j++) {
        printf("%d\n", j);
        Sleep(1000);
    }

    CloseHandle(thread);
    return 0;
}

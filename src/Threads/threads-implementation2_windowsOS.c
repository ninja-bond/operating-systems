#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI thread_function(LPVOID arg);

int main() {
    char *m = "5";
    HANDLE a_thread;
    DWORD result;

    a_thread = CreateThread(NULL, 0, thread_function, (void *)m, 0, NULL);
    WaitForSingleObject(a_thread, INFINITE);

    printf("Inside the main process\n");
    printf("Thread returned: %ld\n", result);

    CloseHandle(a_thread);
    return 0;
}

DWORD WINAPI thread_function(LPVOID arg) {
    int n = atoi((char *)arg);

    for (int i = 0; i < n; i++) {
        printf("%d\n", i);
        Sleep(1000); // Sleep for 1 second
    }

    return 0;
}

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

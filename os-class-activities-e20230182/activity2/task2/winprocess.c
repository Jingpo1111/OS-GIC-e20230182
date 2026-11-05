
#include <stdio.h>
#include <windows.h>

int main(void)
{
    STARTUPINFOA si = {0};
    PROCESS_INFORMATION pi = {0};

    si.cb = sizeof(si);

    printf("Parent process (PID: %lu) - creating child...\n",
           GetCurrentProcessId());

    char paintPath[] =
        "C:\\Users\\Jingpo\\AppData\\Local\\Microsoft\\WindowsApps\\mspaint.exe";

    if (!CreateProcessA(
            paintPath,
            NULL,
            NULL,
            NULL,
            FALSE,
            0,
            NULL,
            NULL,
            &si,
            &pi))
    {

        printf("CreateProcess failed (error %lu).\n",
               GetLastError());
        return 1;
    }

    printf("Child process created!\n");
    printf("Child PID: %lu\n", pi.dwProcessId);
    printf("Child Thread ID: %lu\n", pi.dwThreadId);

    printf("Waiting for Microsoft Paint to close...\n");

    WaitForSingleObject(pi.hProcess, INFINITE);

    printf("Paint closed. Parent finished.\n");

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}

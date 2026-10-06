#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <windows.h>
#include <string>
#include <iostream>
#include <tchar.h>
#include <stdlib.h>


DWORD GetProcId(const wchar_t* procName)
{
    DWORD procId = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnap != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 procEntry;
        procEntry.dwSize = sizeof(procEntry);

        if (Process32First(hSnap, &procEntry))
        {
            do
            {
                if (!wcscmp(procEntry.szExeFile, procName))
                {
                    procId = procEntry.th32ProcessID;
                    break;
                }
            } while (Process32Next(hSnap, &procEntry));
        }
    }
    CloseHandle(hSnap);
    return procId;
}



uint32_t main()
{
    DWORD procId = 0;

    printf("Scanning for process...\n");
    while (!procId)
    {
        procId = GetProcId(L"ChudBlaster.exe");
        Sleep(30);
    }

    HANDLE hProc = OpenProcess(PROCESS_ALL_ACCESS, 0, procId);

    if (hProc != INVALID_HANDLE_VALUE)
    {
        printf("Process has been found!\n");

        //WriteProcessMemory(hProc, loc, dllPath, strlen(dllPath) + 1, 0);
    }

    return 0;
}
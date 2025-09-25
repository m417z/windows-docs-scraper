# GetProcessWorkingSetSize function

## Description

Retrieves the minimum and maximum working set sizes of the specified process.

## Parameters

### `hProcess` [in]

A handle to the process whose working set sizes will be obtained. The handle must have the **PROCESS_QUERY_INFORMATION** or **PROCESS_QUERY_LIMITED_INFORMATION** access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

**Windows Server 2003 and Windows XP:** The handle must have the **PROCESS_QUERY_INFORMATION** access right.

### `lpMinimumWorkingSetSize` [out]

A pointer to a variable that receives the minimum working set size of the specified process, in bytes. The virtual memory manager attempts to keep at least this much memory resident in the process whenever the process is active.

### `lpMaximumWorkingSetSize` [out]

 A pointer to a variable that receives the maximum working set size of the specified process, in bytes. The virtual memory manager attempts to keep no more than this much memory resident in the process whenever the process is active when memory is in short supply.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The "working set" of a process is the set of memory pages currently visible to the process in physical RAM memory. These pages are resident and available for an application to use without triggering a page fault. The minimum and maximum working set sizes affect the virtual memory paging behavior of a process.

#### Examples

```cpp
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    SIZE_T  dwMin, dwMax;
    HANDLE hProcess;

    if (argc != 2)
    {
        printf("This program requires a process ID as an argument.\n");
        return 1;
    }

    // Retrieve a handle to the process.

    hProcess = OpenProcess( PROCESS_QUERY_INFORMATION,
                            FALSE, atoi(argv[1]));
     if (!hProcess)
    {
        printf( "OpenProcess failed (%d)\n", GetLastError() );
        return 1;
    }

    // Retrieve the working set size of the process.

    if (!GetProcessWorkingSetSize(hProcess, &dwMin, &dwMax))
    {
        printf("GetProcessWorkingSetSize failed (%d)\n",
            GetLastError());
        return 1;
    }

    printf("Process ID: %d\n", atoi(argv[1]));
    printf("Minimum working set: %lu KB\n", dwMin/1024);
    printf("Maximum working set: %lu KB\n", dwMax/1024);

    CloseHandle(hProcess);

    return 0;
}

```

## See also

[Process Working Set](https://learn.microsoft.com/windows/desktop/ProcThread/process-working-set)

[Processes](https://learn.microsoft.com/windows/desktop/ProcThread/child-processes)

[SetProcessWorkingSetSize function](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-setprocessworkingsetsize)

[SetProcessWorkingSetSizeEx function](https://learn.microsoft.com/windows/win32/api/memoryapi/nf-memoryapi-setprocessworkingsetsizeex)
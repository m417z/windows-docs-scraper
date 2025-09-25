# GlobalMemoryStatusEx function

## Description

Retrieves information about the system's current usage of both physical and virtual memory.

## Parameters

### `lpBuffer` [in, out]

A pointer to a
[MEMORYSTATUSEX](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-memorystatusex) structure that receives information about current memory availability.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You can use the
**GlobalMemoryStatusEx** function to determine how much memory your application can allocate without severely impacting other applications.

The information returned by the
**GlobalMemoryStatusEx** function is volatile. There is no guarantee that two sequential calls to this function will return the same information.

The **ullAvailPhys** member of the [MEMORYSTATUSEX](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-memorystatusex) structure at *lpBuffer* includes memory for all NUMA nodes.

#### Examples

The following code shows a simple use of the
**GlobalMemoryStatusEx** function.

```cpp
//  Sample output:
//  There is       51 percent of memory in use.
//  There are 2029968 total KB of physical memory.
//  There are  987388 free  KB of physical memory.
//  There are 3884620 total KB of paging file.
//  There are 2799776 free  KB of paging file.
//  There are 2097024 total KB of virtual memory.
//  There are 2084876 free  KB of virtual memory.
//  There are       0 free  KB of extended memory.

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

// Use to convert bytes to KB
#define DIV 1024

// Specify the width of the field in which to print the numbers.
// The asterisk in the format specifier "%*I64d" takes an integer
// argument and uses it to pad and right justify the number.
#define WIDTH 7

void _tmain()
{
  MEMORYSTATUSEX statex;

  statex.dwLength = sizeof (statex);

  GlobalMemoryStatusEx (&statex);

  _tprintf (TEXT("There is  %*ld percent of memory in use.\n"),
            WIDTH, statex.dwMemoryLoad);
  _tprintf (TEXT("There are %*I64d total KB of physical memory.\n"),
            WIDTH, statex.ullTotalPhys/DIV);
  _tprintf (TEXT("There are %*I64d free  KB of physical memory.\n"),
            WIDTH, statex.ullAvailPhys/DIV);
  _tprintf (TEXT("There are %*I64d total KB of paging file.\n"),
            WIDTH, statex.ullTotalPageFile/DIV);
  _tprintf (TEXT("There are %*I64d free  KB of paging file.\n"),
            WIDTH, statex.ullAvailPageFile/DIV);
  _tprintf (TEXT("There are %*I64d total KB of virtual memory.\n"),
            WIDTH, statex.ullTotalVirtual/DIV);
  _tprintf (TEXT("There are %*I64d free  KB of virtual memory.\n"),
            WIDTH, statex.ullAvailVirtual/DIV);

  // Show the amount of extended memory available.

  _tprintf (TEXT("There are %*I64d free  KB of extended memory.\n"),
            WIDTH, statex.ullAvailExtendedVirtual/DIV);
}

```

## See also

[MEMORYSTATUSEX](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/ns-sysinfoapi-memorystatusex)

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[Memory Performance Information](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa965225(v=vs.85))

[Virtual Address Space and Physical Storage](https://learn.microsoft.com/windows/desktop/Memory/virtual-address-space-and-physical-storage)
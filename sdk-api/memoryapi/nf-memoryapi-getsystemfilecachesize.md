# GetSystemFileCacheSize function

## Description

Retrieves the current size limits for the working set of the system cache.

## Parameters

### `lpMinimumFileCacheSize` [out]

A pointer to a variable that receives the minimum size of the file cache, in bytes. The virtual memory manager attempts to keep at least this much memory resident in the system file cache, if there is a previous call to the [SetSystemFileCacheSize](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-setsystemfilecachesize) function with the **FILE_CACHE_MIN_HARD_ENABLE** flag.

### `lpMaximumFileCacheSize` [out]

A pointer to a variable that receives the maximum size of the file cache, in bytes. The virtual memory manager enforces this limit only if there is a previous call to [SetSystemFileCacheSize](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-setsystemfilecachesize) with the **FILE_CACHE_MAX_HARD_ENABLE** flag.

### `lpFlags` [out]

The flags that indicate which of the file cache limits are enabled.

| Value | Meaning |
| --- | --- |
| **FILE_CACHE_MAX_HARD_ENABLE**<br><br>0x1 | The maximum size limit is enabled. If this flag is not present, this limit is disabled. |
| **FILE_CACHE_MIN_HARD_ENABLE**<br><br>0x4 | The minimum size limit is enabled. If this flag is not present, this limit is disabled. |

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is 0 (zero). To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0502 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

The **FILE_CACHE** constants will be defined in the Windows header files starting with the Windows SDK for Windows Server 2008. If you are using header files from an earlier version of the SDK, add the definitions shown in [SetSystemFileCacheSize](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-setsystemfilecachesize) to your code.

## See also

[Memory
Management Functions](https://learn.microsoft.com/windows/desktop/Memory/memory-management-functions)

[SetSystemFileCacheSize](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-setsystemfilecachesize)
# SetProcessAffinityUpdateMode function

## Description

Sets the affinity update mode of the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. This handle must be returned by the [GetCurrentProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-getcurrentprocess) function.

### `dwFlags` [in]

The affinity update mode. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Disables dynamic update of the process affinity by the system. |
| **PROCESS_AFFINITY_ENABLE_AUTO_UPDATE**<br><br>0x00000001UL | Enables dynamic update of the process affinity by the system. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The system can adjust process affinity under various conditions, such as when a processor is added dynamically. By default, dynamic updates to the process affinity are disabled for each process.

Processes should use this function to indicate whether they can handle dynamic adjustment of process affinity by the system. After a process enables affinity update mode, it can call this function to disable it. However, a process cannot enable affinity update mode after it has used this function to disable it.

Child processes do not inherit the affinity update mode of the parent process. The affinity update mode must be explicitly set for each child process.

To compile an application that calls this function, define _WIN32_WINNT as 0x0600 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[QueryProcessAffinityUpdateMode](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queryprocessaffinityupdatemode)
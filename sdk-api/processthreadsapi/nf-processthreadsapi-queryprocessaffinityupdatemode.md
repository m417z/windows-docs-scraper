# QueryProcessAffinityUpdateMode function

## Description

Retrieves the affinity update mode of the specified process.

## Parameters

### `hProcess` [in]

A handle to the process. The handle must have the PROCESS_QUERY_INFORMATION or PROCESS_QUERY_LIMITED_INFORMATION access right. For more information, see
[Process Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/process-security-and-access-rights).

### `lpdwFlags` [out, optional]

The affinity update mode. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0 | Dynamic update of the process affinity by the system is disabled. |
| **PROCESS_AFFINITY_ENABLE_AUTO_UPDATE**<br><br>0x00000001UL | Dynamic update of the process affinity by the system is enabled. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that calls this function, define _WIN32_WINNT as 0x0600 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[SetProcessAffinityUpdateMode](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-setprocessaffinityupdatemode)
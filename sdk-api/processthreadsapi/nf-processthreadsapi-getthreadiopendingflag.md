# GetThreadIOPendingFlag function

## Description

Determines whether a specified thread has any I/O requests pending.

## Parameters

### `hThread` [in]

A handle to the thread in question. This handle must have been created with the THREAD_QUERY_INFORMATION access right. For more information, see [Thread Security and Access Rights](https://learn.microsoft.com/windows/desktop/ProcThread/thread-security-and-access-rights).

### `lpIOIsPending` [in, out]

A pointer to a variable which the function sets to TRUE if the specified thread has one or more I/O requests pending, or to FALSE otherwise.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Keep in mind that the I/O status of the specified thread can change rapidly, and may already have changed by the time the function returns. For example, a pending I/O operation could complete between the time the function sets *lpIOIsPending* and the time it returns.

To compile an application that uses this function, define _WIN32_WINNT as 0x0501 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[Threads](https://learn.microsoft.com/windows/desktop/ProcThread/multiple-threads)
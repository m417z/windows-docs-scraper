# ConvertFiberToThread function

## Description

Converts the current fiber into a thread.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The function releases the resources allocated by the
[ConvertThreadToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiber) function. After calling this function, you cannot call any of the fiber functions from the thread.

To compile an application that uses this function, define \_WIN32_WINNT as \_WIN32_WINNT_WS03 (0x0502) or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[ConvertThreadToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiber)

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)
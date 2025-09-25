# IsThreadAFiber function

## Description

Determines whether the current thread is a fiber.

## Return value

The function returns **TRUE** if the thread is a fiber and **FALSE** otherwise.

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[ConvertThreadToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiber)

[ConvertThreadToFiberEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiberex)

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)
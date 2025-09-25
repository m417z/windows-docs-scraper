# GetCurrentThreadStackLimits function

## Description

Retrieves the boundaries of the stack that was allocated by the system for the current thread.

## Parameters

### `LowLimit` [out]

A pointer variable that receives the lower boundary of the current thread stack.

### `HighLimit` [out]

A pointer variable that receives the upper boundary of the current thread stack.

## Remarks

 It is possible for user-mode code to execute in stack memory
that is outside the region allocated by the system when the thread was created. Callers
can use the **GetCurrentThreadStackLimits** function to verify that the current stack pointer is within the returned
limits.

To compile an application that uses this function, set _WIN32_WINNT >= 0x0602. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Thread Stack Size](https://learn.microsoft.com/windows/desktop/ProcThread/thread-stack-size)
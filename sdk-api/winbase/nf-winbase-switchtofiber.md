# SwitchToFiber function

## Description

Schedules a fiber. The function must be called on a fiber.

## Parameters

### `lpFiber` [in]

The address of the fiber to be scheduled.

## Remarks

You create fibers with the
[CreateFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiber) function. Before you can schedule fibers associated with a thread, you must call
[ConvertThreadToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiber) to set up an area in which to save the fiber state information. The thread is now the currently executing fiber.

The
**SwitchToFiber** function saves the state information of the current fiber and restores the state of the specified fiber. You can call
**SwitchToFiber** with the address of a fiber created by a different thread. To do this, you must have the address returned to the other thread when it called
[CreateFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiber) and you must use proper synchronization.

Avoid making the following call:

``` syntax
SwitchToFiber( GetCurrentFiber() );
```

This call can cause unpredictable problems.

To compile an application that uses this function, define _WIN32_WINNT as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[ConvertThreadToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiber)

[CreateFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiber)

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)
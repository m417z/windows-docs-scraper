# CreateFiberEx function

## Description

Allocates a fiber object, assigns it a stack, and sets up execution to begin at the specified start address, typically the fiber function. This function does not schedule the fiber.

## Parameters

### `dwStackCommitSize` [in]

The initial commit size of the stack, in bytes. If this parameter is zero, the new fiber uses the default commit stack size for the executable. For more information, see [Thread Stack Size](https://learn.microsoft.com/windows/desktop/ProcThread/thread-stack-size).

### `dwStackReserveSize` [in]

The initial reserve size of the stack, in bytes. If this parameter is zero, the new fiber uses the default reserved stack size for the executable. For more information, see [Thread Stack Size](https://learn.microsoft.com/windows/desktop/ProcThread/thread-stack-size).

### `dwFlags` [in]

If this parameter is zero, the floating-point state on x86 systems is not switched and data can be corrupted if a fiber uses floating-point arithmetic. If this parameter is **FIBER_FLAG_FLOAT_SWITCH**, the floating-point state is switched for the fiber.

**Windows XP:** The **FIBER_FLAG_FLOAT_SWITCH** flag is not supported.

### `lpStartAddress` [in]

A pointer to the application-defined function to be executed by the fiber and represents the starting address of the fiber. Execution of the newly created fiber does not begin until another fiber calls the
[SwitchToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-switchtofiber) function with this address. For more information on the fiber callback function, see
[FiberProc](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pfiber_start_routine).

### `lpParameter` [in, optional]

A pointer to a variable that is passed to the fiber. The fiber can retrieve this data by using the
[GetFiberData](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-getfiberdata) macro.

## Return value

If the function succeeds, the return value is the address of the fiber.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The number of fibers a process can create is limited by the available virtual memory. By default, every fiber has 1 megabyte of reserved stack space. Therefore, you can create at most 2028 fibers. If you reduce the default stack size, you can create more fibers. However, your application will have better performance if you use an alternate strategy for processing requests.

Before a thread can schedule a fiber using the
[SwitchToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-switchtofiber) function, it must call the
[ConvertThreadToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiber) function so there is a fiber associated with the thread.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[ConvertThreadToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiber)

[FiberProc](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pfiber_start_routine)

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)

[GetFiberData](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-getfiberdata)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[SwitchToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-switchtofiber)
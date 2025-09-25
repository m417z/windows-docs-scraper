# CreateFiber function

## Description

Allocates a fiber object, assigns it a stack, and sets up execution to begin at the specified start address, typically the fiber function. This function does not schedule the fiber.

To specify both a commit and reserve stack size, use the
[CreateFiberEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiberex) function.

## Parameters

### `dwStackSize` [in]

The initial committed size of the stack, in bytes. If this parameter is zero, the new fiber uses the default commit stack size for the executable. For more information, see [Thread Stack Size](https://learn.microsoft.com/windows/desktop/ProcThread/thread-stack-size).

### `lpStartAddress` [in]

A pointer to the application-defined function to be executed by the fiber and represents the starting address of the fiber. Execution of the newly created fiber does not begin until another fiber calls the
[SwitchToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-switchtofiber) function with this address. For more information of the fiber callback function, see
[FiberProc](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pfiber_start_routine).

### `lpParameter` [in, optional]

A pointer to a variable that is passed to the fiber. The fiber can retrieve this data by using the
[GetFiberData](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-getfiberdata) macro.

## Return value

If the function succeeds, the return value is the address of the fiber.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The number of fibers a process can create is limited by the available virtual memory. For example, if you create each fiber with 1 megabyte of reserved stack space, you can create at most 2028 fibers. If you reduce the default stack size by using the STACKSIZE statement in the module definition (.def) file or
by using [CreateFiberEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiberex), you can create more fibers. However, your application will have better performance if you use an alternate strategy for processing requests instead of creating such a large number of fibers.

Before a thread can schedule a fiber using the
[SwitchToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-switchtofiber) function, it must call the
[ConvertThreadToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiber) function so there is a fiber associated with the thread.

To compile an application that uses this function, define _WIN32_WINNT as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

For an example, see [Using Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/using-fibers).

## See also

[ConvertThreadToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiber)

[CreateFiberEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfiberex)

[FiberProc](https://learn.microsoft.com/windows/desktop/api/winbase/nc-winbase-pfiber_start_routine)

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)

[GetFiberData](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-getfiberdata)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)

[SwitchToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-switchtofiber)
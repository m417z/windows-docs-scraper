# ConvertThreadToFiber function

## Description

Converts the current thread into a fiber. You must convert a thread into a fiber before you can schedule other fibers.

## Parameters

### `lpParameter` [in, optional]

A pointer to a variable that is passed to the fiber. The fiber can retrieve this data by using the
[GetFiberData](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-getfiberdata) macro.

## Return value

If the function succeeds, the return value is the address of the fiber.

If the function fails, the return value is NULL. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Only fibers can execute other fibers. If a thread needs to execute a fiber, it must call
**ConvertThreadToFiber** or
[ConvertThreadToFiberEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiberex) to create an area in which to save fiber state information. The thread is now the current fiber. The state information for this fiber includes the fiber data specified by *lpParameter*.

To compile an application that uses this function, define _WIN32_WINNT as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

For an example, see [Using Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/using-fibers).

## See also

[ConvertFiberToThread](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertfibertothread)

[ConvertThreadToFiberEx](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-convertthreadtofiberex)

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)

[GetFiberData](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-getfiberdata)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)
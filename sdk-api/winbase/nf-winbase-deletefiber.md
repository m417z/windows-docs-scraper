# DeleteFiber function

## Description

Deletes an existing fiber.

## Parameters

### `lpFiber` [in]

The address of the fiber to be deleted.

## Remarks

The
**DeleteFiber** function deletes all data associated with the fiber. This data includes the stack, a subset of the registers, and the fiber data.

If the currently running fiber calls
**DeleteFiber**, its thread calls
[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread) and terminates. However, if a currently running fiber is deleted by another fiber, the thread running the deleted fiber is likely to terminate abnormally because the fiber stack has been freed.

To compile an application that uses this function, define _WIN32_WINNT as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

For an example, see [Using Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/using-fibers).

## See also

[ExitThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitthread)

[Fibers](https://learn.microsoft.com/windows/desktop/ProcThread/fibers)

[Process and Thread Functions](https://learn.microsoft.com/windows/desktop/ProcThread/process-and-thread-functions)
# SetThreadStackGuarantee function

## Description

Sets the minimum size of the stack associated with the calling thread or fiber that will be available during any stack overflow exceptions. This is useful for handling stack overflow exceptions; the application can safely use the specified number of bytes during exception handling.

## Parameters

### `StackSizeInBytes` [in, out]

The size of the stack, in bytes. On return, this value is set to the size of the previous stack, in bytes.

If this parameter is 0 (zero), the function succeeds and the parameter contains the size of the current stack.

If the specified size is less than the current size, the function succeeds but ignores this request. Therefore, you cannot use this function to reduce the size of the stack.

This value cannot be larger than the reserved stack size.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is 0 (zero). To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the function is successful, the application can handle possible EXCEPTION_STACK_OVERFLOW exceptions using [structured exception handling](https://learn.microsoft.com/windows/desktop/Debug/structured-exception-handling). To resume execution after handling a stack overflow, you must perform certain recovery steps. If you are using the Microsoft C/C++ compiler, call the **_resetstkoflw** function. If you are using another compiler, see the documentation for the compiler for information on recovering from stack overflows.

To set the stack guarantee for a fiber, you must first call the [SwitchToFiber](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-switchtofiber) function to execute the fiber. After you set the guarantee for this fiber, it is used by the fiber no matter which thread executes the fiber.

## See also

[Process and Thread Functions](https://learn.microsoft.com/windows/win32/ProcThread/process-and-thread-functions)

[Thread Stack Size](https://learn.microsoft.com/windows/win32/ProcThread/thread-stack-size)

[Threads](https://learn.microsoft.com/windows/win32/ProcThread/multiple-threads)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)
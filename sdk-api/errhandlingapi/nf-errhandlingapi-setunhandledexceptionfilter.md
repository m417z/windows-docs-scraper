# SetUnhandledExceptionFilter function

## Description

Enables an application to supersede the top-level exception handler of each thread of a process.

After calling this function, if an exception occurs in a process that is not being debugged, and the exception makes it to the unhandled exception filter, that filter will call the exception filter function specified by the *lpTopLevelExceptionFilter* parameter.

## Parameters

### `lpTopLevelExceptionFilter` [in]

A pointer to a top-level exception filter function that will be called whenever the [UnhandledExceptionFilter](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-unhandledexceptionfilter) function gets control, and the process is not being debugged. A value of **NULL** for this parameter specifies default handling within **UnhandledExceptionFilter**.

The filter function has syntax similar to that of [UnhandledExceptionFilter](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-unhandledexceptionfilter): It takes a single parameter of type **LPEXCEPTION_POINTERS**, has a WINAPI calling convention, and returns a value of type **LONG**. The filter function should return one of the following values.

| Value | Meaning |
| --- | --- |
| **EXCEPTION_EXECUTE_HANDLER**<br><br>0x1 | Return from [UnhandledExceptionFilter](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-unhandledexceptionfilter) and execute the associated exception handler. This usually results in process termination. |
| **EXCEPTION_CONTINUE_EXECUTION**<br><br>0xffffffff | Return from [UnhandledExceptionFilter](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-unhandledexceptionfilter) and continue execution from the point of the exception. Note that the filter function is free to modify the continuation state by modifying the exception information supplied through its **LPEXCEPTION_POINTERS** parameter. |
| **EXCEPTION_CONTINUE_SEARCH**<br><br>0x0 | Proceed with normal execution of [UnhandledExceptionFilter](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-unhandledexceptionfilter). That means obeying the [SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode) flags, or invoking the Application Error pop-up message box. |

## Return value

The **SetUnhandledExceptionFilter** function returns the address of the previous exception filter established with the function. A **NULL** return value means that there is no current top-level exception handler.

## Remarks

Issuing **SetUnhandledExceptionFilter** replaces the existing top-level exception filter for all existing and all future threads in the calling process.

The exception handler specified by *lpTopLevelExceptionFilter* is executed in the context of the thread that caused the fault. This can affect the exception handler's ability to recover from certain exceptions, such as an invalid stack.

## See also

[Structured Exception Handling Functions](https://learn.microsoft.com/windows/win32/Debug/structured-exception-handling-functions)

[Structured Exception Handling Overview](https://learn.microsoft.com/windows/win32/Debug/structured-exception-handling)

[UnhandledExceptionFilter](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-unhandledexceptionfilter)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)
# UnhandledExceptionFilter function

## Description

An application-defined function that passes unhandled exceptions to the debugger, if the process is being debugged. Otherwise, it optionally displays an **Application Error** message box and causes the exception handler to be executed. This function can be called only from within the filter expression of an exception handler.

## Parameters

### `ExceptionInfo` [in]

A pointer to an
[EXCEPTION_POINTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_pointers) structure that specifies a description of the exception and the processor context at the time of the exception. This pointer is the return value of a call to the
[GetExceptionInformation](https://learn.microsoft.com/windows/desktop/Debug/getexceptioninformation) function.

## Return value

The function returns one of the following values.

| Return code/value | Description |
| --- | --- |
| **EXCEPTION_CONTINUE_SEARCH**<br><br>0x0 | The process is being debugged, so the exception should be passed (as second chance) to the application's debugger. |
| **EXCEPTION_EXECUTE_HANDLER**<br><br>0x1 | If the SEM_NOGPFAULTERRORBOX flag was specified in a previous call to [SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode), no Application Error message box is displayed. The function returns control to the exception handler, which is free to take any appropriate action. |

## Remarks

If the process is not being debugged, the function displays an **Application Error** message box, depending on the current error mode. The default behavior is to display the dialog box, but this can be disabled by specifying SEM_NOGPFAULTERRORBOX in a call to the
[SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode) function.

The system uses
**UnhandledExceptionFilter** internally to handle exceptions that occur during process and thread creation.

## See also

[EXCEPTION_POINTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_pointers)

[GetExceptionInformation](https://learn.microsoft.com/windows/desktop/Debug/getexceptioninformation)

[SetErrorMode](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-seterrormode)

[SetUnhandledExceptionFilter](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-setunhandledexceptionfilter)

[Structured Exception Handling Functions](https://learn.microsoft.com/windows/desktop/Debug/structured-exception-handling-functions)

[Structured Exception Handling Overview](https://learn.microsoft.com/windows/desktop/Debug/structured-exception-handling)
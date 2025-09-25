# RaiseException function

## Description

Raises an exception in the calling thread.

## Parameters

### `dwExceptionCode` [in]

An application-defined exception code of the exception being raised. The filter expression and exception-handler block of an exception handler can use the [GetExceptionCode](https://learn.microsoft.com/windows/desktop/Debug/getexceptioncode) function to retrieve this value.

Note that the system will clear bit 28 of *dwExceptionCode* before displaying a message This bit is a reserved exception bit, used by the system for its own purposes.

### `dwExceptionFlags` [in]

The exception flags. This can be either zero to indicate a continuable exception, or EXCEPTION_NONCONTINUABLE to indicate a noncontinuable exception. Any attempt to continue execution after a noncontinuable exception causes the EXCEPTION_NONCONTINUABLE_EXCEPTION exception.

### `nNumberOfArguments` [in]

The number of arguments in the *lpArguments* array. This value must not exceed EXCEPTION_MAXIMUM_PARAMETERS. This parameter is ignored if *lpArguments* is **NULL**.

### `lpArguments` [in]

An array of arguments. This parameter can be **NULL**. These arguments can contain any application-defined data that needs to be passed to the filter expression of the exception handler.

## Return value

This function does not return a value.

## Remarks

The **RaiseException** function enables a process to use structured exception handling to handle private, software-generated, application-defined exceptions.

Raising an exception causes the exception dispatcher to go through the following search for an exception handler:

1. The system first attempts to notify the process's debugger, if any.
2. If the process is not being debugged, or if the associated debugger does not handle the exception, the system attempts to locate a frame-based exception handler by searching the stack frames of the thread in which the exception occurred. The system searches the current stack frame first, then proceeds backward through preceding stack frames.
3. If no frame-based handler can be found, or no frame-based handler handles the exception, the system makes a second attempt to notify the process's debugger.
4. If the process is not being debugged, or if the associated debugger does not handle the exception, the system provides default handling based on the exception type. For most exceptions, the default action is to call the [ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess) function.

The values specified in the *dwExceptionCode*, *dwExceptionFlags*, *nNumberOfArguments*, and *lpArguments* parameters can be retrieved in the filter expression of a frame-based exception handler by calling the [GetExceptionInformation](https://learn.microsoft.com/windows/desktop/Debug/getexceptioninformation) function. A debugger can retrieve these values by calling the [WaitForDebugEvent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-waitfordebugevent) function.

#### Examples

For an example, see [Using an Exception Handler](https://learn.microsoft.com/windows/desktop/Debug/using-an-exception-handler).

## See also

[ExitProcess](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-exitprocess)

[GetExceptionCode](https://learn.microsoft.com/windows/desktop/Debug/getexceptioncode)

[GetExceptionInformation](https://learn.microsoft.com/windows/desktop/Debug/getexceptioninformation)

[Structured Exception Handling Functions](https://learn.microsoft.com/windows/desktop/Debug/structured-exception-handling-functions)

[Structured Exception Handling Overview](https://learn.microsoft.com/windows/desktop/Debug/structured-exception-handling)

[WaitForDebugEvent](https://learn.microsoft.com/windows/desktop/api/debugapi/nf-debugapi-waitfordebugevent)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)
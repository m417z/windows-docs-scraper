# PVECTORED_EXCEPTION_HANDLER callback function

## Description

An application-defined function that serves as a vectored exception handler. Specify this address when calling the
[AddVectoredExceptionHandler](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-addvectoredexceptionhandler) function. The **PVECTORED_EXCEPTION_HANDLER** type defines a pointer to this callback function.
**VectoredHandler** is a placeholder for the application-defined name.

## Parameters

### `ExceptionInfo` [in]

A pointer to an
[EXCEPTION_POINTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_pointers) structure that receives the exception record.

## Return value

To return control to the point at which the exception occurred, return EXCEPTION_CONTINUE_EXECUTION (0xffffffff). To continue the handler search, return EXCEPTION_CONTINUE_SEARCH (0x0).

## Remarks

The handler should not call functions that acquire synchronization objects or allocate memory, because this can cause problems. Typically, the handler will simply access the exception record and return.

## See also

[EXCEPTION_POINTERS](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-exception_pointers)

[Vectored Exception Handling](https://learn.microsoft.com/windows/desktop/Debug/vectored-exception-handling)
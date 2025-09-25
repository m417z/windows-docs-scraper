## Description

Registers a vectored exception handler.

## Parameters

### `First`

The order in which the handler should be called. If the parameter is nonzero, the handler is the first handler to be called. If the parameter is zero, the handler is the last handler to be called.

### `Handler`

A pointer to the handler to be called. For more information, see [VectoredHandler](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-pvectored_exception_handler).

## Return value

If the function succeeds, the return value is a handle to the exception handler.

If the function fails, the return value is **NULL**.

## Remarks

If the *First* parameter is nonzero, the handler is the first handler to be called until a subsequent call to **AddVectoredExceptionHandler** is used to specify a different handler as the first handler.

If the *VectoredHandler* parameter points to a function in a DLL and that DLL is unloaded, the handler is still registered. This can lead to application errors.

To unregister the handler, use the [RemoveVectoredExceptionHandler function](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-removevectoredexceptionhandler) function.

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0500 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

### Examples

For an example, see [Using a Vectored Exception Handler](https://learn.microsoft.com/windows/desktop/Debug/using-a-vectored-exception-handler).

## See also

[AddVectoredContinueHandler function](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-addvectoredcontinuehandler), [RemoveVectoredExceptionHandler function](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-removevectoredexceptionhandler), [Vectored Exception Handling](https://learn.microsoft.com/windows/desktop/Debug/vectored-exception-handling), [VectoredHandler](https://learn.microsoft.com/windows/desktop/api/winnt/nc-winnt-pvectored_exception_handler)
## Description

Unregisters a vectored exception handler.

## Parameters

### `Handle`

A handle to the vectored exception handler previously registered using the [AddVectoredExceptionHandler function](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-addvectoredexceptionhandler).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0500 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

### Examples

For an example, see [Using a Vectored Exception Handler](https://learn.microsoft.com/windows/desktop/Debug/using-a-vectored-exception-handler).

## See also

[AddVectoredExceptionHandler function](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-addvectoredexceptionhandler), [Vectored Exception Handling](https://learn.microsoft.com/windows/desktop/Debug/vectored-exception-handling)
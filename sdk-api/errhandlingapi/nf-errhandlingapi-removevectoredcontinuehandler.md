## Description

Unregisters a vectored continue handler.

## Parameters

### `Handle`

A pointer to a vectored exception handler previously registered using the [AddVectoredContinueHandler function](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-addvectoredcontinuehandler).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

To compile an application that uses this function, define the _WIN32_WINNT macro as 0x0500 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[AddVectoredContinueHandler function](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-addvectoredcontinuehandler), [Vectored Exception Handling](https://learn.microsoft.com/windows/desktop/Debug/vectored-exception-handling)
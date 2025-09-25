# UnregisterBadMemoryNotification function

## Description

Closes the specified bad memory notification handle.

## Parameters

### `RegistrationHandle` [in]

Registration handle returned from the
[RegisterBadMemoryNotification](https://learn.microsoft.com/windows/desktop/api/memoryapi/nf-memoryapi-registerbadmemorynotification)
function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that calls this function, define **_WIN32_WINNT** as
**_WIN32_WINNT_WIN8** or higher. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).
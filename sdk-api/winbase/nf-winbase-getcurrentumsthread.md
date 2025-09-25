# GetCurrentUmsThread function

## Description

Returns the user-mode scheduling (UMS) thread context of the calling UMS thread.

> [!WARNING]
> As of Windows 11, user-mode scheduling is not supported. All calls fail with the error `ERROR_NOT_SUPPORTED`.

## Return value

The function returns a pointer to the UMS thread context of the calling thread.

If calling thread is not a UMS thread, the function returns NULL. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetCurrentUmsThread** function can be called for a UMS scheduler thread or UMS worker thread.
# ShutdownBlockReasonDestroy function

## Description

Indicates that the system can be shut down and frees the reason string.

## Parameters

### `hWnd` [in]

A handle to the main window of the application.

## Return value

If the call succeeds, the return value is nonzero.

If the call fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function can only be called from the thread that created the window specified by the *hWnd* parameter. Otherwise, the function fails and the last error code is ERROR_ACCESS_DENIED.

If system shutdown has been previously blocked by the [ShutdownBlockReasonCreate](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-shutdownblockreasoncreate) function, this function frees the reason string. Otherwise, this function is a no-op.

## See also

[ShutdownBlockReasonCreate](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-shutdownblockreasoncreate)

[Shutting Down](https://learn.microsoft.com/windows/desktop/Shutdown/shutting-down)
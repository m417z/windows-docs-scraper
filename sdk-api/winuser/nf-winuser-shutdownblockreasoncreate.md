# ShutdownBlockReasonCreate function

## Description

Indicates that the system cannot be shut down and sets a reason string to be displayed to the user if system shutdown is initiated.

## Parameters

### `hWnd` [in]

A handle to the main window of the application.

### `pwszReason` [in]

The reason the application must block system shutdown. This string will be truncated for display purposes after MAX_STR_BLOCKREASON characters.

## Return value

If the call succeeds, the return value is nonzero.

If the call fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function can only be called from the thread that created the window specified by the *hWnd* parameter. Otherwise, the function fails and the last error code is ERROR_ACCESS_DENIED.

Applications should call this function as they begin an operation that cannot be interrupted, such as burning a CD or DVD. When the operation has completed, call the [ShutdownBlockReasonDestroy](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-shutdownblockreasondestroy) function to indicate that the system can be shut down.

Because users are typically in a hurry when shutting down the system, they may spend only a few seconds looking at the shutdown reasons that are displayed by the system. Therefore, it is important that your reason strings are short and clear. For example "A CD burn is in progress." is better than "This application is blocking system shutdown because a CD burn is in progress. Do not shut down."

## See also

[ShutdownBlockReasonDestroy](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-shutdownblockreasondestroy)

[Shutting Down](https://learn.microsoft.com/windows/desktop/Shutdown/shutting-down)
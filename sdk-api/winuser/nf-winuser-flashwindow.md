# FlashWindow function

## Description

Flashes the specified window one time. It does not change the active state of the window.

To flash the window a specified number of times, use the
[FlashWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-flashwindowex) function.

## Parameters

### `hWnd` [in]

A handle to the window to be flashed. The window can be either open or minimized.

### `bInvert` [in]

If this parameter is **TRUE**, the window is flashed from one state to the other. If it is **FALSE**, the window is returned to its original state (either active or inactive).

When an application is minimized and this parameter is **TRUE**, the taskbar window button flashes active/inactive. If it is **FALSE**, the taskbar window button flashes inactive, meaning that it does not change colors. It flashes, as if it were being redrawn, but it does not provide the visual invert clue to the user.

## Return value

The return value specifies the window's state before the call to the
**FlashWindow** function. If the window caption was drawn as active before the call, the return value is nonzero. Otherwise, the return value is zero.

## Remarks

Flashing a window means changing the appearance of its caption bar as if the window were changing from inactive to active status, or vice versa. (An inactive caption bar changes to an active caption bar; an active caption bar changes to an inactive caption bar.)

Typically, a window is flashed to inform the user that the window requires attention but that it does not currently have the keyboard focus.

The
**FlashWindow** function flashes the window only once; for repeated flashing, the application should create a system timer.

## See also

[Error Handling Functions](https://learn.microsoft.com/windows/desktop/Debug/error-handling-functions)

[Notifying the User](https://learn.microsoft.com/windows/desktop/Debug/notifying-the-user)
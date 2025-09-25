# FlashWindowEx function

## Description

Flashes the specified window. It does not change the active state of the window.

## Parameters

### `pfwi` [in]

A pointer to a
[FLASHWINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-flashwinfo) structure.

## Return value

The return value specifies the window's state before the call to the
**FlashWindowEx** function. If the window caption was drawn as active before the call, the return value is nonzero. Otherwise, the return value is zero.

## Remarks

Typically, you flash a window to inform the user that the window requires attention but does not currently have the keyboard focus. When a window flashes, it appears to change from inactive to active status. An inactive caption bar changes to an active caption bar; an active caption bar changes to an inactive caption bar.

## See also

[Error Handling Functions](https://learn.microsoft.com/windows/desktop/Debug/error-handling-functions)

[FLASHWINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-flashwinfo)

[Notifying the User](https://learn.microsoft.com/windows/desktop/Debug/notifying-the-user)
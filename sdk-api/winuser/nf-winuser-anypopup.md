# AnyPopup function

## Description

Indicates whether an owned, visible, top-level pop-up, or overlapped window exists on the screen. The function searches the entire screen, not just the calling application's client area.

This function is provided only for compatibility with 16-bit versions of Windows. It is generally not useful.

## Return value

Type: **BOOL**

If a pop-up window exists, the return value is nonzero, even if the pop-up window is completely covered by other windows.

If a pop-up window does not exist, the return value is zero.

## Remarks

This function does not detect unowned pop-up windows or windows that do not have the **WS_VISIBLE** style bit set.

## See also

**Conceptual**

[GetLastActivePopup](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getlastactivepopup)

**Reference**

[ShowOwnedPopups](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showownedpopups)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
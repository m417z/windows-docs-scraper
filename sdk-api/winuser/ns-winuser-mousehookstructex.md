# MOUSEHOOKSTRUCTEX structure

## Description

Contains information about a mouse event passed to a **WH_MOUSE** hook procedure, [MouseProc](https://learn.microsoft.com/windows/win32/winmsg/mouseproc).

This is an extension of the [MOUSEHOOKSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mousehookstruct) structure that includes information about wheel movement or the use of the X button.

## Members

### `mouseData`

Type: **DWORD**

If the message is [WM_MOUSEWHEEL](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousewheel), the HIWORD of this member is the wheel delta. The LOWORD is undefined and reserved. A positive value indicates that the wheel was rotated forward, away from the user; a negative value indicates that the wheel was rotated backward, toward the user. One wheel click is defined as WHEEL_DELTA, which is 120.

If the message is [WM_XBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-xbuttondown), [WM_XBUTTONUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-xbuttonup), [WM_XBUTTONDBLCLK](https://learn.microsoft.com/windows/desktop/inputdev/wm-xbuttondblclk), [WM_NCXBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncxbuttondown), [WM_NCXBUTTONUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncxbuttonup), or [WM_NCXBUTTONDBLCLK](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncxbuttondblclk), the HIWORD of
**mouseData** specifies which X button was pressed or released, and the LOWORD is undefined and reserved. This member can be one or more of the following values. Otherwise,
**mouseData** is not used.

| Value | Meaning |
| --- | --- |
| **XBUTTON1**<br><br>0x0001 | The first X button was pressed or released. |
| **XBUTTON2**<br><br>0x0002 | The second X button was pressed or released. |

### `tagMOUSEHOOKSTRUCT`

Type: **[MOUSEHOOKSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mousehookstruct)**

The members of a [MOUSEHOOKSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mousehookstruct) structure make up the first part of this structure.

## See also

**Conceptual**

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)

[MOUSEHOOKSTRUCT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mousehookstruct)

[MouseProc](https://learn.microsoft.com/windows/win32/winmsg/mouseproc)

**Reference**

[WM_MOUSEWHEEL](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousewheel)

[WM_NCXBUTTONDBLCLK](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncxbuttondblclk)

[WM_NCXBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncxbuttondown)

[WM_NCXBUTTONUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-ncxbuttonup)

[WM_XBUTTONDBLCLK](https://learn.microsoft.com/windows/desktop/inputdev/wm-xbuttondblclk)

[WM_XBUTTONDOWN](https://learn.microsoft.com/windows/desktop/inputdev/wm-xbuttondown)

[WM_XBUTTONUP](https://learn.microsoft.com/windows/desktop/inputdev/wm-xbuttonup)
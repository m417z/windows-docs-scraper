# GetLastActivePopup function

## Description

Determines which pop-up window owned by the specified window was most recently active.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the owner window.

## Return value

Type: **HWND**

The return value identifies the most recently active pop-up window. The return value is the same as the *hWnd* parameter, if any of the following conditions are met:

* The window identified by hWnd was most recently active.
* The window identified by hWnd does not own any pop-up windows.
* The window identifies by hWnd is not a top-level window, or it is owned by another window.

## See also

[AnyPopup](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-anypopup)

**Conceptual**

**Reference**

[ShowOwnedPopups](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showownedpopups)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
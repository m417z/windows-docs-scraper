# GetWindow function

## Description

Retrieves a handle to a window that has the specified relationship ([Z-Order](https://learn.microsoft.com/windows/desktop/winmsg/window-features) or owner) to the specified window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to a window. The window handle retrieved is relative to this window, based on the value of the *uCmd* parameter.

### `uCmd` [in]

Type: **UINT**

The relationship between the specified window and the window whose handle is to be retrieved. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GW_CHILD**<br><br>5 | The retrieved handle identifies the child window at the top of the Z order, if the specified window is a parent window; otherwise, the retrieved handle is **NULL**. The function examines only child windows of the specified window. It does not examine descendant windows. |
| **GW_ENABLEDPOPUP**<br><br>6 | The retrieved handle identifies the enabled popup window owned by the specified window (the search uses the first such window found using **GW_HWNDNEXT**); otherwise, if there are no enabled popup windows, the retrieved handle is that of the specified window. |
| **GW_HWNDFIRST**<br><br>0 | The retrieved handle identifies the window of the same type that is highest in the Z order.<br><br>If the specified window is a topmost window, the handle identifies a topmost window. If the specified window is a top-level window, the handle identifies a top-level window. If the specified window is a child window, the handle identifies a sibling window. |
| **GW_HWNDLAST**<br><br>1 | The retrieved handle identifies the window of the same type that is lowest in the Z order.<br><br>If the specified window is a topmost window, the handle identifies a topmost window. If the specified window is a top-level window, the handle identifies a top-level window. If the specified window is a child window, the handle identifies a sibling window. |
| **GW_HWNDNEXT**<br><br>2 | The retrieved handle identifies the window below the specified window in the Z order.<br><br>If the specified window is a topmost window, the handle identifies a topmost window. If the specified window is a top-level window, the handle identifies a top-level window. If the specified window is a child window, the handle identifies a sibling window. |
| **GW_HWNDPREV**<br><br>3 | The retrieved handle identifies the window above the specified window in the Z order.<br><br>If the specified window is a topmost window, the handle identifies a topmost window. If the specified window is a top-level window, the handle identifies a top-level window. If the specified window is a child window, the handle identifies a sibling window. |
| **GW_OWNER**<br><br>4 | The retrieved handle identifies the specified window's owner window, if any. For more information, see [Owned Windows](https://learn.microsoft.com/windows/desktop/winmsg/window-features). |

## Return value

Type: **HWND**

If the function succeeds, the return value is a window handle. If no window exists with the specified relationship to the specified window, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The [EnumChildWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumchildwindows) function is more reliable than calling **GetWindow** in a loop. An application that calls **GetWindow** to perform this task risks being caught in an infinite loop or referencing a handle to a window that has been destroyed.

## See also

**Conceptual**

[EnumChildWindows](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumchildwindows)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
# GetNextWindow macro

## Description

Retrieves a handle to the next or previous window in the [Z-Order](https://learn.microsoft.com/windows/desktop/winmsg/window-features). The next window is below the specified window; the previous window is above.

If the specified window is a topmost window, the function searches for a topmost window. If the specified window is a top-level window, the function searches for a top-level window. If the specified window is a child window, the function searches for a child window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to a window. The window handle retrieved is relative to this window, based on the value of the *wCmd* parameter.

### `wCmd` [in]

Type: **UINT**

Indicates whether the function returns a handle to the next window or the previous window. This parameter can be either of the following values.

| Value | Meaning |
| --- | --- |
| **GW_HWNDNEXT**<br><br>2 | Returns a handle to the window below the given window. |
| **GW_HWNDPREV**<br><br>3 | Returns a handle to the window above the given window. |

## Return value

Type: **HWND**

If the function succeeds, the return value is a window handle. If no window exists with the specified relationship to the specified window, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function is implemented as a call to the [GetWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindow) function.

``` syntax
#define GetNextWindow(hWnd, wCmd) GetWindow(hWnd, wCmd)
```

## Syntax

```cpp
HWND GetNextWindow(
  [in] hWnd,
  [in] wCmd
);
```

## See also

**Conceptual**

[GetTopWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-gettopwindow)

[GetWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindow)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)
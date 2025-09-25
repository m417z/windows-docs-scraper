# IsWindowEnabled function

## Description

Determines whether the specified window is enabled for mouse and keyboard input.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window to be tested.

## Return value

Type: **BOOL**

If the window is enabled, the return value is nonzero.

If the window is not enabled, the return value is zero.

## Remarks

A child window receives input only if it is both enabled and visible.

## See also

**Conceptual**

[EnableWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enablewindow)

[IsWindowVisible](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-iswindowvisible)

[Keyboard Input](https://learn.microsoft.com/windows/desktop/inputdev/keyboard-input)

**Reference**
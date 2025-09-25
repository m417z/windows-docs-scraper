# Pager_ForwardMouse macro

## Syntax

```cpp
VOID Pager_ForwardMouse(
   HWND hwnd,
   BOOL bForward
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is not used.

## Description

Enables or disables mouse forwarding for the pager control. When mouse forwarding is enabled, the pager control forwards [WM_MOUSEMOVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousemove) messages to the contained window. You can use this macro or send the [PGM_FORWARDMOUSE](https://learn.microsoft.com/windows/desktop/Controls/pgm-forwardmouse) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the pager control.

### `bForward`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**BOOL** value that determines if mouse forwarding is enabled or disabled. If this value is nonzero, mouse forwarding is enabled. If this value is zero, mouse forwarding is disabled.
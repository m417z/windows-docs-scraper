# ScrollBar_Show macro

## Syntax

```cpp
BOOL ScrollBar_Show(
   HWND hwndCtl,
   BOOL fShow
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

**TRUE** if the window was previously visible, or **FALSE** if it was previously hidden.

## Description

Shows or hides a scroll bar control.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `fShow`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to show the control, or **FALSE** to hide it.
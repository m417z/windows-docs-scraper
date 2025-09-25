# Edit_Enable macro

## Syntax

```cpp
BOOL Edit_Enable(
   HWND hwndCtl,
   BOOL fEnable
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Zero if the window was previously disabled; otherwise nonzero.

## Description

Enables or disables an edit control.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the edit control.

### `fEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to enable the control, or **FALSE** to disable it.
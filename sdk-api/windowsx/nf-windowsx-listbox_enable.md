# ListBox_Enable macro

## Syntax

```cpp
BOOL ListBox_Enable(
   HWND hwndCtl,
   BOOL fEnable
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

**TRUE** if the window was previously disabled, or **FALSE** if it was previously enabled.

## Description

Enables or disables a list box control.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `fEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to enable the control, or **FALSE** to disable it.
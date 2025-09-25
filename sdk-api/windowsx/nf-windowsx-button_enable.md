# Button_Enable macro

## Syntax

```cpp
BOOL Button_Enable(
   HWND hwndCtl,
   BOOL fEnable
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Zero if the window was previously disabled; otherwise nonzero.

## Description

Enables or disables a button.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the button control.

### `fEnable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to enable the button, or **FALSE** to disable it.
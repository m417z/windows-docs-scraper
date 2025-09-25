# Static_SetIcon macro

## Syntax

```cpp
HICON Static_SetIcon(
   HWND  hwndCtl,
   HICON hIcon
);
```

## Return value

Type: **[HICON](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

A handle to the icon previously associated with the icon control, or zero if an error occurs.

## Description

Sets the icon for a static control. You can use this macro or send the [STM_SETICON](https://learn.microsoft.com/windows/desktop/Controls/stm-seticon) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `hIcon`

Type: **[HICON](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

a handle to the icon.
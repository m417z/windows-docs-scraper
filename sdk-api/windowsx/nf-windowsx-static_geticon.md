# Static_GetIcon macro

## Syntax

```cpp
HICON Static_GetIcon(
   HWND  hwndCtl
   HICON hIcon
);
```

## Return value

Type: **[HICON](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

A handle to the icon, or **NULL** if the static control has no associated icon or if an error occurred.

## Description

Retrieves a handle to the icon associated with a static control that has the SS_ICON style. You can use this macro or send the [STM_GETICON](https://learn.microsoft.com/windows/desktop/Controls/stm-geticon) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `hIcon`

Type: **[HICON](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the icon.
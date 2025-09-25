# TabCtrl_SetExtendedStyle macro

## Syntax

```cpp
DWORD TabCtrl_SetExtendedStyle(
   HWND  hwnd,
   DWORD dw
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **DWORD** value that contains the previous tab control extended styles.

## Description

Sets the extended styles that the tab control will use. You can use this macro or send the [TCM_SETEXTENDEDSTYLE](https://learn.microsoft.com/windows/desktop/Controls/tcm-setextendedstyle) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `dw`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value that contains the new tab control extended styles. This value is a combination of tab control [extended styles](https://learn.microsoft.com/windows/desktop/Controls/tab-control-extended-styles).
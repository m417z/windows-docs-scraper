# TabCtrl_GetExtendedStyle macro

## Syntax

```cpp
DWORD TabCtrl_GetExtendedStyle(
   HWND hwnd
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **DWORD** value that represents the extended styles currently in use for the tab control. This value is a combination of tab control extended styles.

## Description

Retrieves the extended styles that are currently in use for the tab control. You can use this macro or send the [TCM_GETEXTENDEDSTYLE](https://learn.microsoft.com/windows/desktop/Controls/tcm-getextendedstyle) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.
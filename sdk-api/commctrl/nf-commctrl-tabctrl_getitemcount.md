# TabCtrl_GetItemCount macro

## Syntax

```cpp
int TabCtrl_GetItemCount(
   HWND hwnd
);
```

## Return value

Type: **int**

Returns the number of items if successful, or zero otherwise.

## Description

Retrieves the number of tabs in the tab control. You can use this macro or send the [TCM_GETITEMCOUNT](https://learn.microsoft.com/windows/desktop/Controls/tcm-getitemcount) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.
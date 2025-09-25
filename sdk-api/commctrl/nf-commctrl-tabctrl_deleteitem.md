# TabCtrl_DeleteItem macro

## Syntax

```cpp
BOOL TabCtrl_DeleteItem(
   HWND hwnd,
   int  i
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Removes an item from a tab control. You can use this macro or send the [TCM_DELETEITEM](https://learn.microsoft.com/windows/desktop/Controls/tcm-deleteitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `i`

Type: **int**

Index of the item to delete.
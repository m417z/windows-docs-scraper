# TabCtrl_DeleteAllItems macro

## Syntax

```cpp
BOOL TabCtrl_DeleteAllItems(
   HWND hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Removes all items from a tab control. You can use this macro or send the [TCM_DELETEALLITEMS](https://learn.microsoft.com/windows/desktop/Controls/tcm-deleteallitems) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.
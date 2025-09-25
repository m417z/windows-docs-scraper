# TabCtrl_GetRowCount macro

## Syntax

```cpp
int TabCtrl_GetRowCount(
   HWND hwnd
);
```

## Return value

Type: **int**

Returns the number of rows of tabs.

## Description

Retrieves the current number of rows of tabs in a tab control. You can use this macro or send the [TCM_GETROWCOUNT](https://learn.microsoft.com/windows/desktop/Controls/tcm-getrowcount) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

## Remarks

Only tab controls that have the [TCS_MULTILINE](https://learn.microsoft.com/windows/desktop/Controls/tab-control-styles) style can have multiple rows of tabs.
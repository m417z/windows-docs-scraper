# TabCtrl_SetMinTabWidth macro

## Syntax

```cpp
int TabCtrl_SetMinTabWidth(
   HWND hwnd,
   int  x
);
```

## Return value

Type: **int**

Returns a value of type **int** that represents the previous minimum tab width.

## Description

Sets the minimum width of items in a tab control. You can use this macro or send the [TCM_SETMINTABWIDTH](https://learn.microsoft.com/windows/desktop/Controls/tcm-setmintabwidth) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `x`

Type: **int**

Minimum width to be set for a tab control item. If this parameter is set to -1, the control will use the default tab width.
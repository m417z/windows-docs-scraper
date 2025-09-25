# TabCtrl_GetCurFocus macro

## Syntax

```cpp
int TabCtrl_GetCurFocus(
   HWND hwnd
);
```

## Return value

Type: **int**

Returns the index of the tab item that has the focus.

## Description

Returns the index of the item that has the focus in a tab control. You can use this macro or send the [TCM_GETCURFOCUS](https://learn.microsoft.com/windows/desktop/Controls/tcm-getcurfocus) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

## Remarks

The item that has the focus may be different than the selected item.
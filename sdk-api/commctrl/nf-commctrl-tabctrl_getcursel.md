# TabCtrl_GetCurSel macro

## Syntax

```cpp
int TabCtrl_GetCurSel(
   HWND hwnd
);
```

## Return value

Type: **int**

Returns the index of the selected tab if successful, or -1 if no tab is selected.

## Description

Determines the currently selected tab in a tab control. You can use this macro or send the [TCM_GETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/tcm-getcursel) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.
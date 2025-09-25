# TabCtrl_SetCurSel macro

## Syntax

```cpp
int TabCtrl_SetCurSel(
   HWND hwnd,
   int  i
);
```

## Return value

Type: **int**

Returns the index of the previously selected tab if successful, or -1 otherwise.

## Description

Selects a tab in a tab control. You can use this macro or send the [TCM_SETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/tcm-setcursel) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `i`

Type: **int**

Index of the tab to select.

## Remarks

A tab control does not send a [TCN_SELCHANGING](https://learn.microsoft.com/windows/desktop/Controls/tcn-selchanging) or [TCN_SELCHANGE](https://learn.microsoft.com/windows/desktop/Controls/tcn-selchange) notification code when a tab is selected using the [TCM_SETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/tcm-setcursel) message.
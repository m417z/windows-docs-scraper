# TabCtrl_SetToolTips macro

## Syntax

```cpp
void TabCtrl_SetToolTips(
   HWND hwnd,
   HWND hwndTT
);
```

## Description

Assigns a tooltip control to a tab control. You can use this macro or send the [TCM_SETTOOLTIPS](https://learn.microsoft.com/windows/desktop/Controls/tcm-settooltips) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `hwndTT`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tooltip control.

## Remarks

You can retrieve the tooltip control associated with a tab control by using the [TCM_GETTOOLTIPS](https://learn.microsoft.com/windows/desktop/Controls/tcm-gettooltips) message.
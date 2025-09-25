# TabCtrl_GetToolTips macro

## Syntax

```cpp
HWND TabCtrl_GetToolTips(
   HWND hwnd
);
```

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the handle to the tooltip control if successful, or **NULL** otherwise.

## Description

Retrieves the handle to the tooltip control associated with a tab control. You can use this macro or send the [TCM_GETTOOLTIPS](https://learn.microsoft.com/windows/desktop/Controls/tcm-gettooltips) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

## Remarks

A tab control creates a tooltip control if it has the [TCS_TOOLTIPS](https://learn.microsoft.com/windows/desktop/Controls/tab-control-styles). You can also assign a tooltip control to a tab control by using the [TCM_SETTOOLTIPS](https://learn.microsoft.com/windows/desktop/Controls/tcm-settooltips) message.
# TabCtrl_DeselectAll macro

## Syntax

```cpp
VOID TabCtrl_DeselectAll(
   HWND hwnd,
   UINT fExcludeFocus
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The return value is not used.

## Description

Resets items in a tab control, clearing any that were set to the [TCIS_BUTTONPRESSED](https://learn.microsoft.com/windows/desktop/Controls/tab-control-item-states) state. You can use this macro or send the [TCM_DESELECTALL](https://learn.microsoft.com/windows/desktop/Controls/tcm-deselectall) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `fExcludeFocus`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag value that specifies the scope of the item deselection. If this parameter is set to **FALSE**, all tab items will be reset. If it is set to **TRUE**, all but the currently selected tab item will be reset.

## Remarks

This message is only meaningful if the [TCS_BUTTONS](https://learn.microsoft.com/windows/desktop/Controls/tab-control-styles) style flag has been set.
# TabCtrl_SetPadding macro

## Syntax

```cpp
void TabCtrl_SetPadding(
   HWND hwnd,
   int  cx,
   int  cy
);
```

## Description

Sets the amount of space (padding) around each tab's icon and label in a tab control. You can use this macro or send the [TCM_SETPADDING](https://learn.microsoft.com/windows/desktop/Controls/tcm-setpadding) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `cx`

Type: **int**

Amount of horizontal padding, in pixels.

### `cy`

Type: **int**

Amount of vertical padding, in pixels.
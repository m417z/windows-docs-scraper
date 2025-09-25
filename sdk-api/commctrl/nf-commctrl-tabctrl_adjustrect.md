# TabCtrl_AdjustRect macro

## Syntax

```cpp
VOID TabCtrl_AdjustRect(
   HWND hwnd,
   BOOL bLarger,
   RECT *prc
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No return value.

## Description

Calculates a tab control's display area given a window rectangle, or calculates the window rectangle that would correspond to a specified display area. You can use this macro or send the [TCM_ADJUSTRECT](https://learn.microsoft.com/windows/desktop/Controls/tcm-adjustrect) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tab control.

### `bLarger`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Operation to perform. If this parameter is **TRUE**,
*prc* specifies a display rectangle and receives the corresponding window rectangle. If this parameter is **FALSE**,
*prc* specifies a window rectangle and receives the corresponding display area.

### `prc`

Type: **[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)***

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the given rectangle and receives the calculated rectangle.

## Remarks

This message applies only to tab controls that are at the top. It does not apply to tab controls that are on the sides or bottom.
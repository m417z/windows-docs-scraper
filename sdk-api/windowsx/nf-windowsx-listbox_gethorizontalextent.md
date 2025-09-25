# ListBox_GetHorizontalExtent macro

## Syntax

```cpp
int ListBox_GetHorizontalExtent(
   HWND hwndCtl
);
```

## Return value

Type: **int**

The scrollable width, in pixels, of the list box.

## Description

Gets the width that a list box can be scrolled horizontally (the scrollable width) if the list box has a horizontal scroll bar. You can use this macro or send the [LB_GETHORIZONTALEXTENT](https://learn.microsoft.com/windows/desktop/Controls/lb-gethorizontalextent) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

## Remarks

For more information, see [LB_GETHORIZONTALEXTENT](https://learn.microsoft.com/windows/desktop/Controls/lb-gethorizontalextent).
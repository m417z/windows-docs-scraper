# ListBox_SetHorizontalExtent macro

## Syntax

```cpp
void ListBox_SetHorizontalExtent(
   HWND hwndCtl,
   int  cxExtent
);
```

## Description

Set the width by which a list box can be scrolled horizontally (the scrollable width). If the width of the list box is smaller than this value, the horizontal scroll bar horizontally scrolls items in the list box. If the width of the list box is equal to or greater than this value, the horizontal scroll bar is hidden. You can use this macro or send the [LB_SETHORIZONTALEXTENT](https://learn.microsoft.com/windows/desktop/Controls/lb-sethorizontalextent) message explicitly.

## Parameters

### `hwndCtl`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the control.

### `cxExtent`

Type: **int**

The number of pixels by which the list box can be scrolled.

## Remarks

For more information, see [LB_SETHORIZONTALEXTENT](https://learn.microsoft.com/windows/desktop/Controls/lb-sethorizontalextent).
# ListView_Scroll macro

## Syntax

```cpp
BOOL ListView_Scroll(
   HWND hwndLV,
   int  dx,
   int  dy
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Scrolls the content of a list-view control. You can use this macro or send the [LVM_SCROLL](https://learn.microsoft.com/windows/desktop/Controls/lvm-scroll) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `dx`

Type: **int**

A value of type **int** that specifies the amount of horizontal scrolling, in pixels, relative to the current position of the list view content. If the list-view control is in list view, this value is rounded up to the nearest number of pixels that form a whole column.

### `dy`

Type: **int**

A value of type **int** that specifies the amount of vertical scrolling, in pixels, relative to the current position of the list view content.

## Remarks

When the list-view control is in report view, the control can only be scrolled vertically in whole line increments. Therefore, the
*dy* parameter will be rounded to the nearest number of pixels that form a whole line increment. For example, if the height of a line is 16 pixels and 8 is passed for *dy*, the list will be scrolled by 16 pixels (1 line). If 7 is passed for *dy*, the list will be scrolled 0 pixels (0 lines).
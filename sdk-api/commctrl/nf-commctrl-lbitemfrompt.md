# LBItemFromPt function

## Description

Retrieves the index of the item at the specified point in a list box.

## Parameters

### `hLB`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list box to check.

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that contains the screen coordinates to check.

### `bAutoScroll`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A scroll flag. If this parameter is **TRUE** and the point is directly above or below the list box, the function scrolls the list box by one line and returns -1. Otherwise, the function does not scroll the list box.

## Return value

Type: **int**

Returns the item identifier if the point is over a list item, or -1 otherwise.

## Remarks

The **LBItemFromPt** function only scrolls the list box if a minimum amount of time has passed since it last did so. Timing prevents the list box from scrolling too quickly if the function is called repeatedly in rapid succession—for example, when [DL_DRAGGING](https://learn.microsoft.com/windows/desktop/Controls/dl-dragging) notification codes or [WM_MOUSEMOVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousemove) messages are processed.

If the specified point is outside the client area of the list box and
*bAutoScroll* is **TRUE**, the function scrolls the list box instead of returning an item identifier.
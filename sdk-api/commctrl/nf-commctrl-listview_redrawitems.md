# ListView_RedrawItems macro

## Syntax

```cpp
BOOL ListView_RedrawItems(
   HWND hwndLV,
   int  iFirst,
   int  iLast
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Forces a list-view control to redraw a range of items. You can use this macro or send the [LVM_REDRAWITEMS](https://learn.microsoft.com/windows/desktop/Controls/lvm-redrawitems) message explicitly.

## Parameters

### `hwndLV`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iFirst`

Type: **int**

The index of the first item to redraw.

### `iLast`

Type: **int**

The index of the last item to redraw.

## Remarks

The specified items are not actually redrawn until the list-view window receives a [WM_PAINT](https://learn.microsoft.com/windows/desktop/gdi/wm-paint) message to repaint. To repaint immediately, call the [UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow) function after using this macro.
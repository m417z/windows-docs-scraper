# ListView_ApproximateViewRect macro

## Syntax

```cpp
DWORD ListView_ApproximateViewRect(
   HWND hwnd,
   int    iWidth,
   int    iHeight,
   int    iCount
);
```

## Return value

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **DWORD** value that holds the approximate width (in the LOWORD) and height (in the HIWORD) needed to display the items, in pixels.

## Description

Calculates the approximate width and height required to display a given number of items. You can use this macro or send the [LVM_APPROXIMATEVIEWRECT](https://learn.microsoft.com/windows/desktop/Controls/lvm-approximateviewrect) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the list-view control.

### `iWidth`

Type: **int**

The proposed x-dimension of the control, in pixels. This parameter can be -1 to allow the message to use the current width value.

### `iHeight`

Type: **int**

The proposed y-dimension of the control, in pixels. This parameter can be -1 to allow the message to use the current height value.

### `iCount`

Type: **int**

The number of items to be displayed in the control. If this parameter is -1, the message uses the total number of items in the control.
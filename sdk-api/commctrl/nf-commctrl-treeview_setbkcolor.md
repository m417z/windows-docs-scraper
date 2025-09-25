# TreeView_SetBkColor macro

## Syntax

```cpp
COLORREF TreeView_SetBkColor(
   HWND     hwnd,
   COLORREF clr
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **COLORREF** value that represents the previous background color. If this value is -1, the control was using the system color for the background color.

## Description

Sets the background color of the control. You can use this macro or send the [TVM_SETBKCOLOR](https://learn.microsoft.com/windows/desktop/Controls/tvm-setbkcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a tree-view control.

### `clr`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value that contains the new background color. If this argument is -1, the control will revert to using the system color for the background color.

## See also

[TreeView_GetBkColor](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getbkcolor)
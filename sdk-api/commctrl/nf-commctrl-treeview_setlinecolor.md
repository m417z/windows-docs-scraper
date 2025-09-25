# TreeView_SetLineColor macro

## Syntax

```cpp
COLORREF TreeView_SetLineColor(
   HWND     hwnd,
   COLORREF clr
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns the previous line color.

## Description

Sets the current line color. You can also use the [TVM_SETLINECOLOR](https://learn.microsoft.com/windows/desktop/Controls/tvm-setlinecolor) message directly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `clr`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) that specifies the new line color. Use the CLR_DEFAULT value to restore the system default colors.

## Remarks

This message only changes line colors. To change the colors of the plus sign (+) and minus sign (-) inside the buttons, use the [TreeView_SetTextColor](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_settextcolor) macro.

## See also

[TVM_SETLINECOLOR](https://learn.microsoft.com/windows/desktop/Controls/tvm-setlinecolor)
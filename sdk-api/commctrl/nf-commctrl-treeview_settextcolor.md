# TreeView_SetTextColor macro

## Syntax

```cpp
COLORREF TreeView_SetTextColor(
   HWND     hwnd,
   COLORREF clr
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **COLORREF** value that represents the previous text color. If this value is -1, the control was using the system color for the text color.

## Description

Sets the text color of the control. You can use this macro or send the [TVM_SETTEXTCOLOR](https://learn.microsoft.com/windows/desktop/Controls/tvm-settextcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a tree-view control.

### `clr`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value that contains the new text color. If this argument is -1, the control will revert to using the system color for the text color.

## See also

[TreeView_GetTextColor](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_gettextcolor)
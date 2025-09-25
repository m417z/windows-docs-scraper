# TreeView_GetBkColor macro

## Syntax

```cpp
COLORREF TreeView_GetBkColor(
   HWND hwnd
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **COLORREF** value that represents the current background color. If this value is -1, the control is using the system color for the background color.

## Description

Retrieves the current background color of the control. You can use this macro or send the [TVM_GETBKCOLOR](https://learn.microsoft.com/windows/desktop/Controls/tvm-getbkcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a tree-view control.

## See also

[TreeView_SetBkColor](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_setbkcolor)
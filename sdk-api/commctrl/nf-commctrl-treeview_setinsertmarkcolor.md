# TreeView_SetInsertMarkColor macro

## Syntax

```cpp
COLORREF TreeView_SetInsertMarkColor(
   HWND     hwnd,
   COLORREF clr
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **COLORREF** value that contains the previous insertion mark color.

## Description

Sets the color used to draw the insertion mark for the tree view. You can use this macro or send the [TVM_SETINSERTMARKCOLOR](https://learn.microsoft.com/windows/desktop/Controls/tvm-setinsertmarkcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a tree-view control.

### `clr`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value that contains the new insertion mark color.

## See also

[TreeView_GetInsertMarkColor](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getinsertmarkcolor)
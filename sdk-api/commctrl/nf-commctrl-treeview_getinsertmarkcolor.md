# TreeView_GetInsertMarkColor macro

## Syntax

```cpp
COLORREF TreeView_GetInsertMarkColor(
   HWND hwnd
);
```

## Return value

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns a **COLORREF** value that contains the current insertion mark color.

## Description

Retrieves the color used to draw the insertion mark for the tree view. You can use this macro or send the [TVM_GETINSERTMARKCOLOR](https://learn.microsoft.com/windows/desktop/Controls/tvm-getinsertmarkcolor) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

## See also

[TreeView_SetInsertMarkColor](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_setinsertmarkcolor)
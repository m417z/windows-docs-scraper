# TreeView_GetSelection macro

## Syntax

```cpp
HTREEITEM TreeView_GetSelection(
   HWND hwnd
);
```

## Return value

Type: **HTREEITEM**

Returns the handle to the item if successful, or **NULL** otherwise.

## Description

Retrieves the currently selected item in a tree-view control. You can use this macro, or you can explicitly send the [TVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getnextitem) message with the TVGN_CARET flag.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

## See also

[TreeView_GetNextItem](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextitem)
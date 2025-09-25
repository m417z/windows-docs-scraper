# TreeView_GetPrevVisible macro

## Syntax

```cpp
HTREEITEM TreeView_GetPrevVisible(
   HWND      hwnd,
   HTREEITEM hitem
);
```

## Return value

Type: **HTREEITEM**

Returns the handle to the item if successful, or **NULL** otherwise.

## Description

Retrieves the first visible item that precedes a specified item in a tree-view control. You can use this macro, or you can explicitly send the [TVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getnextitem) message with the TVGN_PREVIOUSVISIBLE flag.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to an item. The specified item must be visible. Use the [TVM_GETITEMRECT](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitemrect) message to determine whether an item is visible.

## See also

**Reference**

[TreeView_GetFirstVisible](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getfirstvisible)

[TreeView_GetNextItem](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextitem)

[TreeView_GetNextVisible](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextvisible)
# TreeView_GetChild macro

## Syntax

```cpp
HTREEITEM TreeView_GetChild(
   HWND      hwnd,
   HTREEITEM hitem
);
```

## Return value

Type: **HTREEITEM**

Returns the handle to the item if successful, or **NULL** otherwise.

## Description

Retrieves the first child item of the specified tree-view item. You can use this macro, or you can explicitly send the [TVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getnextitem) message with the TVGN_CHILD flag.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to a tree-view item.

## See also

**Reference**

[TreeView_GetNextItem](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextitem)

[TreeView_GetNextSibling](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextsibling)

[TreeView_GetParent](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getparent)

[TreeView_GetPrevSibling](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getprevsibling)
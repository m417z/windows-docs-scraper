# TreeView_GetPrevSibling macro

## Syntax

```cpp
HTREEITEM TreeView_GetPrevSibling(
   HWND      hwnd,
   HTREEITEM hitem
);
```

## Return value

Type: **HTREEITEM**

Returns the handle to the item if successful, or **NULL** otherwise.

## Description

Retrieves the previous sibling item of a specified item in a tree-view control. You can use this macro, or you can explicitly send the [TVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getnextitem) message with the TVGN_PREVIOUS flag.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to an item.

## See also

**Reference**

[TreeView_GetChild](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getchild)

[TreeView_GetNextItem](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextitem)

[TreeView_GetNextSibling](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextsibling)

[TreeView_GetParent](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getparent)
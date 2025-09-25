# TreeView_GetParent macro

## Syntax

```cpp
HTREEITEM TreeView_GetParent(
   HWND      hwnd,
   HTREEITEM hitem
);
```

## Return value

Type: **HTREEITEM**

Returns the handle to the item if successful. For most cases, the message returns a **NULL** value to indicate an error. See the Remarks section for details.

## Description

Retrieves the parent item of the specified tree-view item. You can use this macro, or you can explicitly send the [TVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getnextitem) message with the TVGN_PARENT flag.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to an item.

## Return value

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The handle to the parent item of this tree-view item, or NULL.

## Remarks

This macro will return **NULL** if the parent of the specified item is the root node of the tree.

## See also

**Reference**

[TreeView_GetChild](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getchild)

[TreeView_GetNextItem](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextitem)

[TreeView_GetNextSibling](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextsibling)

[TreeView_GetPrevSibling](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getprevsibling)
# TreeView_DeleteItem macro

## Syntax

```cpp
BOOL TreeView_DeleteItem(
   HWND      hwnd,
   HTREEITEM hitem
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Removes an item and all its children from a tree-view control. You can also send the [TVM_DELETEITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-deleteitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

**HTREEITEM** handle to the item to delete. If *hitem* is set to TVI_ROOT, all items are deleted from the tree-view control. You can also use the [TreeView_DeleteAllItems](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_deleteallitems) macro to delete all items.

## Remarks

It is not safe to delete items in response to a notification such as [TVN_SELCHANGING](https://learn.microsoft.com/windows/desktop/Controls/tvn-selchanging).

Once an item is deleted, its handle is invalid and cannot be used.

The parent window receives a [TVN_DELETEITEM](https://learn.microsoft.com/windows/desktop/Controls/tvn-deleteitem) notification code when each item is removed.

If the item label is being edited, the edit operation is canceled and the parent window receives the [TVN_ENDLABELEDIT](https://learn.microsoft.com/windows/desktop/Controls/tvn-endlabeledit) notification code.

If you delete all items in a tree-view control that has the [TVS_NOSCROLL](https://learn.microsoft.com/windows/desktop/Controls/tree-view-control-window-styles) style, items subsequently added may not display properly. For more information, see [TreeView_DeleteAllItems](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_deleteallitems).
# TreeView_SelectDropTarget macro

## Syntax

```cpp
BOOL TreeView_SelectDropTarget(
   HWND      hwnd,
   HTREEITEM hitem
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Redraws a specified tree-view control item in the style used to indicate the target of a drag-and-drop operation. You can use this macro or the [TreeView_Select](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_select) macro, or you can send the [TVM_SELECTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-selectitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to an item. If the *hitem* parameter is **NULL**, the control is set to have no selected item.

## Remarks

If the specified item is the child of a collapsed parent item, the parent's list of child items is expanded to reveal the specified item. In this case, the parent window receives the [TVN_ITEMEXPANDING](https://learn.microsoft.com/windows/desktop/Controls/tvn-itemexpanding) and [TVN_ITEMEXPANDED](https://learn.microsoft.com/windows/desktop/Controls/tvn-itemexpanded) notification codes.

Using the **TreeView_SelectDropTarget** macro is equivalent to sending the [TVM_SELECTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-selectitem) message with its
*flag* parameter set to the TVGN_DROPHILITE value.
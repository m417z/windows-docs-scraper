# TreeView_DeleteAllItems macro

## Syntax

```cpp
BOOL TreeView_DeleteAllItems(
   HWND hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Deletes all items from a tree-view control.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

## Remarks

Once an item is deleted from a tree-view control, its **HTREEITEM** handle is invalid and cannot be used.

The parent window receives a [TVN_DELETEITEM](https://learn.microsoft.com/windows/desktop/Controls/tvn-deleteitem) notification code when each item is removed.

If the item label is being edited, the edit operation is canceled and the parent window receives the [TVN_ENDLABELEDIT](https://learn.microsoft.com/windows/desktop/Controls/tvn-endlabeledit) notification code.

You can also delete all items with the [TreeView_DeleteItem](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_deleteitem) macro or the [TVM_DELETEITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-deleteitem) message by setting
*lParam* to TVI_ROOT.

If the window style for a tree-view control contains TVS_NOSCROLL and all items are deleted, new items are not displayed until the window styles are reset. The following code shows one way to ensure that items are always displayed.

```
DWORD styles = GetWindowLong(hwnd, GWL_STYLE);
TreeView_DeleteAllItems(hwnd);
SetWindowLong(hwnd, GWL_STYLE, styles);
```
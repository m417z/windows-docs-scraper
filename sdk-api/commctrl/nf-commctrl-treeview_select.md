# TreeView_Select macro

## Syntax

```cpp
BOOL TreeView_Select(
   HWND      hwnd,
   HTREEITEM hitem,
   UINT      code
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Selects the specified tree-view item, scrolls the item into view, or redraws the item in the style used to indicate the target of a drag-and-drop operation. You can use this macro or the [TreeView_SelectItem](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_selectitem), [TreeView_SelectSetFirstVisible](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_selectsetfirstvisible), or [TreeView_SelectDropTarget](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_selectdroptarget) macros, or you can send the [TVM_SELECTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-selectitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to an item. If the *hitem* parameter is **NULL**, the control is set to have no selected item.

### `code`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Action flag. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **TVGN_CARET** | Sets the selection to the given item. The control's parent window receives the [TVN_SELCHANGING](https://learn.microsoft.com/windows/desktop/Controls/tvn-selchanging) and [TVN_SELCHANGED](https://learn.microsoft.com/windows/desktop/Controls/tvn-selchanged) notification codes. |
| **TVGN_DROPHILITE** | Redraws the given item in the style used to indicate the target of a drag-and-drop operation. |
| **TVGN_FIRSTVISIBLE** | Ensures that the specified item is visible, and, if possible, displays it at the top of the control's window. Tree-view controls display as many items as will fit in the window. If the specified item is near the bottom of the control's hierarchy of items, it might not become the first visible item, depending on how many items fit in the window. |

## Remarks

If the specified item is the child of a collapsed parent item, the parent's list of child items is expanded to reveal the specified item. In this case, the parent window receives the [TVN_ITEMEXPANDING](https://learn.microsoft.com/windows/desktop/Controls/tvn-itemexpanding) and [TVN_ITEMEXPANDED](https://learn.microsoft.com/windows/desktop/Controls/tvn-itemexpanded) notification codes.
# TreeView_GetNextItem macro

## Syntax

```cpp
HTREEITEM TreeView_GetNextItem(
   HWND      hwnd,
   HTREEITEM hitem,
   UINT      code
);
```

## Return value

Type: **HTREEITEM**

Returns the handle to the item if successful. For most cases, the message returns a **NULL** value to indicate an error. See the Remarks section for details.

## Description

Retrieves the tree-view item that bears the specified relationship to a specified item. You can use this macro, use one of the **TreeView_Get** macros described below, or send the [TVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getnextitem) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to an item.

### `code`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flag specifying the item to retrieve. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **TVGN_CARET** | Retrieves the currently selected item. You can use the [TreeView_GetSelection](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getselection) macro to send this message. |
| **TVGN_CHILD** | Retrieves the first child item of the item specified by the *hitem* parameter. You can use the [TreeView_GetChild](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getchild) macro to send this message. |
| **TVGN_DROPHILITE** | Retrieves the item that is the target of a drag-and-drop operation. You can use the [TreeView_GetDropHilight](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getdrophilight) macro to send this message. |
| **TVGN_FIRSTVISIBLE** | Retrieves the first visible item. You can use the [TreeView_GetFirstVisible](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getfirstvisible) macro to send this message. |
| **TVGN_NEXT** | Retrieves the next sibling item. You can use the [TreeView_GetNextSibling](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextsibling) macro to send this message. |
| **TVGN_NEXTSELECTED** | **Windows Vista and later.** Retrieves the next selected item. You can use the [TreeView_GetNextSelected](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextselected) macro to send this message. |
| **TVGN_NEXTVISIBLE** | Retrieves the next visible item that follows the specified item. The specified item must be visible. Use the [TVM_GETITEMRECT](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitemrect) message to determine whether an item is visible. You can use the [TreeView_GetNextVisible](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextvisible) macro to send this message. |
| **TVGN_PARENT** | Retrieves the parent of the specified item. You can use the [TreeView_GetParent](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getparent) macro to send this message. |
| **TVGN_PREVIOUS** | Retrieves the previous sibling item. You can use the [TreeView_GetPrevSibling](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getprevsibling) macro to send this message. |
| **TVGN_PREVIOUSVISIBLE** | Retrieves the first visible item that precedes the specified item. The specified item must be visible. Use the [TVM_GETITEMRECT](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitemrect) message to determine whether an item is visible. You can use the [TreeView_GetPrevVisible](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getprevvisible) macro to send this message. |
| **TVGN_ROOT** | Retrieves the topmost or very first item of the tree-view control. You can use the [TreeView_GetRoot](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getroot) macro to send this message. |

## Remarks

This macro will return **NULL** if the item being retrieved is the root node of the tree. For example, if you use this macro with the TVGN_PARENT flag on a first-level child of the tree view's root node, the macro will return **NULL**.
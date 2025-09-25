# TreeView_GetFirstVisible macro

## Syntax

```cpp
HTREEITEM TreeView_GetFirstVisible(
   HWND hwnd
);
```

## Return value

Type: **HTREEITEM**

Returns the handle to the item if successful, or **NULL** otherwise.

## Description

Retrieves the first visible item in a tree-view control window. You can use this macro, or you can explicitly send the [TVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getnextitem) message with the TVGN_FIRSTVISIBLE flag.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

## See also

**Reference**

[TVM_GETITEMRECT](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitemrect)

[TreeView_GetLastVisible](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getlastvisible)

[TreeView_GetNextVisible](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextvisible)

[TreeView_GetPrevVisible](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getprevvisible)
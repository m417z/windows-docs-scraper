# TreeView_GetLastVisible macro

## Syntax

```cpp
HTREEITEM TreeView_GetLastVisible(
   HWND hwnd
);
```

## Return value

Type: **HTREEITEM**

Returns the handle to the item if successful, or **NULL** otherwise.

## Description

Retrieves the last expanded item in a tree-view control. This does not retrieve the last item visible in the tree-view window. You can use this macro, or you can explicitly send the [TVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getnextitem) message with the TVGN_LASTVISIBLE flag.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

## See also

**Reference**

[TVM_GETITEMRECT](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitemrect)

[TreeView_GetFirstVisible](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getfirstvisible)

[TreeView_GetNextVisible](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextvisible)

[TreeView_GetPrevVisible](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getprevvisible)
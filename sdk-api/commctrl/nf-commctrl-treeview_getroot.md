# TreeView_GetRoot macro

## Syntax

```cpp
HTREEITEM TreeView_GetRoot(
   HWND hwnd
);
```

## Return value

Type: **HTREEITEM**

Returns the handle to the item if successful, or **NULL** otherwise.

## Description

Retrieves the topmost or very first item of the tree-view control. You can use this macro, or you can explicitly send the [TVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getnextitem) message with the TVGN_ROOT flag.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

## See also

[TreeView_GetNextItem](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_getnextitem)
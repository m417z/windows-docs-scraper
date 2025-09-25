# TreeView_GetItemHeight macro

## Syntax

```cpp
int TreeView_GetItemHeight(
   HWND hwnd
);
```

## Return value

Type: **int**

Returns the height of the items, in pixels.

## Description

Retrieves the current height of the tree-view items. You can use this macro or send the [TVM_GETITEMHEIGHT](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitemheight) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to a tree-view control.

## See also

[TreeView_SetItemHeight](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-treeview_setitemheight)
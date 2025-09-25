# TreeView_GetNextSelected macro

## Syntax

```cpp
HTREEITEM TreeView_GetNextSelected(
   HWND      hwnd,
   HTREEITEM *hitem
);
```

## Return value

Type: **HTREEITEM**

Handle to an item, or **NULL** if no item is found with the **TVGN_NEXTSELECTED** relationship.

## Description

Retrieves the tree-view item that bears the **TVGN_NEXTSELECTED** relationship to a specified tree item.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM***

Specifies the tree item by handle.

## Remarks

Used to find the next selected item when there are multiple items selected.

## See also

[TVM_GETNEXTITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getnextitem)
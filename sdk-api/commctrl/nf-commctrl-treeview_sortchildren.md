# TreeView_SortChildren macro

## Syntax

```cpp
BOOL TreeView_SortChildren(
   HWND      hwnd,
   HTREEITEM hitem,
   BOOL      recurse
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns **TRUE** if successful, or **FALSE** otherwise.

## Description

Sorts the child items of the specified parent item in a tree-view control. You can use this macro or send the [TVM_SORTCHILDREN](https://learn.microsoft.com/windows/desktop/Controls/tvm-sortchildren) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to the parent item whose child items are to be sorted.

### `recurse`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Not implemented; see remarks.

## Remarks

This message alphabetizes the tree items using [lstrcmpi](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lstrcmpia) on the item name. You can use the [TVM_SORTCHILDRENCB](https://learn.microsoft.com/windows/desktop/Controls/tvm-sortchildrencb) message to customize the ordering behavior.
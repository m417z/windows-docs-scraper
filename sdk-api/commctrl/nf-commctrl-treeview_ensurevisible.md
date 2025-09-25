# TreeView_EnsureVisible macro

## Syntax

```cpp
BOOL TreeView_EnsureVisible(
   HWND      hwnd,
   HTREEITEM hitem
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Returns nonzero if the system scrolled the items in the tree-view control and no items were expanded. Otherwise, the message returns zero.

## Description

Ensures that a tree-view item is visible, expanding the parent item or scrolling the tree-view control, if necessary. You can use this macro or send the [TVM_ENSUREVISIBLE](https://learn.microsoft.com/windows/desktop/Controls/tvm-ensurevisible) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the tree-view control.

### `hitem`

Type: **HTREEITEM**

Handle to the item.

## Remarks

If the **TreeView_EnsureVisible** macro expands the parent item, the parent window receives the [TVN_ITEMEXPANDING](https://learn.microsoft.com/windows/desktop/Controls/tvn-itemexpanding) and [TVN_ITEMEXPANDED](https://learn.microsoft.com/windows/desktop/Controls/tvn-itemexpanded) notification codes.